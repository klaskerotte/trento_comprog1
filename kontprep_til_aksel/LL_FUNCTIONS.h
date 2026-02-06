#ifndef LLPACK
#define LLPACK

// Definerer nodestrukturen for linkedlisten
struct node {
  int data;
  node *next;
};

node *createlist(int size);
void printLL(node *head); // Printer en linked list (LL). Input er listheaden
node *array2list(int *array, int size); // Gjør om en array til en linked list
int *createIDs(
    int size); // Lager en lineær liste med "Id", altså [0 1 2 3 .... size]
int *create_entries(int IDcount,
                    int size); // Lager en liste med random tall mellom 0 og 10
int *create_exits(int IDcount,
                  int size); // Lager en liste med random tall mellom 0 og 10
node *
create_discrepancyLL(node *LLID, node *LL1,
                     node *LL2); // Sjekker differansen mellom id entries og
                                 // exits og lager en varselliste med ID-er som
                                 // har forskjellig antall entries og exits

#endif
