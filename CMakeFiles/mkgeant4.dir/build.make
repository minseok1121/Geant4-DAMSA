# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.20.0-790a8/x86_64-centos7-gcc8-opt/bin/cmake

# The command to remove a file.
RM = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.20.0-790a8/x86_64-centos7-gcc8-opt/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data6/Users/mioh/DMG4/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA

# Include any dependencies generated for this target.
include CMakeFiles/mkgeant4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mkgeant4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mkgeant4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mkgeant4.dir/flags.make

CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o: ActionInitialization.cc
CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o -MF CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o.d -o CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/ActionInitialization.cc

CMakeFiles/mkgeant4.dir/ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/ActionInitialization.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/ActionInitialization.cc > CMakeFiles/mkgeant4.dir/ActionInitialization.cc.i

CMakeFiles/mkgeant4.dir/ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/ActionInitialization.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/ActionInitialization.cc -o CMakeFiles/mkgeant4.dir/ActionInitialization.cc.s

CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o: DarkMatterPhysicsConfigure.cc
CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o -MF CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o.d -o CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DarkMatterPhysicsConfigure.cc

CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DarkMatterPhysicsConfigure.cc > CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.i

CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DarkMatterPhysicsConfigure.cc -o CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.s

CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o: DetectorConstruction.cc
CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o -MF CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o.d -o CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DetectorConstruction.cc

CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DetectorConstruction.cc > CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.i

CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/DetectorConstruction.cc -o CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.s

CMakeFiles/mkgeant4.dir/EventAction.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/EventAction.cc.o: EventAction.cc
CMakeFiles/mkgeant4.dir/EventAction.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mkgeant4.dir/EventAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/EventAction.cc.o -MF CMakeFiles/mkgeant4.dir/EventAction.cc.o.d -o CMakeFiles/mkgeant4.dir/EventAction.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/EventAction.cc

CMakeFiles/mkgeant4.dir/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/EventAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/EventAction.cc > CMakeFiles/mkgeant4.dir/EventAction.cc.i

CMakeFiles/mkgeant4.dir/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/EventAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/EventAction.cc -o CMakeFiles/mkgeant4.dir/EventAction.cc.s

CMakeFiles/mkgeant4.dir/PMTHit.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/PMTHit.cc.o: PMTHit.cc
CMakeFiles/mkgeant4.dir/PMTHit.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mkgeant4.dir/PMTHit.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/PMTHit.cc.o -MF CMakeFiles/mkgeant4.dir/PMTHit.cc.o.d -o CMakeFiles/mkgeant4.dir/PMTHit.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTHit.cc

CMakeFiles/mkgeant4.dir/PMTHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/PMTHit.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTHit.cc > CMakeFiles/mkgeant4.dir/PMTHit.cc.i

CMakeFiles/mkgeant4.dir/PMTHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/PMTHit.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTHit.cc -o CMakeFiles/mkgeant4.dir/PMTHit.cc.s

CMakeFiles/mkgeant4.dir/PMTSD.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/PMTSD.cc.o: PMTSD.cc
CMakeFiles/mkgeant4.dir/PMTSD.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mkgeant4.dir/PMTSD.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/PMTSD.cc.o -MF CMakeFiles/mkgeant4.dir/PMTSD.cc.o.d -o CMakeFiles/mkgeant4.dir/PMTSD.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTSD.cc

CMakeFiles/mkgeant4.dir/PMTSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/PMTSD.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTSD.cc > CMakeFiles/mkgeant4.dir/PMTSD.cc.i

CMakeFiles/mkgeant4.dir/PMTSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/PMTSD.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PMTSD.cc -o CMakeFiles/mkgeant4.dir/PMTSD.cc.s

CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o: PrimaryGeneratorAction.cc
CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o -MF CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o.d -o CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PrimaryGeneratorAction.cc

CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PrimaryGeneratorAction.cc > CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.i

CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/PrimaryGeneratorAction.cc -o CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.s

CMakeFiles/mkgeant4.dir/Run.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/Run.cc.o: Run.cc
CMakeFiles/mkgeant4.dir/Run.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mkgeant4.dir/Run.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/Run.cc.o -MF CMakeFiles/mkgeant4.dir/Run.cc.o.d -o CMakeFiles/mkgeant4.dir/Run.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/Run.cc

CMakeFiles/mkgeant4.dir/Run.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/Run.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/Run.cc > CMakeFiles/mkgeant4.dir/Run.cc.i

CMakeFiles/mkgeant4.dir/Run.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/Run.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/Run.cc -o CMakeFiles/mkgeant4.dir/Run.cc.s

CMakeFiles/mkgeant4.dir/RunAction.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/RunAction.cc.o: RunAction.cc
CMakeFiles/mkgeant4.dir/RunAction.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mkgeant4.dir/RunAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/RunAction.cc.o -MF CMakeFiles/mkgeant4.dir/RunAction.cc.o.d -o CMakeFiles/mkgeant4.dir/RunAction.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/RunAction.cc

CMakeFiles/mkgeant4.dir/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/RunAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/RunAction.cc > CMakeFiles/mkgeant4.dir/RunAction.cc.i

CMakeFiles/mkgeant4.dir/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/RunAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/RunAction.cc -o CMakeFiles/mkgeant4.dir/RunAction.cc.s

CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o: SteppingActionDMG4.cc
CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o -MF CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o.d -o CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/SteppingActionDMG4.cc

CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/SteppingActionDMG4.cc > CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.i

CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/SteppingActionDMG4.cc -o CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.s

CMakeFiles/mkgeant4.dir/mkgeant4.cc.o: CMakeFiles/mkgeant4.dir/flags.make
CMakeFiles/mkgeant4.dir/mkgeant4.cc.o: mkgeant4.cc
CMakeFiles/mkgeant4.dir/mkgeant4.cc.o: CMakeFiles/mkgeant4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/mkgeant4.dir/mkgeant4.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mkgeant4.dir/mkgeant4.cc.o -MF CMakeFiles/mkgeant4.dir/mkgeant4.cc.o.d -o CMakeFiles/mkgeant4.dir/mkgeant4.cc.o -c /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/mkgeant4.cc

CMakeFiles/mkgeant4.dir/mkgeant4.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkgeant4.dir/mkgeant4.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/mkgeant4.cc > CMakeFiles/mkgeant4.dir/mkgeant4.cc.i

CMakeFiles/mkgeant4.dir/mkgeant4.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkgeant4.dir/mkgeant4.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/mkgeant4.cc -o CMakeFiles/mkgeant4.dir/mkgeant4.cc.s

# Object files for target mkgeant4
mkgeant4_OBJECTS = \
"CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o" \
"CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o" \
"CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o" \
"CMakeFiles/mkgeant4.dir/EventAction.cc.o" \
"CMakeFiles/mkgeant4.dir/PMTHit.cc.o" \
"CMakeFiles/mkgeant4.dir/PMTSD.cc.o" \
"CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/mkgeant4.dir/Run.cc.o" \
"CMakeFiles/mkgeant4.dir/RunAction.cc.o" \
"CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o" \
"CMakeFiles/mkgeant4.dir/mkgeant4.cc.o"

# External object files for target mkgeant4
mkgeant4_EXTERNAL_OBJECTS =

mkgeant4: CMakeFiles/mkgeant4.dir/ActionInitialization.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/DarkMatterPhysicsConfigure.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/DetectorConstruction.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/EventAction.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/PMTHit.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/PMTSD.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/PrimaryGeneratorAction.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/Run.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/RunAction.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/SteppingActionDMG4.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/mkgeant4.cc.o
mkgeant4: CMakeFiles/mkgeant4.dir/build.make
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4Tree.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4FR.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4GMocren.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4visHepRep.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4RayTracer.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4VRML.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4ToolsSG.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4vis_management.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4modeling.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4interfaces.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4persistency.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4error_propagation.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4readout.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4physicslists.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4run.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4event.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4tracking.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4parmodels.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4processes.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4digits_hits.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4track.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4particles.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4geometry.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4materials.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4graphics_reps.so
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc8-opt/lib/libgsl.so
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc8-opt/lib/libgslcblas.so
mkgeant4: /usr/lib64/libXm.so
mkgeant4: /usr/lib64/libXmu.so
mkgeant4: /usr/lib64/libXext.so
mkgeant4: /usr/lib64/libXt.so
mkgeant4: /usr/lib64/libICE.so
mkgeant4: /usr/lib64/libSM.so
mkgeant4: /usr/lib64/libX11.so
mkgeant4: /usr/lib64/libGL.so
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libQt5OpenGL.so.5.15.2
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libQt5PrintSupport.so.5.15.2
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libQt5Widgets.so.5.15.2
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libQt5Gui.so.5.15.2
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libQt5Core.so.5.15.2
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libxerces-c.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4analysis.so
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libhdf5.so
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib64/libexpat.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4zlib.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4intercoms.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4global.so
mkgeant4: /cvmfs/geant4.cern.ch/geant4/11.1/x86_64-centos7-gcc8-optdeb-MT/lib64/libG4ptl.so.2.3.3
mkgeant4: /cvmfs/sft.cern.ch/lcg/views/LCG_geant4ext20221205/x86_64-centos7-gcc8-opt/lib/libCLHEP-2.4.6.2.so
mkgeant4: CMakeFiles/mkgeant4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable mkgeant4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mkgeant4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mkgeant4.dir/build: mkgeant4
.PHONY : CMakeFiles/mkgeant4.dir/build

CMakeFiles/mkgeant4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mkgeant4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mkgeant4.dir/clean

CMakeFiles/mkgeant4.dir/depend:
	cd /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data6/Users/mioh/DMG4/examples /data6/Users/mioh/DMG4/examples /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA /data6/Users/mioh/DMG4/examples/GitBackup_DAMSA/CMakeFiles/mkgeant4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mkgeant4.dir/depend

