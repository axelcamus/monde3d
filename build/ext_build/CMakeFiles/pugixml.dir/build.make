# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shinhra/cours/monde3d/monde3d/m3d_td1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shinhra/cours/monde3d/monde3d/build

# Include any dependencies generated for this target.
include ext_build/CMakeFiles/pugixml.dir/depend.make

# Include the progress variables for this target.
include ext_build/CMakeFiles/pugixml.dir/progress.make

# Include the compile flags for this target's objects.
include ext_build/CMakeFiles/pugixml.dir/flags.make

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o: ext_build/CMakeFiles/pugixml.dir/flags.make
ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o: /home/shinhra/cours/monde3d/monde3d/m3d_td1/ext/pugixml/src/pugixml.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/shinhra/cours/monde3d/monde3d/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o"
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o -c /home/shinhra/cours/monde3d/monde3d/m3d_td1/ext/pugixml/src/pugixml.cpp

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.i"
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/shinhra/cours/monde3d/monde3d/m3d_td1/ext/pugixml/src/pugixml.cpp > CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.i

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.s"
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/shinhra/cours/monde3d/monde3d/m3d_td1/ext/pugixml/src/pugixml.cpp -o CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.s

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.requires:
.PHONY : ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.requires

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.provides: ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.requires
	$(MAKE) -f ext_build/CMakeFiles/pugixml.dir/build.make ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.provides.build
.PHONY : ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.provides

ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.provides.build: ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o

# Object files for target pugixml
pugixml_OBJECTS = \
"CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o"

# External object files for target pugixml
pugixml_EXTERNAL_OBJECTS =

ext_build/libpugixml.a: ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o
ext_build/libpugixml.a: ext_build/CMakeFiles/pugixml.dir/build.make
ext_build/libpugixml.a: ext_build/CMakeFiles/pugixml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libpugixml.a"
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean_target.cmake
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pugixml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext_build/CMakeFiles/pugixml.dir/build: ext_build/libpugixml.a
.PHONY : ext_build/CMakeFiles/pugixml.dir/build

ext_build/CMakeFiles/pugixml.dir/requires: ext_build/CMakeFiles/pugixml.dir/pugixml/src/pugixml.cpp.o.requires
.PHONY : ext_build/CMakeFiles/pugixml.dir/requires

ext_build/CMakeFiles/pugixml.dir/clean:
	cd /home/shinhra/cours/monde3d/monde3d/build/ext_build && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean.cmake
.PHONY : ext_build/CMakeFiles/pugixml.dir/clean

ext_build/CMakeFiles/pugixml.dir/depend:
	cd /home/shinhra/cours/monde3d/monde3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shinhra/cours/monde3d/monde3d/m3d_td1 /home/shinhra/cours/monde3d/monde3d/m3d_td1/ext /home/shinhra/cours/monde3d/monde3d/build /home/shinhra/cours/monde3d/monde3d/build/ext_build /home/shinhra/cours/monde3d/monde3d/build/ext_build/CMakeFiles/pugixml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext_build/CMakeFiles/pugixml.dir/depend

