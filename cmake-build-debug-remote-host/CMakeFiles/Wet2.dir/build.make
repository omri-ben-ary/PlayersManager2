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
CMAKE_COMMAND = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/omri/DataStructures/Final/Wet2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host

# Include any dependencies generated for this target.
include CMakeFiles/Wet2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wet2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wet2.dir/flags.make

CMakeFiles/Wet2.dir/main.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Wet2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/main.cpp.o -c /home/omri/DataStructures/Final/Wet2/main.cpp

CMakeFiles/Wet2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/main.cpp > CMakeFiles/Wet2.dir/main.cpp.i

CMakeFiles/Wet2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/main.cpp -o CMakeFiles/Wet2.dir/main.cpp.s

CMakeFiles/Wet2.dir/UnionFindNode.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/UnionFindNode.cpp.o: ../UnionFindNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Wet2.dir/UnionFindNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/UnionFindNode.cpp.o -c /home/omri/DataStructures/Final/Wet2/UnionFindNode.cpp

CMakeFiles/Wet2.dir/UnionFindNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/UnionFindNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/UnionFindNode.cpp > CMakeFiles/Wet2.dir/UnionFindNode.cpp.i

CMakeFiles/Wet2.dir/UnionFindNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/UnionFindNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/UnionFindNode.cpp -o CMakeFiles/Wet2.dir/UnionFindNode.cpp.s

CMakeFiles/Wet2.dir/UnionFind.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/UnionFind.cpp.o: ../UnionFind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Wet2.dir/UnionFind.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/UnionFind.cpp.o -c /home/omri/DataStructures/Final/Wet2/UnionFind.cpp

CMakeFiles/Wet2.dir/UnionFind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/UnionFind.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/UnionFind.cpp > CMakeFiles/Wet2.dir/UnionFind.cpp.i

CMakeFiles/Wet2.dir/UnionFind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/UnionFind.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/UnionFind.cpp -o CMakeFiles/Wet2.dir/UnionFind.cpp.s

CMakeFiles/Wet2.dir/AVLTree.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/AVLTree.cpp.o: ../AVLTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Wet2.dir/AVLTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/AVLTree.cpp.o -c /home/omri/DataStructures/Final/Wet2/AVLTree.cpp

CMakeFiles/Wet2.dir/AVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/AVLTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/AVLTree.cpp > CMakeFiles/Wet2.dir/AVLTree.cpp.i

CMakeFiles/Wet2.dir/AVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/AVLTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/AVLTree.cpp -o CMakeFiles/Wet2.dir/AVLTree.cpp.s

CMakeFiles/Wet2.dir/EmptyNode.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/EmptyNode.cpp.o: ../EmptyNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Wet2.dir/EmptyNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/EmptyNode.cpp.o -c /home/omri/DataStructures/Final/Wet2/EmptyNode.cpp

CMakeFiles/Wet2.dir/EmptyNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/EmptyNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/EmptyNode.cpp > CMakeFiles/Wet2.dir/EmptyNode.cpp.i

CMakeFiles/Wet2.dir/EmptyNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/EmptyNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/EmptyNode.cpp -o CMakeFiles/Wet2.dir/EmptyNode.cpp.s

CMakeFiles/Wet2.dir/LevelNode.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/LevelNode.cpp.o: ../LevelNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Wet2.dir/LevelNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/LevelNode.cpp.o -c /home/omri/DataStructures/Final/Wet2/LevelNode.cpp

CMakeFiles/Wet2.dir/LevelNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/LevelNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/LevelNode.cpp > CMakeFiles/Wet2.dir/LevelNode.cpp.i

CMakeFiles/Wet2.dir/LevelNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/LevelNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/LevelNode.cpp -o CMakeFiles/Wet2.dir/LevelNode.cpp.s

CMakeFiles/Wet2.dir/Node.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/Node.cpp.o: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Wet2.dir/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/Node.cpp.o -c /home/omri/DataStructures/Final/Wet2/Node.cpp

CMakeFiles/Wet2.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/Node.cpp > CMakeFiles/Wet2.dir/Node.cpp.i

CMakeFiles/Wet2.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/Node.cpp -o CMakeFiles/Wet2.dir/Node.cpp.s

CMakeFiles/Wet2.dir/Player.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Wet2.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/Player.cpp.o -c /home/omri/DataStructures/Final/Wet2/Player.cpp

CMakeFiles/Wet2.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/Player.cpp > CMakeFiles/Wet2.dir/Player.cpp.i

CMakeFiles/Wet2.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/Player.cpp -o CMakeFiles/Wet2.dir/Player.cpp.s

CMakeFiles/Wet2.dir/RankTree.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/RankTree.cpp.o: ../RankTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Wet2.dir/RankTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/RankTree.cpp.o -c /home/omri/DataStructures/Final/Wet2/RankTree.cpp

CMakeFiles/Wet2.dir/RankTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/RankTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/RankTree.cpp > CMakeFiles/Wet2.dir/RankTree.cpp.i

CMakeFiles/Wet2.dir/RankTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/RankTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/RankTree.cpp -o CMakeFiles/Wet2.dir/RankTree.cpp.s

CMakeFiles/Wet2.dir/TreeExceptions.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/TreeExceptions.cpp.o: ../TreeExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Wet2.dir/TreeExceptions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/TreeExceptions.cpp.o -c /home/omri/DataStructures/Final/Wet2/TreeExceptions.cpp

CMakeFiles/Wet2.dir/TreeExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/TreeExceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/TreeExceptions.cpp > CMakeFiles/Wet2.dir/TreeExceptions.cpp.i

CMakeFiles/Wet2.dir/TreeExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/TreeExceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/TreeExceptions.cpp -o CMakeFiles/Wet2.dir/TreeExceptions.cpp.s

CMakeFiles/Wet2.dir/PlayersManager.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/PlayersManager.cpp.o: ../PlayersManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Wet2.dir/PlayersManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/PlayersManager.cpp.o -c /home/omri/DataStructures/Final/Wet2/PlayersManager.cpp

CMakeFiles/Wet2.dir/PlayersManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/PlayersManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/PlayersManager.cpp > CMakeFiles/Wet2.dir/PlayersManager.cpp.i

CMakeFiles/Wet2.dir/PlayersManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/PlayersManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/PlayersManager.cpp -o CMakeFiles/Wet2.dir/PlayersManager.cpp.s

CMakeFiles/Wet2.dir/HashTable.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/HashTable.cpp.o: ../HashTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Wet2.dir/HashTable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/HashTable.cpp.o -c /home/omri/DataStructures/Final/Wet2/HashTable.cpp

CMakeFiles/Wet2.dir/HashTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/HashTable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/HashTable.cpp > CMakeFiles/Wet2.dir/HashTable.cpp.i

CMakeFiles/Wet2.dir/HashTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/HashTable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/HashTable.cpp -o CMakeFiles/Wet2.dir/HashTable.cpp.s

CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o: ../HashTableExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o -c /home/omri/DataStructures/Final/Wet2/HashTableExceptions.cpp

CMakeFiles/Wet2.dir/HashTableExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/HashTableExceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/HashTableExceptions.cpp > CMakeFiles/Wet2.dir/HashTableExceptions.cpp.i

CMakeFiles/Wet2.dir/HashTableExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/HashTableExceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/HashTableExceptions.cpp -o CMakeFiles/Wet2.dir/HashTableExceptions.cpp.s

CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o: ../PlayersManagerExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o -c /home/omri/DataStructures/Final/Wet2/PlayersManagerExceptions.cpp

CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/PlayersManagerExceptions.cpp > CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.i

CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/PlayersManagerExceptions.cpp -o CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.s

CMakeFiles/Wet2.dir/library2.cpp.o: CMakeFiles/Wet2.dir/flags.make
CMakeFiles/Wet2.dir/library2.cpp.o: ../library2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Wet2.dir/library2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet2.dir/library2.cpp.o -c /home/omri/DataStructures/Final/Wet2/library2.cpp

CMakeFiles/Wet2.dir/library2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet2.dir/library2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omri/DataStructures/Final/Wet2/library2.cpp > CMakeFiles/Wet2.dir/library2.cpp.i

CMakeFiles/Wet2.dir/library2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet2.dir/library2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omri/DataStructures/Final/Wet2/library2.cpp -o CMakeFiles/Wet2.dir/library2.cpp.s

# Object files for target Wet2
Wet2_OBJECTS = \
"CMakeFiles/Wet2.dir/main.cpp.o" \
"CMakeFiles/Wet2.dir/UnionFindNode.cpp.o" \
"CMakeFiles/Wet2.dir/UnionFind.cpp.o" \
"CMakeFiles/Wet2.dir/AVLTree.cpp.o" \
"CMakeFiles/Wet2.dir/EmptyNode.cpp.o" \
"CMakeFiles/Wet2.dir/LevelNode.cpp.o" \
"CMakeFiles/Wet2.dir/Node.cpp.o" \
"CMakeFiles/Wet2.dir/Player.cpp.o" \
"CMakeFiles/Wet2.dir/RankTree.cpp.o" \
"CMakeFiles/Wet2.dir/TreeExceptions.cpp.o" \
"CMakeFiles/Wet2.dir/PlayersManager.cpp.o" \
"CMakeFiles/Wet2.dir/HashTable.cpp.o" \
"CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o" \
"CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o" \
"CMakeFiles/Wet2.dir/library2.cpp.o"

# External object files for target Wet2
Wet2_EXTERNAL_OBJECTS =

Wet2: CMakeFiles/Wet2.dir/main.cpp.o
Wet2: CMakeFiles/Wet2.dir/UnionFindNode.cpp.o
Wet2: CMakeFiles/Wet2.dir/UnionFind.cpp.o
Wet2: CMakeFiles/Wet2.dir/AVLTree.cpp.o
Wet2: CMakeFiles/Wet2.dir/EmptyNode.cpp.o
Wet2: CMakeFiles/Wet2.dir/LevelNode.cpp.o
Wet2: CMakeFiles/Wet2.dir/Node.cpp.o
Wet2: CMakeFiles/Wet2.dir/Player.cpp.o
Wet2: CMakeFiles/Wet2.dir/RankTree.cpp.o
Wet2: CMakeFiles/Wet2.dir/TreeExceptions.cpp.o
Wet2: CMakeFiles/Wet2.dir/PlayersManager.cpp.o
Wet2: CMakeFiles/Wet2.dir/HashTable.cpp.o
Wet2: CMakeFiles/Wet2.dir/HashTableExceptions.cpp.o
Wet2: CMakeFiles/Wet2.dir/PlayersManagerExceptions.cpp.o
Wet2: CMakeFiles/Wet2.dir/library2.cpp.o
Wet2: CMakeFiles/Wet2.dir/build.make
Wet2: CMakeFiles/Wet2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Wet2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wet2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wet2.dir/build: Wet2

.PHONY : CMakeFiles/Wet2.dir/build

CMakeFiles/Wet2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wet2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wet2.dir/clean

CMakeFiles/Wet2.dir/depend:
	cd /home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/omri/DataStructures/Final/Wet2 /home/omri/DataStructures/Final/Wet2 /home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host /home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host /home/omri/DataStructures/Final/Wet2/cmake-build-debug-remote-host/CMakeFiles/Wet2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wet2.dir/depend

