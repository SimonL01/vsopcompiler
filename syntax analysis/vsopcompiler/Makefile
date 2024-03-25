# compiler and flags
CXX = g++
BISON = bison
CXXFLAGS = -std=c++17 -Wall -Wextra

# Linking libraries and flags

BISONFLAGS = -d

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

# Bison
PARSER_SRCS = $(wildcard $(SRCDIR)/SyntaxAnalyzer/Parser.y)

LEXICALANALYZER_SRCS = $(wildcard $(SRCDIR)/LexicalAnalyzer/*.cpp)
LEXICALANALYZER_OBJS = $(patsubst $(SRCDIR)/LexicalAnalyzer/%.cpp,$(OBJDIR)/LexicalAnalyzer/%.o,$(LEXICALANALYZER_SRCS))

SYNTAXANALYZER_SRCS = $(wildcard $(SRCDIR)/SyntaxAnalyzer/*.cpp)
SYNTAXANALYZER_OBJS = $(patsubst $(SRCDIR)/SyntaxAnalyzer/%.cpp,$(OBJDIR)/SyntaxAnalyzer/%.o,$(SYNTAXANALYZER_SRCS))

TOKEN_SRCS = $(wildcard $(SRCDIR)/Token/*.cpp)
TOKEN_OBJS = $(patsubst $(SRCDIR)/Token/%.cpp,$(OBJDIR)/Token/%.o,$(TOKEN_SRCS))

# Dependencies for each object file
MAIN_DEPS = $(wildcard $(SRCDIR)/*.h)
LEXICALANALYZER_DEPS = $(wildcard $(SRCDIR)/LexicalAnalyzer/*.h)
SYNTAXANALYZER_DEPS = $(wildcard $(SRCDIR)/SyntaxAnalyzer/*.h)
TOKEN_DEPS = $(wildcard $(SRCDIR)/Token/*.h)

# Build the executable
$(TARGET): $(MAIN_OBJS) $(LEXICALANALYZER_OBJS) $(TOKEN_OBJS) $(SYNTAXANALYZER_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build Parser files
$(SRCDIR)/SyntaxAnalyzer/Parser.cpp:  $(PARSER_SRCS)
	$(BISON) $(BISONFLAGS) $^ -o $@ -Wcounterexamples

# Build main objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(MAIN_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build LexicalAnalyzer objects
$(OBJDIR)/LexicalAnalyzer/%.o: $(SRCDIR)/LexicalAnalyzer/%.cpp $(LEXICALANALYZER_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build SyntaxAnalyzer objects
$(OBJDIR)/SyntaxAnalyzer/%.o: $(SRCDIR)/SyntaxAnalyzer/%.cpp $(SYNTAXANALYZER_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build Token objects
$(OBJDIR)/Token/%.o: $(SRCDIR)/Token/%.cpp $(TOKEN_DEPS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and executable files
clean:
	rm -rf $(OBJDIR)/* $(TARGET) vsopc
	rm -rf $(SRCDIR)/SyntaxAnalyzer/Parser.cpp $(SRCDIR)/SyntaxAnalyzer/Parser.hpp $(SRCDIR)/SyntaxAnalyzer/location.hh

run:
	$(TARGET) 

#
# bison $(BISONFLAGS) $(PARSER_SRCS) -o $(wildcard $(SRCDIR)/SyntaxAnalyzer)/Parser.cpp
vsopc:
	mkdir -p bin
	make $(SRCDIR)/SyntaxAnalyzer/Parser.cpp
	make
	cp $(TARGET)  .

parse:
	clear
	make clean
	make vsopc
	./bin/vsopc -p exemple.vsop

do:
	./bin/vsopc -p exemple.vsop

install-tools:

archive:
	tar -cJf $(ARCHIVE_NAME) $(FILES_TO_ARCHIVE)
