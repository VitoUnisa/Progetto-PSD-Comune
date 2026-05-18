#include "segnalazioni.h"

int main() {

    printf("===== AVVIO TEST =====\n");

    int id = 1;

    //creazione nodi test

    Segnalazione* s1 = (Segnalazione*)malloc(sizeof(Segnalazione));
    Segnalazione* s2 = (Segnalazione*)malloc(sizeof(Segnalazione));

    //controllo allocazione memoria

    if(s1 == NULL || s2 == NULL) {
        printf("Errore allocazione memoria.\n");
        return 1;
    }

    //prima segnalazione di test

    s1->codice = id++;
    strcpy(s1->nome, "Post Malone");
    strcpy(s1->categoria, "Buche");
    strcpy(s1->descrizione, "Buche profonde in strada");
    strcpy(s1->data, "10/05/2026");
    s1->urgenza = 5;
    s1->stato = 0;

    //Seconda segnalazione di test

    s2->codice = id++;
    strcpy(s2->nome, "Francesco Zalone");
    strcpy(s2->categoria, "Illuminazione");
    strcpy(s2->descrizione, "Lampione guasto");
    strcpy(s2->data, "11/05/2026");
    s2->urgenza = 3;
    s2->stato = 1;

    //collegamento della lista test

    s1->next = s2;
    s2->next = NULL;

    Segnalazione* lista = s1;

    //visualizza lista completa

    printf("\nTEST INSERIMENTO\n");
    visualizzaTutte(lista);

    printf("\nTEST RICERCA PER CODICE ESISTENTE\n");
    ricercaPerCodice(lista, 1);

    printf("\nTEST RICERCA PER CODICE NON ESISTENTE\n");
    ricercaPerCodice(lista, 99);

    printf("\nTEST RICERCA PER CATEGORIA\n");
    ricercaPerCategoria(lista, "Buche");

    printf("\nTEST AGGIORNAMENTO STATO\n");
    aggiornaStato(lista, 1, 2);
    visualizzaTutte(lista);

    printf("\nTEST VISUALIZZAZIONE PER STATO\n");
    visualizzaPerStato(lista, 2);

    printf("\nTEST SEGNALAZIONI URGENTI\n");
    visualizzaUrgenti(lista);

    printf("\nTEST REPORT\n");
    generaReport(lista);

    printf("\nTEST ELIMINAZIONE\n");
    lista = eliminaSegnalazione(lista, 1);
    visualizzaTutte(lista);

    //deallocazione memoria
    liberaMemoria(lista);

    printf("\n===== TEST COMPLETATI! =====\n");


    //Getchar per mantenere aperto il CMD
    getchar();
    getchar();

    return 0;
    //fine
}
