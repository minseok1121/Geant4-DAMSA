#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4GeometryManager.hh"
#include "G4TransportationManager.hh"
#include "G4UserLimits.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"

#include "G4ios.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SubtractionSolid.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4SDManager.hh"

#include "G4Cons.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "PMTSD.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"


DetectorConstruction::DetectorConstruction()
{
}


DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4Material* DefinePolyurethane();
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* tar_mat = nist->FindOrBuildMaterial("G4_W");
  G4Material* modulator_mat = DefinePolyurethane();
  G4Material* chamber_mat = nist->FindOrBuildMaterial("G4_Galactic");

 // CsI(Tl) 물질 정의
G4Material* CsI = new G4Material("CsI", 55., 259.809 * g / mole, 4.51 * g / cm3);

// 물질 속성 테이블 생성
G4MaterialPropertiesTable* CsIMPT = new G4MaterialPropertiesTable();

// 광학 광자 에너지 범위 설정
std::vector<G4double> photonEnergy = {1.2398 / 1.0 * eV, 1.2398 / 0.59 * eV, 1.2398 / 0.3 * eV}; 

// 섬광체의 분광 특성 설정 (CsI(Tl) 값으로 조정)
std::vector<G4double> scintillationComponent = {1.0, 1.0, 1.0}; // 임의의 값
CsIMPT->AddProperty("SCINTILLATIONCOMPONENT1", photonEnergy, scintillationComponent);
CsIMPT->AddProperty("SCINTILLATIONCOMPONENT2", photonEnergy, scintillationComponent); // 필요 시 조정

// 굴절률 설정 (CsI(Tl) 값으로 조정)
std::vector<G4double> refractiveIndex = {1.7576, 1.7873, 1.9790}; 
CsIMPT->AddProperty("RINDEX", photonEnergy, refractiveIndex);

// 흡수 길이 설정
std::vector<G4double> absorptionLength = {100. * cm, 10. * cm, 1. * cm}; // 조정 필요
CsIMPT->AddProperty("ABSLENGTH", photonEnergy, absorptionLength);

// 상수 속성 추가
G4double scintYield = 54.0 / keV; // CsI(Tl) 섬광 수율
G4double scintillationTimeConstant = 1000.0 * ns; // CsI(Tl) 빛 분해 시간
CsIMPT->AddConstProperty("SCINTILLATIONYIELD", scintYield);
CsIMPT->AddConstProperty("RESOLUTIONSCALE", 1.0); // 해상도 스케일 조정
CsIMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", scintillationTimeConstant);
CsIMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", 45. * ns);
CsIMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
CsIMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

// CsI에 물질 속성 테이블 설정
CsI->SetMaterialPropertiesTable(CsIMPT);

// Birks 상수 설정
CsI->GetIonisation()->SetBirksConstant(0.126 * mm / MeV);

//**Photocathode surface properties
  auto photocath_mt = new G4MaterialPropertiesTable();
  std::vector<G4double> photocath_EFF     = {1., 1., 1.};
  photocath_mt->AddProperty("EFFICIENCY", photonEnergy, photocath_EFF);
  std::vector<G4double> photocath_REFL = {0., 0., 0.};
  photocath_mt->AddProperty("REFLECTIVITY", photonEnergy, photocath_REFL);
  auto photocath_opsurf = new G4OpticalSurface(
    "photocath_opsurf", glisur, polished, dielectric_dielectric);
  photocath_opsurf->SetMaterialPropertiesTable(photocath_mt);

  G4double detectorSizeX = 5.0*cm;
  G4double detectorSizeY = 5.0*cm;
  G4double targetLength = 10.0*cm;
  G4double                          modulatorWidth = 20.0*cm;
  G4double chamberRadius  = 10.0*cm, chamberSize = 30.0*cm;
  G4double                          ECALSize = 44.0*cm;
  G4double wallwidth = 0.0*cm;
  
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeXY = 200*cm;
  G4double world_sizeZ  = 200*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  auto solidWorld = new G4Box("World",                           // its name
    0.5 * world_sizeXY, 0.5 * world_sizeXY, 0.5 * world_sizeZ);  // its size

  auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
    chamber_mat,                                       // its material
    "World");                                        // its name

  auto physWorld = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),                           // at (0,0,0)
    logicWorld,                                // its logical volume
    "World",                                   // its name
    nullptr,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    checkOverlaps);                            // overlaps checking

 //G4ThreeVector pos0 = G4ThreeVector(0,0,-(targetLength/2+modulatorWidth+chamberSize/2+0.6*cm));
  G4ThreeVector pos0 = G4ThreeVector(0,0,-(targetLength/2+chamberSize/2+0.6*cm));
  auto targetS = new G4Box("target", detectorSizeX / 2, detectorSizeY / 2, targetLength / 2);
  auto logictarget = new G4LogicalVolume(targetS,  // its solid
    tar_mat,                                     // its material
    //G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe")
    "target");                                 // its name
  new G4PVPlacement(nullptr,  // no rotation
    pos0,          // at (0,0,0)
    logictarget,                 // its logical volume
    "target",               // its name
    logicWorld,               // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    checkOverlaps);           // overlaps checking

    G4ThreeVector pos2 = G4ThreeVector(0,0,0);
/*
wallwidth = 1.0*cm;
  auto WallS = new G4Tubs("wall", 0., chamberRadius, wallwidth/2, 0. * deg, 360. * deg);
  auto logicwall = new G4LogicalVolume(WallS,  // its solid
    G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb"),  // its material
    "wall");                                 // its name
  new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(0,0,wallwidth/2-(chamberSize/2+0.6*cm)),          // at (0,0,0)
    logicwall,                 // its logical volume
    "wall",               // its name
    logicWorld,               // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    checkOverlaps);           // overlaps checking

  pos2 = G4ThreeVector(0,0,wallwidth);
   */
// /*
  auto steelchamS = new G4Tubs("steelchamber", 0, chamberRadius+0.6*cm, chamberSize/2+0.6*cm, 0. * deg, 360. * deg);
  auto chamberS = new G4Tubs("chamber", 0, chamberRadius, chamberSize/2, 0. * deg, 360. * deg);
  auto logicchamber = new G4LogicalVolume(chamberS, chamber_mat, "chamber", nullptr, nullptr, nullptr);
  G4SubtractionSolid* solidDecayChamber = new G4SubtractionSolid("DecayChamber", steelchamS, chamberS);
  G4LogicalVolume* logicDecayChamber = new G4LogicalVolume(solidDecayChamber, G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe"), "DecayChamber");
  //G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe")
// */
 /*
// Parameters for the truncated cone (decay chamber)
    G4double rmin1 = 0.0 * cm; // Inner radius at z = -dz/2
    G4double rmax1 = 1.0 * cm; // Outer radius at z = -dz/2
    G4double rmin2 = 0.0 * cm; // Inner radius at z = dz/2
    G4double rmax2 = 10.0 * cm; // Outer radius at z = dz/2
    G4double hz = 15.0 * cm; // Half-length along the z-axis
    G4double startAngle = 0.0 * deg; // Starting angle of the segment
    G4double spanningAngle = 360.0 * deg; // Spanning angle of the segment

    // Create the steel cone (decay chamber)
    G4Cons* steelCone = new G4Cons("steelchamber", rmin1, rmax1 + 0.6 * cm, rmin2, rmax2 + 0.6 * cm, hz + 0.6 * cm, startAngle, spanningAngle);
    G4Cons* solidCone = new G4Cons("chamber", rmin1, rmax1, rmin2, rmax2, hz, startAngle, spanningAngle);
    G4LogicalVolume* logicchamber = new G4LogicalVolume(solidCone, chamber_mat, "chamber");

    // Create the subtraction solid (decay chamber with steel walls)
    G4SubtractionSolid* solidDecayChamber = new G4SubtractionSolid("DecayChamber", steelCone, solidCone);
    G4LogicalVolume* logicDecayChamber = new G4LogicalVolume(solidDecayChamber, G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe"), "DecayChamber");
    // */
/*
    // Parameters for the outer lead cylinder
    G4double leadThickness = 5.0 * cm; // Thickness of the lead shield
    G4Cons* outerLead = new G4Cons("outerLead",
                                   rmin1, rmax1 + 0.61 * cm + leadThickness,
                                   rmin2, rmax2 + 0.61 * cm + leadThickness,
                                   hz + 0.6 * cm, startAngle, spanningAngle);

    // Subtract the steelCone from the outerLead to create the lead shield
    G4SubtractionSolid* solidLeadShield = new G4SubtractionSolid("LeadShield", outerLead, steelCone);
    G4LogicalVolume* logicLeadShield = new G4LogicalVolume(solidLeadShield, G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb"), "LeadShield");
*/
  new G4PVPlacement(nullptr,  // no rotation
    pos2,          // at (x,y,z)
    logicchamber,                // its logical volume
    "chamber",                // its name
    logicWorld,                  // its mother  volume
    false,                    // no boolean operations
    0,                        // copy number
    checkOverlaps);          // checking overlaps
  new G4PVPlacement(nullptr,  // no rotation
    pos2,          // at (x,y,z)
    logicDecayChamber,                // its logical volume
    "steel",                // its name
    logicWorld,                  // its mother  volume
    false,                    // no boolean operations
    0,                        // copy number
    checkOverlaps);          // checking overlaps
  /*
  new G4PVPlacement(nullptr,  // no rotation
    pos2,          // at (x,y,z)
    logicLeadShield,          // Logical volume
    "LeadShield",                // its name
    logicWorld,                  // its mother  volume
    false,                    // no boolean operations
    0,                        // copy number
    checkOverlaps);          // checking overlaps
*/
/*
  G4ThreeVector pos3 = G4ThreeVector(0,0,chamberSize/2+0.6*cm+wallwidth+ECALSize/2);
  //G4ThreeVector pos3 = G4ThreeVector(0,0,chamberSize/2+0.6*cm+ECALSize/2);

  auto ECALS = new G4Tubs("ECAL", 0., chamberRadius, ECALSize/2, 0. * deg, 360. * deg);
  auto logicECAL = new G4LogicalVolume(ECALS,  // its solid
    CsI,                                     // its material
    "ECAL");                                 // its name
  new G4PVPlacement(nullptr,  // no rotation
    pos3,          // at (0,0,0)
    logicECAL,                 // its logical volume
    "ECAL",               // its name
    logicWorld,               // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    checkOverlaps);           // overlaps checking
*/
  //
  //always return the physical World
  //
  // Define the CsI bar
G4double barZ = 10.0 * cm;
G4double barX = 1.0 * cm;
G4double barY = 1.0 * cm;

G4Box* solidCsIBar = new G4Box("CsIBar", barX/2, barY/2, barZ/2);
logicCsIBar = new G4LogicalVolume(solidCsIBar, CsI, "CsIBarLV");

// Define the SiPm
G4double sipmZ = 1.0 * cm;
G4double sipmX = barX;
G4double sipmY = barY;

G4Box* solidSiPm = new G4Box("SiPm", sipmX/2, sipmY/2, sipmZ/2);
logicSiPm = new G4LogicalVolume(solidSiPm, nist->FindOrBuildMaterial("G4_Si"), "SiPmLV");
new G4LogicalSkinSurface("photocath_surf", logicSiPm, photocath_opsurf);

// Parameters for the grid and layers
G4int gridX = 10;
G4int gridY = 10;
G4int numLayers = 4;  // Number of layers in z direction
G4double layerZ = barZ + sipmZ;  // Height of one layer

G4int Index = 0;

// Loop to create the grid and layers
for (G4int k = 0; k < numLayers; k++) {
    for (G4int i = 0; i < gridX; i++) {
        for (G4int j = 0; j < gridY; j++) {
            // Position for CsI bar
            G4double posX = (i - gridX/2 + 0.5) * barX;
            G4double posY = (j - gridY/2 + 0.5) * barY;
            G4double posZ = k * layerZ + 0.5 * barZ + chamberSize/2+0.6*cm+wallwidth;
            G4ThreeVector posCsI = G4ThreeVector(posX, posY, posZ);
            // Position for SiPm (halfway between CsI bars in z direction)
            G4double posSiPmZ = posZ + barZ/2 + sipmZ/2;
            G4ThreeVector posSiPm = G4ThreeVector(posX, posY, posSiPmZ);

            // Place CsI bars
            new G4PVPlacement(nullptr, posCsI, logicCsIBar, "CsIBarPV", logicWorld, false, Index, true);

            // Place SiPm
            new G4PVPlacement(nullptr, posSiPm, logicSiPm, "SiPmPV", logicWorld, false, Index, true);

            fPmtPositions.push_back(posSiPm);
            Index++;
        }
    }
}


  return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
  PMTSD* pmt = fPmt_SD.Get();
  if(!pmt)
  {
    // Created here so it exists as pmts are being placed
    G4cout << "Construction /Det/pmtSD" << G4endl;
    auto pmt_SD = new PMTSD("/Det/pmtSD");
    fPmt_SD.Put(pmt_SD);

    pmt_SD->InitPMTs();
    pmt_SD->SetPmtPositions(GetPmtPositions());
  }
  else
  {
    pmt->InitPMTs();
    pmt->SetPmtPositions(GetPmtPositions());
  }
  G4SDManager::GetSDMpointer()->AddNewDetector(fPmt_SD.Get());
  SetSensitiveDetector(logicSiPm, fPmt_SD.Get());
}

G4Material* DefinePolyurethane() {
    G4NistManager* nistManager = G4NistManager::Instance();
    G4double density = 1.2 * g/cm3;
    G4Element* elC = nistManager->FindOrBuildElement("C");
    G4Element* elH = nistManager->FindOrBuildElement("H");
    G4Element* elO = nistManager->FindOrBuildElement("O");
    G4Material* polyurethane = new G4Material("Polyurethane", density, 3);
    polyurethane->AddElement(elC, 15);
    polyurethane->AddElement(elH, 22);
    polyurethane->AddElement(elO, 1);

    return polyurethane;
}
