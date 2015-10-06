CC=gcc
CFLAGS=-c -std=c99 -fdiagnostics-color -Wall -Wextra -Wno-missing-braces -Wno-missing-field-initializers
LDFLAGS=-L/usr/lib/x86_64-linux-gnu
INCLUDE=-I/usr/include/x86_64-linux-gnu

SOURCES=src/main.c src/system.c src/opcodes.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bin/em

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCLUDE) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(INCLUDE) $(LDFLAGS) $(CFLAGS) $< -o $@

clean:
	$(RM) bin/em src/*.o
