#ifndef BSTFUNCTIONS // Dette sier at filen ikke skal inkluderes mer enn én gang
#define BSTFUNCTIONS // Dette også

// Dette er en headerfil. Derav .h på slutten av filen
// Tenk på dette som en enkel håndbok for funksjonene. De sier
//      hvilken type funksjonen returnerer
//      hva funksjonen heter
//      hvilke argumenter funksjonen tar inn
//
// For å se hvordan selve funksjonene fungerer, sjekk BSTFUNCTIONS.cpp filen

// Definerer en type objekt som heter node.
// Hver node inneholder:
//      data som er en integer
//      left som er en pointer til venstre node
//      right som er en pointer til høyre node

struct node {
  int data;
  node *left;
  node *right;
};

int *createarray(
    int size); // Lager en array med random integers mellom 0 til 10. Tar inn
               // størrelsen på arrayen du vil lage.

void printarray(int *array,
                int size); // Printer arrays på en fin måte. Tar inn en
                           // arraypointer og størrelsen på arrayen

node *insert_element(node *tree, int value); // En hjelperfunksjon for å sette
                                             // inn verdier i et binært søketre

node *createBST(int *array,
                int size); // Tar inn en array av integers og arrangerer disse i
                           // en binær søketre struktur.

void fancyprintBST(node *tree, int depth); // Printer ut tréet ditt

#endif // BSTFUNCTIONS
