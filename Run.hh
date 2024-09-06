#ifndef RUN_HH
#define RUN_HH

#include "G4Run.hh"
#include <vector>
#include <map>
#include <tuple>

class Run : public G4Run
{
public:
    Run();
    virtual ~Run();

    virtual void RecordEvent(const G4Event* evt) override;
    virtual void Merge(const G4Run* aRun) override;

    std::vector<std::vector<double>>& GetEventDataH1() { return eventDataH1; }
    const std::vector<std::vector<double>>& GetEventDataH1() const { return eventDataH1; }

    std::vector<std::vector<std::vector<double>>>& GetEventDataH2() { return eventDataH2; }
    const std::vector<std::vector<std::vector<double>>>& GetEventDataH2() const { return eventDataH2; }

    void StoreKineticEnergy(int particleIndex, int binX, int binY, G4double kineticEnergy);

    std::vector<std::vector<std::vector<double>>> tempKineticEnergyData = std::vector<std::vector<std::vector<double>>>(4, std::vector<std::vector<double>>(10, std::vector<double>(10, 0.0)));

private:
    static const size_t numH1Histograms = 400; // Number of histograms
    static const size_t timeBins = 10000; // Number of time bins
    static const size_t numH2Histograms = 8;
    static const size_t xBins = 10;
    static const size_t yBins = 10;

    std::vector<std::vector<double>> eventDataH1 = std::vector<std::vector<double>>(numH1Histograms, std::vector<double>(timeBins, 0.0));
    std::vector<std::vector<std::vector<double>>> eventDataH2 = std::vector<std::vector<std::vector<double>>>(numH2Histograms, std::vector<std::vector<double>>(xBins, std::vector<double>(yBins, 0.0)));
    G4int fPMTCollID = -1;
};

#endif // RUN_HH
