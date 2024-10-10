#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCARATTERI 1000
#define MAX_LIBRI 100

// Enum per definire le categorie di libro
enum CategoriaLibro {
    NARRATIVA = 1,
    SAGGISTICA,
    SCIENZE,
    ARTE
};

// Struttura per rappresentare un libro
struct Libro {
    char titolo[50];
    char autore[50];
    int annoPubblicazione;
    float prezzo;
    enum CategoriaLibro categoria;
};

// Funzione per leggere i libri da un file CSV
void LeggiLibriDaFileCSV(struct Libro collezioneLibri[], int *numeroLibri) {
    FILE *file;
    char riga[MAXCARATTERI];

    // Apertura del file
    file = fopen("libreria.csv", "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        return;
    }

    // Lettura delle righe del file
    while (fgets(riga, MAXCARATTERI, file) != NULL) {
        if (*numeroLibri >= MAX_LIBRI) {
            printf("Massimo numero di libri raggiunto\n");
            break;
        }

        // Tokenizzazione della riga
        char *token = strtok(riga, ",");
        if (token != NULL) {
            strcpy(collezioneLibri[*numeroLibri].titolo, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(collezioneLibri[*numeroLibri].autore, token);
                token = strtok(NULL, ",");
                if (token != NULL) {
                    collezioneLibri[*numeroLibri].annoPubblicazione = atoi(token);
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        collezioneLibri[*numeroLibri].prezzo = atof(token);
                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            collezioneLibri[*numeroLibri].categoria = atoi(token);
                        }
                    }
                }
            }
        }
        (*numeroLibri)++; // Incremento del contatore dei libri
    }
    fclose(file); // Chiusura del file
}

// Funzione per stampare i libri in base alla categoria
void StampaLibriPerCategoria(const struct Libro collezioneLibri[], int numeroLibri, enum CategoriaLibro categoria) {
    printf("Libri nella categoria %d:\n", categoria);
    for (int i = 0; i < numeroLibri; i++) {
        if (collezioneLibri[i].categoria == categoria) {
            printf("Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                   collezioneLibri[i].titolo, collezioneLibri[i].autore, collezioneLibri[i].annoPubblicazione, collezioneLibri[i].prezzo);
        }
    }
}

// Funzione per cercare un libro per titolo
struct Libro *CercaLibroPerTitolo(const struct Libro collezioneLibri[], int numeroLibri, const char *titolo) {
    for (int i = 0; i < numeroLibri; i++) {
        if (strcmp(collezioneLibri[i].titolo, titolo) == 0) {
            return &collezioneLibri[i]; // Libro trovato
        }
    }
    return NULL; // Libro non trovato
}

// Funzione per leggere la categoria dall'input dell'utente
enum CategoriaLibro LeggiCategoriaUtente() {
    int scelta;
    do {
        printf("\nInserisci la categoria (1: Narrativa, 2: Saggistica, 3: Scienze, 4: Arte): ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 4); // Validazione dell'input
    return (enum CategoriaLibro)scelta; // Ritorna la categoria selezionata
}

int main() {
    struct Libro collezioneLibri[MAX_LIBRI]; // Array per memorizzare i libri
    int numeroLibri = 0; // Contatore per il numero di libri

    LeggiLibriDaFileCSV(collezioneLibri, &numeroLibri); // Leggi i libri dal file

    // Chiedi all'utente di inserire la categoria
    enum CategoriaLibro categoria = LeggiCategoriaUtente();
    StampaLibriPerCategoria(collezioneLibri, numeroLibri, categoria); // Stampa i libri per categoria selezionata

    // Chiedi all'utente di inserire il titolo del libro da cercare
    char titoloDaCercare[50];
    printf("\nInserisci il titolo del libro da cercare: ");
    getchar(); // Consuma il newline rimasto nel buffer
    fgets(titoloDaCercare, sizeof(titoloDaCercare), stdin);
    titoloDaCercare[strcspn(titoloDaCercare, "\n")] = '\0'; // Rimuovi newline

    struct Libro *libroCercato = CercaLibroPerTitolo(collezioneLibri, numeroLibri, titoloDaCercare);
    if (libroCercato) {
        printf("\nLibro trovato: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
               libroCercato->titolo, libroCercato->autore, libroCercato->annoPubblicazione, libroCercato->prezzo);
    } else {
        printf("Libro non trovato\n");
    }

    return 0; // Fine del programma
}