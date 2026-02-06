#include "LL_FUNCTIONS.h"
#include <cstdlib>
#include <iostream>

int main() {

  // Bestem størrelse på ID-listen/arrayen
  int IDsize = 10;

  // Lag ID-arrayen (lineært fra 0 til "IDsize")
  int *IDarray = createIDs(IDsize);

  // Gjør om fra array til liste
  node *LL_ID = array2list(IDarray, IDsize);
  std::cout << "Creating ID-list" << std::endl;

  // Print linked listen(LL)
  printLL(LL_ID);

  // Lag et random antall entries for hver ID, som array
  int *entriesarray = createIDs(IDsize);

  // Lag et random antall exits for hver ID, som array
  int *exitsarray = createIDs(IDsize);

  // Gjør om entries til LL
  node *LL_entries = array2list(entriesarray, IDsize);
  std::cout << "Creating Entry-list" << std::endl;

  // Gjør om exits til LL
  node *LL_exits = array2list(exitsarray, IDsize);
  std::cout << "Creating Exit-list" << std::endl;

  // Sjekk listene
  printLL(LL_entries);
  printLL(LL_exits);

  // Lag en LL som inneholder tallene som har forskjellig antall entries og
  // exits
  std::cout << "Creating Disc-list " << std::endl;
  node *Dlist = create_discrepancyLL(LL_ID, LL_entries, LL_exits);

  // Sjekk discrepancy list.
  printLL(Dlist);

  return 0;
}
