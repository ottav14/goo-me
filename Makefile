# Compiler
CC = g++
LIBS = -lm -lSDL2 -lSDL2_ttf 

# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin

# Source files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Frame.cpp $(SRCDIR)/Button.cpp $(SRCDIR)/TextRenderer.cpp $(SRCDIR)/Textbox.cpp
# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
# Header files
HEADERS = $(INCDIR)/Frame.h $(INCDIR)/Button.h $(INCDIR)/TextRenderer.h $(INCDIR)/Textbox.h

# Executable
EXECUTABLE = out

# Target: all (default target)
all: $(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINDIR)/$(EXECUTABLE) $(LIBS)

# Compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) -I$(INCDIR) -c $< -o $@

# Target: clean (remove object files and executable)
clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/$(EXECUTABLE)

# Target to build and run the application
run: $(EXECUTABLE)
	./$(BINDIR)/$(EXECUTABLE)
