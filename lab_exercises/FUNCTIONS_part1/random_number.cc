#include<iostream>
#include<cstdlib>
using namespace std;

  // Additional reading on random https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
  

int main(){
	
	int selec=0;
	cout << " Generate random number 1 (0:RAND_MAX) 2 (1:6): ";
	cin >> selec;
	
	// Providing a seed value
	srand((unsigned) time(NULL)); //what happens withot the seed value? ... always the same random number
	
	int random=-1;
	
	//Selection =1
	if (selec==1) {
		// Get a random number between 1 and 6
		random = rand();
	}
	else if (selec==2){
		// Get a random number between 1 and 6
		random = rand()%6+1;  
	}
	else {
		cout<< "Wrong selection"<<endl;
	}
	
	// Print the random number
	cout<<random<<endl;
			
	return 0;
}