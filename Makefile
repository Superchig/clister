CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
# Without file extensions.
SOURCE_NAMES=clister stringarray
OBJ=$(addsuffix .o,$(addprefix obj/,$(SOURCE_NAMES)))
SRC=$(addsuffix .c,$(addprefix src/,$(SOURCE_NAMES)))

all: clister

run: clister
	./clister

clister: $(OBJ)
	$(CC) $(OBJ) -o clister

test: obj/stringarray.o obj/test.o
	$(CC) $(CFLAGS) obj/stringarray.o obj/test.o -o test

obj/%.o : src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm OBJ clister
