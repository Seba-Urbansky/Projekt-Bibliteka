CC=gcc
CFLAGS=-I.
DEPS = ksiazki.h wypozyczenia.h klienci.h
OBJ = main.o ksiazki.o wypozyczenia.o klienci.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)