TOPDIR := $(HOME)/Documents/Programming/Battleship/
SRCDIR := $(TOPDIR)src/
INCDIR := $(TOPDIR)include/
OBJDIR := $(TOPDIR)obj/

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


CXXFLAGS+= --std=c++11
CXX := g++

EXE=battlerun


all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(exe)
