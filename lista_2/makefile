# Makefile for compiling a C++ file with g++-20

# Compiler
CXX = g++-11

# Flags for the compiler
CXXFLAGS = -std=c++20 -Wall -Wextra

# Default target (you can specify your own default target here)
all: 

# Rule to compile the program
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $<

# Clean rule to remove the compiled binaries
clean:
	rm -f *.out

# Ensure that the 'clean' target doesn't get confused with a file named 'clean'
.PHONY: all clean
