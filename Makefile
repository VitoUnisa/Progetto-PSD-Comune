#Variabili per il compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

#Nome dell'eseguibile finale al quale puntare
TARGET = progetto_segnalazioni

#Compilazione generale
all: $(TARGET)

#Creazione eseguibile collegndo i file oggeto 
$(TARGET): main.o segnalazioni.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o segnalazioni.o

#Compilazione main
main.o: main.c segnalazioni.h
	$(CC) $(CFLAGS) -c main.c

#Compilazione delle funzioni
segnalazioni.o: segnalazioni.c segnalazioni.h
	$(CC) $(CFLAGS) -c segnalazioni.c

#Pulizia con "make clean"
clean:
	rm -f *.o $(TARGET)
