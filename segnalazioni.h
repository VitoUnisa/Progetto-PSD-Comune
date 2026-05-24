#ifndef SEGNALAZIONI_H      //"ifndef" ed "endif" per evitare inclusioni multiple
#define SEGNALAZIONI_H

//Librerie utilizzate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struttura delle segnalazioni
typedef struct Segnalazione {
    int codice;             //Codice identificativo
    char nome[50];          //Nome del cittadino
    char categoria[50];     //Categoria della segnalazione
    char descrizione[200];  //Descrizione della segnalazione
    char data[15];          //Data di inserimento
    int urgenza;            //Livello urgenza della segnalazione
    int stato;              //Stato della segnalazione: 0 = Aperta, 1 = In lavorazione, 2 = Chiusa

    struct Segnalazione* next;  //Puntatore al nodo della lista successivo 
} Segnalazione;

//Operazioni e prototipi delle funzioni:
Segnalazione* inserisciSegnalazione(Segnalazione* head, int* contatoreId);      //inserire nuova segnalazione
void visualizzaTutte(Segnalazione* head);                                       //elenca tutte le segnalazioni
void ricercaPerCategoria(Segnalazione* head, char* categoriaCercata);           //ricerca segnalazioneper categoria
void ricercaPerCodice(Segnalazione* head, int codice);                          //ricerca segnalazione per codice
void aggiornaStato(Segnalazione* head, int codiceCercato, int nuovoStato);      //aggiornamento dello stato di una segnalazione
void visualizzaPerStato(Segnalazione* head, int stato);                         //visualizza le segnalazioni in un determnato stato
void visualizzaUrgenti(Segnalazione* head);                                     //visualizza quelle più urgenti (stato >= 4)
Segnalazione* eliminaSegnalazione(Segnalazione* head, int codiceDaEliminare);   //eliminazione di una segnalazione
void generaReport(Segnalazione* head);                                          //generatore report delle segnalazioni
void liberaMemoria(Segnalazione* head);                                         //liberazione della memoria 

#endif
