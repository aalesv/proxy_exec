CXX = $(BIN)g++
CFLAGS = -Wl,-static -static-libgcc -static-libstdc++ -lstdc++

SRC = proxy_exec.cpp
OBJ = $(SRC:.c=.o)

EXEC = proxy_exec.exe

.PHONY: all

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CFLAGS) $^ -o $@
