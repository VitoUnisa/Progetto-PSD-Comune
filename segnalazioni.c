#include "segnalazioni.h"

// Funzione per registrare una nuova segnalazione
Segnalazione* inserisciSegnalazione(Segnalazione* head, int* contatoreId) {
    // Allocazione dinamica di un nuovo nodo in memoria
    Segnalazione* nuovoNodo = (Segnalazione*)malloc(sizeof(Segnalazione));
    if (nuovoNodo == NULL) {
        printf("Errore di allocazione memoria!\n");
        return head;
    }

    // Assegnazione dei valori inseriti dall'utente
    nuovoNodo->codice = (*contatoreId)++; // Assegna il codice identificativo e incrementa il contatore
    
    printf("Inserisci nome cittadino: ");
    scanf(" %[^\n]", nuovoNodo->nome); // Legge la stringa con gli spazi
    
    printf("Inserisci categoria (es. strade, illuminazione, rifiuti): ");
    scanf(" %[^\n]", nuovoNodo->categoria);
    
    printf("Inserisci descrizione: ");
    scanf(" %[^\n]", nuovoNodo->descrizione);
    
    printf("Inserisci data (GG/MM/AAAA): ");
    scanf("%s", nuovoNodo->data);
    
    printf("Inserisci livello urgenza (1-5): ");
    scanf("%d", &nuovoNodo->urgenza);
    
    nuovoNodo->stato = 0; // Lo stato iniziale è 0 (Aperta)
    nuovoNodo->next = NULL;

    // Inserimento in testa per ottimizzare i tempi (O(1))
    if (head == NULL) {
        head = nuovoNodo;
    } else {
        nuovoNodo->next = head;
        head = nuovoNodo;
    }
    
    printf("Segnalazione #%d inserita con successo!\n", nuovoNodo->codice);
    return head;
}

// Funzione per visualizzare tutte le segnalazioni registrate
void visualizzaTutte(Segnalazione* head) {
    Segnalazione* temp = head; // Puntatore temporaneo per scorrere la lista
    if (temp == NULL) {
        printf("Nessuna segnalazione presente.\n");
        return;
    }

    while (temp != NULL) {
        printf("\n--- Segnalazione #%d ---\n", temp->codice);
        printf("Cittadino: %s\n", temp->nome);
        printf("Categoria: %s\n", temp->categoria);
        printf("Urgenza: %d | Stato: %d (0=Aperta, 1=In lavorazione, 2=Chiusa)\n", temp->urgenza, temp->stato);
        temp = temp->next; // Passa al nodo successivo
    }
}

// Funzione per la ricerca tramite categoria
void ricercaPerCategoria(Segnalazione* head, char* categoriaCercata) {
    Segnalazione* temp = head;
    int trovati = 0;

    while (temp != NULL) {
        // strcmp compara due stringhe, restituisce 0 se sono identiche
        if (strcmp(temp->categoria, categoriaCercata) == 0) {
            printf("- Codice: %d | Descrizione: %s | Stato: %d\n", temp->codice, temp->descrizione, temp->stato);
            trovati++;
        }
        temp = temp->next;
    }
    if (trovati == 0) {
        printf("Nessuna segnalazione trovata per la categoria '%s'.\n", categoriaCercata);
    }
}

// Funzione per l'aggiornamento dello stato
void aggiornaStato(Segnalazione* head, int codiceCercato, int nuovoStato) {
    Segnalazione* temp = head;
    while (temp != NULL) {
        if (temp->codice == codiceCercato) {
            temp->stato = nuovoStato;
            printf("Stato della segnalazione #%d aggiornato a %d.\n", codiceCercato, nuovoStato);
            return;
        }
        temp = temp->next;
    }
    printf("Segnalazione non trovata.\n");
}

// Funzione per l'eliminazione di una segnalazione
Segnalazione* eliminaSegnalazione(Segnalazione* head, int codiceDaEliminare) {
    Segnalazione *temp = head, *prev = NULL;

    // Se la lista è vuota
    if (temp != NULL && temp->codice == codiceDaEliminare) {
        head = temp->next; // Sposta la testa
        free(temp);        // Libera la memoria
        printf("Segnalazione eliminata.\n");
        return head;
    }

    // Cerca il nodo da eliminare tenendo traccia del nodo precedente
    while (temp != NULL && temp->codice != codiceDaEliminare) {
        prev = temp;
        temp = temp->next;
    }

    // Se il codice non era presente
    if (temp == NULL) {
        printf("Segnalazione non trovata.\n");
        return head;
    }

    // Salta il nodo da eliminare e libera la memoria
    prev->next = temp->next;
    free(temp);
    printf("Segnalazione eliminata.\n");
    
    return head;
}

// Funzione per generare un report aggregato
void generaReport(Segnalazione* head) {
    int totale = 0, aperte = 0, inLavorazione = 0, chiuse = 0;
    Segnalazione* temp = head;

    while (temp != NULL) {
        totale++;
        if (temp->stato == 0) aperte++;
        else if (temp->stato == 1) inLavorazione++;
        else if (temp->stato == 2) chiuse++;
        temp = temp->next;
    }

    printf("\n=== REPORT SEGNALAZIONI ===\n");
    printf("Totale segnalazioni: %d\n", totale);
    printf("Aperte: %d\n", aperte);
    printf("In Lavorazione: %d\n", inLavorazione);
    printf("Chiuse: %d\n", chiuse);
    printf("===========================\n");
}