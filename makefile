### Cleaning
# make clean
### Compiling
# make vsopc 
### Running
# ./bin/vsopc -l exemple.vsop

# compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Linking libraries and flags

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Executable name : specifies the path and the name of the final executable file
TARGET = $(BINDIR)/vsopc

# Sources and objects for each package
# Each package's objects are compiled into a separate .o file
MAIN_SRCS = $(wildcard $(SRCDIR)/*.cpp) # wildcard function returns a list of all files in the directory that match the pattern (here find all .cpp files in the src directory)
MAIN_OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(MAIN_SRCS)) # patsubst function replaces the first pattern with the second pattern in a list of words
# So here "patsubst" replaces the pattern $(SRCDIR)/%.cpp with $(OBJDIR)/%.o in the list of words $(MAIN_SRCS)

LEXICALANALYZER_SRCS = $(wildcard $(SRCDIR)/LexicalAnalyzer/*.cpp)
LEXICALANALYZER_OBJS = $(patsubst $(SRCDIR)/LexicalAnalyzer/%.cpp,$(OBJDIR)/LexicalAnalyzer/%.o,$(LEXICALANALYZER_SRCS))

TOKEN_SRCS = $(wildcard $(SRCDIR)/Token/*.cpp)
TOKEN_OBJS = $(patsubst $(SRCDIR)/Token/%.cpp,$(OBJDIR)/Token/%.o,$(TOKEN_SRCS))

# Dependencies for each object file
MAIN_DEPS = $(wildcard $(SRCDIR)/*.h)
LEXICALANALYZER_DEPS = $(wildcard $(SRCDIR)/LexicalAnalyzer/*.h)
TOKEN_DEPS = $(wildcard $(SRCDIR)/Token/*.h)

# Build the executable
$(TARGET): $(MAIN_OBJS) $(LEXICALANALYZER_OBJS) $(TOKEN_OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build main objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(MAIN_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build LexicalAnalyzer objects
$(OBJDIR)/LexicalAnalyzer/%.o: $(SRCDIR)/LexicalAnalyzer/%.cpp $(LEXICALANALYZER_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build Token objects
$(OBJDIR)/Token/%.o: $(SRCDIR)/Token/%.cpp $(TOKEN_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and executable files
clean:
	rm -rf $(OBJDIR)/* $(TARGET)

run:
	$(TARGET) 

vsopc:
	make

install-tools: