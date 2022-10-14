# Builds and tests tictactoe game program.
#
# Author (starting point): Russ Tuck
# Authors (everything else):

# Game-of-Life uses C++ 2011.  Compile for debugging (-g) with warnings.
# Google Test needs -pthread.
CXXFLAGS=-std=c++11 -g -Wall -Wextra -pthread

# Instructor's note: First target is the default; use it to build everything.
all:		Game-of-Life \


# Main program for users to use.
Game-of-Life :		Game-of-Life.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

