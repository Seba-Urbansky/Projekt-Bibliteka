CC=gcc
CFLAGS=-I.
DEPS = klienci.h
OBJ = main.o klienci.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

CC=gcc
CFLAGS=-I.
DEPS = ksiazki.h
OBJ = main.o ksiazki.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

	CC=gcc
CFLAGS=-I.
DEPS = wypozyczenia.h
OBJ = main.o wypozyczenia.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)