#include "LL_FUNCTIONS.h"
#include <cstdlib>
#include <iostream>

int main() {

  int IDsize = 10;
  int *IDarray = createIDs(IDsize);
  node *LL_ID = array2list(IDarray, IDsize);
  std::cout << "Creating ID-list" << std::endl;
  printLL(LL_ID);

  int *entriesarray = createIDs(IDsize);
  int *exitsarray = createIDs(IDsize);

  node *LL_entries = array2list(entriesarray, IDsize);
  std::cout << "Creating Entry-list" << std::endl;
  node *LL_exits = array2list(exitsarray, IDsize);
  std::cout << "Creating Exit-list" << std::endl;

  printLL(LL_entries);
  printLL(LL_exits);

  std::cout << "Creating Disc-list " << std::endl;
  node *Dlist = create_discrepancyLL(LL_ID, LL_entries, LL_exits);
  printLL(Dlist);

  return 0;
}
