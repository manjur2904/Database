# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Iinc

# Source and header files
SRCDIR = src
INCDIR = inc
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(SRCFILES:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)

# Output executable
EXEC = database_app

# Default rule
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(SRCDIR)/*.o $(EXEC)

# Phony targets
.PHONY: all clean
