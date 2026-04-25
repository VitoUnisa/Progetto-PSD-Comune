//In questo file (Segnalazioni.h) sono presenti le funzioni prototipo le quali agiscono da interfaccia

#ifndef SEGNALAZIONI_H //ho preferito utilizzare le macro #ifndef (if not defined) ed #endif come forma di sicurezza per il corretto funzionamento del programma
#define SEGNALAZIONI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione della struttura per la singola segnalazione
typedef struct Segnalazione {
    int codice;                  // Codice identificativo univoco
    char nome[50];               // Nome del cittadino
    char categoria[50];          // Categoria del problema (es. buche, illuminazione)
    char descrizione[200];       // Descrizione dettagliata
    char data[15];               // Data di inserimento (es. DD/MM/YYYY)
    int urgenza;                 // Livello di urgenza (es. 1 bassa, 5 alta)
    int stato;                   // 0 = Aperta, 1 = In lavorazione, 2 = Chiusa
    struct Segnalazione* next;   // Puntatore al nodo successivo della lista
} Segnalazione;

// Prototipi delle funzioni (Specifica Sintattica)
Segnalazione* inserisciSegnalazione(Segnalazione* head, int* contatoreId);
void visualizzaTutte(Segnalazione* head);
void ricercaPerCategoria(Segnalazione* head, char* categoriaCercata);
void aggiornaStato(Segnalazione* head, int codiceCercato, int nuovoStato);
Segnalazione* eliminaSegnalazione(Segnalazione* head, int codiceDaEliminare);
void generaReport(Segnalazione* head);

#endif