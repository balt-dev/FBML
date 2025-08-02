SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
HEADER = $(wildcard src/*.h)
OUT = dist/zlib1.dll
CC = winegcc -bi686-w64-mingw32

CFLAGS = -I./lib/include
LDFLAGS = -L./lib
LIBS = -lshlwapi

obj dist:
	mkdir -p $@

obj/%.o: src/%.c $(HEADER) | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ) | dist
	$(CC) -shared $(OBJ) $(LDFLAGS) $(LIBS) -o $@

compile: $(OBJ)

build: $(OUT)

run: compile build
	cp /home/baltdev/Documents/FBML/dist/zlib1.dll /home/baltdev/Games/Steam/common/Fractal\ Block\ World/Bin/WindowsMinGW/zlib1.dll
	steam steam://rungameid/1540570
	tail -f /home/baltdev/Games/Steam/common/Fractal\ Block\ World/stdout.txt

clean:
	rm -rf obj/* dist/*

all: clean compile build run
