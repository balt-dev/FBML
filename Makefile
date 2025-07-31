SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
HEADER = $(wildcard src/*.h)
OUT = dist/zlib1.dll
CC = winegcc -bi686-w64-mingw32

CFLAGS = -I./lib/include
LDFLAGS = -L./lib
LIBS = -llua52

obj dist:
	mkdir -p $@

obj/%.o: src/%.c $(HEADER) | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ) | dist
	$(CC) -shared $(OBJ) $(LDFLAGS) $(LIBS) -o $@

compile: $(OBJ)

build: $(OUT)

run: compile build
	@dist/out

clean:
	rm -rf obj/* dist/*

.PHONY: compile build run clean
