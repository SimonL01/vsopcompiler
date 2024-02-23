

# compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Linking libraries and flags

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Executable name
TARGET = $(BINDIR)/vsopc

# Archive
ARCHIVE_NAME = vsopcompiler.tar.xz
FILES_TO_ARCHIVE = vsopcompiler

# Sources and objects for each package
# Each package's objects are compiled into a separate .o file
MAIN_SRCS = $(wildcard $(SRCDIR)/*.cpp)
MAIN_OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(MAIN_SRCS))

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
	rm -rf $(OBJDIR)/* $(TARGET) vsopc

run:
	$(TARGET) 

vsopc:
	mkdir -p bin
	make
	cp $(TARGET)  .

all:
	make vsopc
	./bin/vsopc -l exemple.vsop

install-tools:

archive:
	tar -cJf $(ARCHIVE_NAME) $(FILES_TO_ARCHIVE)
