# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RomanCalculatorStarter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RomanCalculatorStarter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RomanCalculatorStarter.dir/flags.make

CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o: CMakeFiles/RomanCalculatorStarter.dir/flags.make
CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o -c /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/main.cpp

CMakeFiles/RomanCalculatorStarter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RomanCalculatorStarter.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/main.cpp > CMakeFiles/RomanCalculatorStarter.dir/main.cpp.i

CMakeFiles/RomanCalculatorStarter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RomanCalculatorStarter.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/main.cpp -o CMakeFiles/RomanCalculatorStarter.dir/main.cpp.s

CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o: CMakeFiles/RomanCalculatorStarter.dir/flags.make
CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o: ../Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o -c /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Token.cpp

CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Token.cpp > CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.i

CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Token.cpp -o CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.s

CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o: CMakeFiles/RomanCalculatorStarter.dir/flags.make
CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o: ../InfixToPostfix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o -c /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/InfixToPostfix.cpp

CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/InfixToPostfix.cpp > CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.i

CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/InfixToPostfix.cpp -o CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.s

CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o: CMakeFiles/RomanCalculatorStarter.dir/flags.make
CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o: ../TokenIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o -c /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/TokenIterator.cpp

CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/TokenIterator.cpp > CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.i

CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/TokenIterator.cpp -o CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.s

CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o: CMakeFiles/RomanCalculatorStarter.dir/flags.make
CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o: ../Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o -c /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Tokenizer.cpp

CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Tokenizer.cpp > CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.i

CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/Tokenizer.cpp -o CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.s

# Object files for target RomanCalculatorStarter
RomanCalculatorStarter_OBJECTS = \
"CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o" \
"CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o" \
"CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o" \
"CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o" \
"CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o"

# External object files for target RomanCalculatorStarter
RomanCalculatorStarter_EXTERNAL_OBJECTS =

RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/main.cpp.o
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/Token.cpp.o
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/InfixToPostfix.cpp.o
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/TokenIterator.cpp.o
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/Tokenizer.cpp.o
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/build.make
RomanCalculatorStarter: CMakeFiles/RomanCalculatorStarter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable RomanCalculatorStarter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RomanCalculatorStarter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RomanCalculatorStarter.dir/build: RomanCalculatorStarter

.PHONY : CMakeFiles/RomanCalculatorStarter.dir/build

CMakeFiles/RomanCalculatorStarter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RomanCalculatorStarter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RomanCalculatorStarter.dir/clean

CMakeFiles/RomanCalculatorStarter.dir/depend:
	cd /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug /Users/kooshesh/Courses/2021fall/cs315/projects/romanCalculator/RomanCalculatorStarter/cmake-build-debug/CMakeFiles/RomanCalculatorStarter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RomanCalculatorStarter.dir/depend

