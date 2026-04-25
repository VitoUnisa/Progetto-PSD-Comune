#include "segnalazioni.h"

int main() {
    Segnalazione* listaSegnalazioni = NULL; // Inizializza la lista vuota
    int contatoreCodici = 1;                // Contatore per i codici univoci
    int scelta;

    do {
        // Stampa del menu interattivo
        printf("\n--- GESTIONE SEGNALAZIONI COMUNE ---\n");
        printf("1. Registra nuova segnalazione\n");
        printf("2. Visualizza tutte le segnalazioni\n");
        printf("3. Cerca per categoria\n");
        printf("4. Aggiorna stato segnalazione\n");
        printf("5. Elimina segnalazione\n");
        printf("6. Genera Report\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                listaSegnalazioni = inserisciSegnalazione(listaSegnalazioni, &contatoreCodici);
                break;
            case 2:
                visualizzaTutte(listaSegnalazioni);
                break;
            case 3: {
                char cat[50];
                printf("Inserisci la categoria da cercare: ");
                scanf(" %[^\n]", cat);
                ricercaPerCategoria(listaSegnalazioni, cat);
                break;
            }
            case 4: {
                int cod, st;
                printf("Codice segnalazione: ");
                scanf("%d", &cod);
                printf("Nuovo stato (0=Aperta, 1=Lavorazione, 2=Chiusa): ");
                scanf("%d", &st);
                aggiornaStato(listaSegnalazioni, cod, st);
                break;
            }
            case 5: {
                int cod;
                printf("Codice segnalazione da eliminare: ");
                scanf("%d", &cod);
                listaSegnalazioni = eliminaSegnalazione(listaSegnalazioni, cod);
                break;
            }
            case 6:
                generaReport(listaSegnalazioni);
                break;
            case 0:
                printf("Uscita dal programma. Arrivederci!\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 0);

    // Prima di uscire, sarebbe buona pratica liberare tutta la memoria allocata rimasta (free della lista)
    Segnalazione* current = listaSegnalazioni;
    Segnalazione* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}