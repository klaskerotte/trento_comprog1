#ifndef LLPACK
#define LLPACK

struct node {
  int data;
  node *next;
};

node *createlist(int size);
void printLL(node *head);
node *array2list(int *array, int size);
int *createIDs(int size);
int *create_entries(int IDcount, int size);
int *create_exits(int IDcount, int size);
node *create_discrepancyLL(node *LLID, node *LL1, node *LL2);

#endif
