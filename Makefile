PRODUCT  := battlerun
BIN 		 := bin
INC      := include
SRC      := src
OBJ      := obj

CXX      := g++
CXXFLAGS := -std=c++11

LINKER   := g++

INCLUDE  := -I$(INC) -I.

EXT      := cpp

MAIN     := $(SRC)/main.$(EXT)
SRCS     := $(wildcard $(SRC)/*.$(EXT))
SRCS     := $(filter-out $(MAIN), $(SRCS))

OBJS     := $(patsubst $(SRC)/%.$(EXT), $(OBJ)/%.o, $(SRCS))
MAIN_OBJ := $(patsubst $(SRC)/%.$(EXT), $(OBJ)/%.o, $(MAIN))

# EXECUTABLES

run: build
	./$(BIN)/$(PRODUCT)
.PHONY: run

# BUILDING

build: $(BIN)/$(PRODUCT)
.PHONY: build

$(BIN)/$(PRODUCT): $(OBJS) $(MAIN_OBJ)
	$(LINKER) $(OBJS) $(MAIN_OBJ) -o $@

$(MAIN_OBJ): $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.$(EXT)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# MISC

DIRS     := $(BIN) $(OBJ)

clean:
	rm -rf $(DIRS)
	mkdir -p $(DIRS)
.PHONY: clean
