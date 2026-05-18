#include "segnalazioni.h"   //Header file di "segnalazioni.h"

int main() {

    Segnalazione* lista = NULL; //Inizializzazione puntatore "lista"

    int scelta;
    int contatoreCodici = 1;

    do {
            //Stampa delle possibili operazioni
        printf("\n===== GESTIONE SEGNALAZIONI COMUNE =====\n");
        printf("1. Inserisci segnalazione\n");
        printf("2. Visualizza tutte\n");
        printf("3. Ricerca per categoria\n");
        printf("4. Ricerca per codice\n");
        printf("5. Aggiorna stato\n");
        printf("6. Visualizza per stato\n");
        printf("7. Visualizza urgenti\n");
        printf("8. Elimina segnalazione\n");
        printf("9. Genera report\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        scanf("%d", &scelta);   //Assume il valore da dare allo switch


        //Switch per scelta dell'operazione
        switch(scelta) {

            case 1:
                lista = inserisciSegnalazione(lista, &contatoreCodici);
                break;

            case 2:
                visualizzaTutte(lista);   
                break;
            
            case 3: {
                char categoria[50];     

                printf("Inserisci categoria: ");
                scanf(" %[^\n]", categoria);        

                ricercaPerCategoria(lista, categoria);  
                break;
            }

            case 4: {
                int codice; 

                printf("Inserisci codice: ");
                scanf("%d", &codice);

                ricercaPerCodice(lista, codice);
                break;
            }

            case 5: {
                int codice, stato;

                printf("Codice segnalazione: ");
                scanf("%d", &codice);

                printf("Nuovo stato (0=Aperta, 1=Lavorazione, 2=Chiusa): ");
                scanf("%d", &stato);

                aggiornaStato(lista, codice, stato);
                break;
            }

            case 6: {
                int stato;

                printf("Stato da visualizzare (0=Aperta, 1=Lavorazione, 2=Chiusa): ");
                scanf("%d", &stato);

                visualizzaPerStato(lista, stato);
                break;
            }

            case 7:
                visualizzaUrgenti(lista);
                break;

            case 8: {
                int codice;

                printf("Codice da eliminare: ");
                scanf("%d", &codice);

                lista = eliminaSegnalazione(lista, codice);
                break;
            }

            case 9:
                generaReport(lista);
                break;

            case 0:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Scelta non valida.\n");
        }

    } while(scelta != 0);

    liberaMemoria(lista);   //Liberazione memoria a fine programma

    return 0;
}
