CC=gcc
CFLAGS=-I.
DEPS = ksiazki.h wypozyczenia.h klienci.h common.h menu.h
OBJ = main.o ksiazki.o wypozyczenia.o klienci.o common.o menu.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)