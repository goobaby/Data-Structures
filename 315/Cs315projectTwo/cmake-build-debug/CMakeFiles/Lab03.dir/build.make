# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/student/Downloads/reclistsStudentFiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/student/Downloads/reclistsStudentFiles/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab03.dir/flags.make

CMakeFiles/Lab03.dir/main.cpp.o: CMakeFiles/Lab03.dir/flags.make
CMakeFiles/Lab03.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab03.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab03.dir/main.cpp.o -c /Users/student/Downloads/reclistsStudentFiles/main.cpp

CMakeFiles/Lab03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab03.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/student/Downloads/reclistsStudentFiles/main.cpp > CMakeFiles/Lab03.dir/main.cpp.i

CMakeFiles/Lab03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab03.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/student/Downloads/reclistsStudentFiles/main.cpp -o CMakeFiles/Lab03.dir/main.cpp.s

CMakeFiles/Lab03.dir/parser.cpp.o: CMakeFiles/Lab03.dir/flags.make
CMakeFiles/Lab03.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab03.dir/parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab03.dir/parser.cpp.o -c /Users/student/Downloads/reclistsStudentFiles/parser.cpp

CMakeFiles/Lab03.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab03.dir/parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/student/Downloads/reclistsStudentFiles/parser.cpp > CMakeFiles/Lab03.dir/parser.cpp.i

CMakeFiles/Lab03.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab03.dir/parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/student/Downloads/reclistsStudentFiles/parser.cpp -o CMakeFiles/Lab03.dir/parser.cpp.s

CMakeFiles/Lab03.dir/reclists.cpp.o: CMakeFiles/Lab03.dir/flags.make
CMakeFiles/Lab03.dir/reclists.cpp.o: ../reclists.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab03.dir/reclists.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab03.dir/reclists.cpp.o -c /Users/student/Downloads/reclistsStudentFiles/reclists.cpp

CMakeFiles/Lab03.dir/reclists.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab03.dir/reclists.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/student/Downloads/reclistsStudentFiles/reclists.cpp > CMakeFiles/Lab03.dir/reclists.cpp.i

CMakeFiles/Lab03.dir/reclists.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab03.dir/reclists.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/student/Downloads/reclistsStudentFiles/reclists.cpp -o CMakeFiles/Lab03.dir/reclists.cpp.s

CMakeFiles/Lab03.dir/lex.cpp.o: CMakeFiles/Lab03.dir/flags.make
CMakeFiles/Lab03.dir/lex.cpp.o: ../lex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab03.dir/lex.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab03.dir/lex.cpp.o -c /Users/student/Downloads/reclistsStudentFiles/lex.cpp

CMakeFiles/Lab03.dir/lex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab03.dir/lex.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/student/Downloads/reclistsStudentFiles/lex.cpp > CMakeFiles/Lab03.dir/lex.cpp.i

CMakeFiles/Lab03.dir/lex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab03.dir/lex.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/student/Downloads/reclistsStudentFiles/lex.cpp -o CMakeFiles/Lab03.dir/lex.cpp.s

CMakeFiles/Lab03.dir/solutions.cpp.o: CMakeFiles/Lab03.dir/flags.make
CMakeFiles/Lab03.dir/solutions.cpp.o: ../solutions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lab03.dir/solutions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab03.dir/solutions.cpp.o -c /Users/student/Downloads/reclistsStudentFiles/solutions.cpp

CMakeFiles/Lab03.dir/solutions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab03.dir/solutions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/student/Downloads/reclistsStudentFiles/solutions.cpp > CMakeFiles/Lab03.dir/solutions.cpp.i

CMakeFiles/Lab03.dir/solutions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab03.dir/solutions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/student/Downloads/reclistsStudentFiles/solutions.cpp -o CMakeFiles/Lab03.dir/solutions.cpp.s

# Object files for target Lab03
Lab03_OBJECTS = \
"CMakeFiles/Lab03.dir/main.cpp.o" \
"CMakeFiles/Lab03.dir/parser.cpp.o" \
"CMakeFiles/Lab03.dir/reclists.cpp.o" \
"CMakeFiles/Lab03.dir/lex.cpp.o" \
"CMakeFiles/Lab03.dir/solutions.cpp.o"

# External object files for target Lab03
Lab03_EXTERNAL_OBJECTS =

Lab03: CMakeFiles/Lab03.dir/main.cpp.o
Lab03: CMakeFiles/Lab03.dir/parser.cpp.o
Lab03: CMakeFiles/Lab03.dir/reclists.cpp.o
Lab03: CMakeFiles/Lab03.dir/lex.cpp.o
Lab03: CMakeFiles/Lab03.dir/solutions.cpp.o
Lab03: CMakeFiles/Lab03.dir/build.make
Lab03: CMakeFiles/Lab03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Lab03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab03.dir/build: Lab03

.PHONY : CMakeFiles/Lab03.dir/build

CMakeFiles/Lab03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab03.dir/clean

CMakeFiles/Lab03.dir/depend:
	cd /Users/student/Downloads/reclistsStudentFiles/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/student/Downloads/reclistsStudentFiles /Users/student/Downloads/reclistsStudentFiles /Users/student/Downloads/reclistsStudentFiles/cmake-build-debug /Users/student/Downloads/reclistsStudentFiles/cmake-build-debug /Users/student/Downloads/reclistsStudentFiles/cmake-build-debug/CMakeFiles/Lab03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab03.dir/depend

