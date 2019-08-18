CC=gcc
CFLAGS=-Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`
OBJ=shutdown-dialog.o resources.o logout.o
BIN=shutdown-dialog

all: shutdown-dialog.o

resources.c: shutdown-dialog.gresource.xml
	glib-compile-resources $+ --generate-source --sourcedir=resources --target=$@

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

all: $(BIN)

clean:
	rm -f resources.c *.o $(BIN)

.PHONY: clean
