CC = gcc					#Scelta del compilatore
CFLAGS = -Wall -std=c99		#Flag utilizzati Wall -> warnings e std=c99 per utilizzare lo standard c99



all: main test		#Compila il main e il test

main: main.o segnalazioni.o		#Crea il file EXE del main
	$(CC) $(CFLAGS) -o main main.o segnalazioni.o

test: test.o segnalazioni.o		#Crea il file EXE del test
	$(CC) $(CFLAGS) -o test test.o segnalazioni.o

main.o: main.c segnalazioni.h	#Compila main.c
	$(CC) $(CFLAGS) -c main.c

test.o: test.c segnalazioni.h	#Compila test.c
	$(CC) $(CFLAGS) -c test.c

segnalazioni.o: segnalazioni.c segnalazioni.h	#Compila segnalazioni.c
	$(CC) $(CFLAGS) -c segnalazioni.c

clean:							#Pulizia dei file ed eliminazione degli eseguibili main e test
	del /Q *.o main.exe test.exe
