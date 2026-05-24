#include "segnalazioni.h"       //Inclusione file header segnalazioni.h


//Convertitore dello stato da numerico a stringa
const char* statoToString(int stato) {
    switch(stato) {
        case 0: return "Aperta";
        case 1: return "In lavorazione";
        case 2: return "Chiusa";
        default: return "Sconosciuto";  //In caso di inserimento di un numero non incluso tra 0 e 2 ritorna di base "Sconosciuto"
    }
}


//inseriemnto segnalazione
Segnalazione* inserisciSegnalazione(Segnalazione* head, int* contatoreId) {

    Segnalazione* nuovoNodo = (Segnalazione*)malloc(sizeof(Segnalazione));  //Allocazione memoria per nuovo nodo


        //controllo allocazione memoria
    if (nuovoNodo == NULL) {
        printf("Errore allocazione memoria!\n");
        return head;
    }


    nuovoNodo->codice = (*contatoreId)++;   //Creazione codice identificativo automatico


    //Inserimento dei vari dati 
    printf("Nome cittadino: ");
    scanf(" %[^\n]", nuovoNodo->nome);

    printf("Categoria problema: ");
    scanf(" %[^\n]", nuovoNodo->categoria);

    printf("Descrizione: ");
    scanf(" %[^\n]", nuovoNodo->descrizione);

    printf("Data (GG/MM/AAAA): ");
    scanf("%s", nuovoNodo->data);



        //Controllo del valore assegnato ad "urgenza"
    do {
        printf("Livello urgenza (1-5): ");
        scanf("%d", &nuovoNodo->urgenza);
    } while(nuovoNodo->urgenza < 1 || nuovoNodo->urgenza > 5);

    nuovoNodo->stato = 0;   //Stato iniziale

    //Assegnamento nuova testa
    nuovoNodo->next = head;

    head = nuovoNodo;

    printf("\n\n\nSegnalazione inserita con codice #%d\n\n\n", nuovoNodo->codice);

    return head;
}


//Visualizzazione lista completa
void visualizzaTutte(Segnalazione* head) {

    Segnalazione* temp = head;     //Puntatore temporaneo ad head


    //Controllo lista vuota
    if (temp == NULL) {
        printf("Nessuna segnalazione presente.\n");
        return;
    }


    //Stampa lista
    while(temp != NULL) {

        printf("\n===== SEGNALAZIONE =====\n");

        printf("Codice: %d\n", temp->codice);               //Stampa codice identificativo

        printf("Cittadino: %s\n", temp->nome);              //Stampa nome cittadino

        printf("Categoria: %s\n", temp->categoria);         //Stampa categoria

        printf("Descrizione: %s\n", temp->descrizione);     //Stampa descrizione

        printf("Data: %s\n", temp->data);                   //Stampa data

        printf("Urgenza: %d\n", temp->urgenza);             //Stampa urgenza

        printf("Stato: %s\n", statoToString(temp->stato));  //Stampa stato

        temp = temp->next;  //Punta al prossimo nodo
    }
}


//Ricerca per categoria
void ricercaPerCategoria(Segnalazione* head, char* categoriaCercata) {

    Segnalazione* temp = head;      //Puntatore temporaneo ad head
    int trovata = 0;

    while(temp != NULL) {

        //Confronto delle categorie
        if(strcmp(temp->categoria, categoriaCercata) == 0) {

            printf("Codice: %d | Stato: %s | Urgenza: %d\n", temp->codice, statoToString(temp->stato), temp->urgenza);

            trovata = 1;
        }

        temp = temp->next;      //Va al prossimo nodo
    }


    //Controllo sengalazioni trovate
    if(!trovata) {
        printf("Nessuna segnalazione trovata.\n");
    }
}


//Ricerca per codice
void ricercaPerCodice(Segnalazione* head, int codice) {

    Segnalazione* temp = head;      //Puntatore temporaneo ad head

    while(temp != NULL) {

        //Comparazione codice identificativo
        if(temp->codice == codice) {

            printf("\nSegnalazione trovata:\n");
            printf("Categoria: %s\n", temp->categoria);
            printf("Descrizione: %s\n", temp->descrizione);
            printf("Stato: %s\n", statoToString(temp->stato));
            return;
        }

        temp = temp->next;    //Va al prossimo nodo finchè non è stato trovato o finchè non sono finiti
    }

    printf("Segnalazione non trovata.\n");
}


//Aggiornamento stato di una segnalazione esistente
void aggiornaStato(Segnalazione* head, int codiceCercato, int nuovoStato) {

    Segnalazione* temp = head;      //Puntatore temporaneo ad head

    while(temp != NULL) {
        //Verifica codice
        if(temp->codice == codiceCercato) {

        temp->stato = nuovoStato;   //Assegnazione nuovo stato

            printf("Stato aggiornato correttamente.\n");
            return;
        }

        temp = temp->next;
    }

    printf("Segnalazione non trovata.\n");
}

void visualizzaPerStato(Segnalazione* head, int stato) {

    Segnalazione* temp = head;      //Puntatore temporaneo ad head
    int trovata = 0;

    while(temp != NULL) {
        //Verifica stato
        if(temp->stato == stato) {

            printf("Codice: %d | Categoria: %s\n", temp->codice, temp->categoria);
            trovata = 1;
        }

        temp = temp->next;
    }

    //Controllo segnalazione non trovata
    if(!trovata) {
        printf("Nessuna segnalazione con questo stato.\n");
    }
}


//Visualizza le segnalazioni più urgenti
void visualizzaUrgenti(Segnalazione* head) {

    Segnalazione* temp = head;      //Puntatore temporaneo ad head
    int trovata = 0;

    while(temp != NULL) {
        //Controllo livello urgenza
        if(temp->urgenza >= 4) {

            printf("Codice: %d | Categoria: %s | Urgenza: %d\n", temp->codice, temp->categoria, temp->urgenza);
            trovata = 1;
        }

        temp = temp->next;
    }
    //Controllo segnalazione non trovata
    if(!trovata) {
        printf("Nessuna segnalazione urgente.\n");
    }
}


//Eliminazione segnalazione
Segnalazione* eliminaSegnalazione(Segnalazione* head, int codiceDaEliminare) {

    Segnalazione *temp = head;      //Puntatore temporaneo ad head
    Segnalazione *prev = NULL;      //Puntatore "prev" (Precedente) necessario per l'eliminazione essendo una lista semplice

    while(temp != NULL && temp->codice != codiceDaEliminare) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Segnalazione non trovata.\n");
        return head;
    }

    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);     //Eliminazione dati

    printf("Segnalazione eliminata.\n");

    return head;
}



//Generazione report
void generaReport(Segnalazione* head) {

    int totale = 0;
    int aperte = 0;
    int lavorazione = 0;
    int chiuse = 0;
 

    Segnalazione* temp = head;      //Puntatore temporaneo ad head

    printf("\n\n===== REPORT =====\n");
    printf("-Segnalazioni aperte o chiuse-\n");
    while(temp != NULL) {

        totale++;

        if(temp->stato == 0){
            aperte++;
        }

        else if(temp->stato == 1)
            lavorazione++;

        else if(temp->stato == 2)
            chiuse++;

//Stampa report e dati
 if(temp->stato == 0 || temp->stato == 2){
                printf("Codice: %d\n", temp->codice);
                printf("Nome cittadino: %s\n", temp->nome);
                printf("Cateogria: %s\n", temp->categoria);
                printf("Descrizione: %s\n", temp->descrizione);
                printf("Data: %s\n", temp->data);
                printf("Livello urgenza: %d\n", temp->urgenza);
                printf("Stato: %d\n\n\n", temp->stato);
            }
        temp = temp->next;
    }
    
    printf("Totale segnalazioni: %d\n", totale);
    printf("Segnalazioni aperte: %d\n", aperte);
    printf("Segnalazioni in lavorazione: %d\n", lavorazione);
    printf("Segnalazioni chiuse: %d\n\n\n", chiuse);
}

//Eliminazione lista
void liberaMemoria(Segnalazione* head) {

    Segnalazione* temp;

    while(head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}
