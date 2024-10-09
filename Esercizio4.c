/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define LEN 4

typedef struct {
    char modelloAuto[30];
    char marca[30];
    int cilindrata;
    int prezzo;
    int annoImmatricolazione;
} Auto;

void stampaAuto(Auto arr[]) {
    for (int i = 0; i < LEN; i++) {
        printf("Modello: %s\nMarca: %s\nCilindrata: %d\nPrezzo: %d\nAnno immatricolazione: %d\n\n", arr[i].modelloAuto, arr[i].marca, arr[i].cilindrata, arr[i].prezzo, arr[i].annoImmatricolazione);
    }
}

Auto autoPiuCostosa(Auto arr[]) {
    Auto autoCostosa = arr[0];
    
    for (int i = 1; i < LEN; i++) {
        if (autoCostosa.prezzo < arr[i].prezzo) {
            autoCostosa = arr[i];
        }
    }
    
    return autoCostosa;
}

Auto autoMenoCostosa(Auto arr[]) {
    Auto autoEconomica = arr[0];
    
    for (int i = 1; i < LEN; i++) {
        if (autoEconomica.prezzo > arr[i].prezzo) {
            autoEconomica = arr[i];
        }
    }
    
    return autoEconomica;
}

void ordinaAutoPerAnno(Auto arr[]) {
    Auto temp;
    
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (arr[i].annoImmatricolazione > arr[j].annoImmatricolazione) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void stampaAutoDaPrezzo(Auto arr[], int prezzo) {
    for (int i = 0; i < LEN; i++) {
        if (arr[i].prezzo <= prezzo) {
            printf("Modello: %s\nMarca: %s\nCilindrata: %d\nPrezzo: %d\nAnno immatricolazione: %d\n\n", arr[i].modelloAuto, arr[i].marca, arr[i].cilindrata, arr[i].prezzo, arr[i].annoImmatricolazione);
        }
    }
}

int main(int argc, char *argv[]) {
    Auto arr[LEN];
    
    strcpy(arr[0].modelloAuto, "m8");
    strcpy(arr[0].marca, "bmw");    
    arr[0].cilindrata = 1600;
    arr[0].prezzo = 30000;
    arr[0].annoImmatricolazione = 2020;
    
    strcpy(arr[1].modelloAuto, "Classe g");
    strcpy(arr[1].marca, "mercedes");    
    arr[1].cilindrata = 1800;
    arr[1].prezzo = 25000;
    arr[1].annoImmatricolazione = 2015;
    
    strcpy(arr[2].modelloAuto, "zl1");
    strcpy(arr[2].marca, "chevrolet");    
    arr[2].cilindrata = 2000;
    arr[2].prezzo = 27000;
    arr[2].annoImmatricolazione = 2016;
    
    strcpy(arr[3].modelloAuto, "Challenger SRT");
    strcpy(arr[3].marca, "Dodge");    
    arr[3].cilindrata = 1700;
    arr[3].prezzo = 22000;
    arr[3].annoImmatricolazione = 2008;
    
    Auto autoCostosa = autoPiuCostosa(arr);
    Auto autoEconomica = autoMenoCostosa(arr);
    
    printf("\n1)\nAUTO PIU' COSTOSA\nPrezzo: %d\nModello: %s\n", autoCostosa.prezzo, autoCostosa.modelloAuto);
    printf("\nAUTO MENO COSTOSA\nPrezzo: %d\nModello: %s\n", autoEconomica.prezzo, autoEconomica.modelloAuto);
    
    printf("\n2)\n");
    printf("Auto in ordine in base all'anno di immatricolazione:\n");
     printf("\n");
    ordinaAutoPerAnno(arr);
    stampaAuto(arr);
    
    printf("\n3)\n");
    int prezzo;
    printf("Prezzo di partenza: ");
    scanf("%d", &prezzo);
    printf("\n");
    printf("Auto con il prezzo minore di quello indicato:\n");
     printf("\n");
    stampaAutoDaPrezzo(arr, prezzo);
    
    return 0;
}
