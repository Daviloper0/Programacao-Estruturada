CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
OBJETOS = main.o texto.o utils.o ocorrencias.o documento.o indice.o

.PHONY: all clean

all: ep2

ep2: $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $(OBJETOS)

main.o: main.c documento.h indice.h texto.h ocorrencias.h
texto.o: texto.c texto.h utils.h
utils.o: utils.c utils.h
ocorrencias.o: ocorrencias.c ocorrencias.h utils.h
indice.o: indice.c indice.h ocorrencias.h utils.h
documento.o: documento.c documento.h utils.h

clean:
	rm -f $(OBJETOS) ep2
