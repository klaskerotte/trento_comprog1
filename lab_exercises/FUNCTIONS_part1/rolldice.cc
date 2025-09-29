using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

void init();	 	//void function = procedure
int rolldices(); 	//function
void youwon();	 	//void function = procedure
void youlost(); 	//void function = procedure

int main()
{
  int mychoice=1;
  int dices;

  init();
  cout << "RAND_MAX is " << RAND_MAX << endl;
  do {
    cout << "What number is expected to exit? [2-12] (different for ends): ";
    cin >> mychoice;
    if ((mychoice>=2)&&(mychoice<=12))
    {
      dices = rolldices();
      cout << dices << " ";
      if (dices==mychoice)
		youwon();
      else
        youlost();
    }
  } while ((mychoice>=2)&&(mychoice<=12));
  return 0;
}

void init()
{
  unsigned int seed = time(NULL);  //what happens without this? .. needed for random numbers generation
  //unsigned int seed = 0;
  srand(seed);
}

int rolldice()
{
  // rand generates a number between 0 and RAND_MAX (not actually random!)
  // the generated number is not not actually random (try to run rand() more times)
  // ... see random_number.cc
  int dice = rand()%6+1;  //it generates a number between 1 and 6
  
  return dice;
}


int rolldices()
{
  int dice1 = rolldice();
  int dice2 = rolldice(); 
  int t = dice1 + dice2;
  return t;
}

void youwon()
{
  cout << "\tyou won.\n";
}

void youlost() 

{
  cout << "\tyou lost.\n";
}
