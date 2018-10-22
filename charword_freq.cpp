/************************************************************************************************************************

Name: Rosalba Monterrosas         
Date: 10/15/2018 

Description:
This program determines the number of words and the number of occurrences of each letter in a block of text stored in a 
data file called “mytext.dat”. When outputting the number of words and letters that occur in a line, the upper- and
lowercase versions of a letter are counted as the same letter. The output lists the letters in alphabetical order and 
lists only those letters that do occur in the input data file.
*************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//Prototypes

void Input(ifstream & in, string & word, int counter[]);
void Process(int counter[], string word);
void Output(int counter[], const int size);

///*************************************************************************************
//Name:  Input
//Precondition: The variable string & word has not been initialized. The array int couner[] has been
//initialized to an array of zeroes. The variable int size has been initialized.
//Postcondition: The variable string & word has been initialized. The array int counter[] has been 
//updated with the frequency of words and letters in a file. 
//Description: Get input (value of string & word) from the file. The Process(counter, word) function
//updates the array int counter[] with the frequency of words and letters in the file.
//*************************************************************************************

void Input(ifstream & in, string & word, int counter[]) {
	in.open("mytext.dat");
	if (in.fail()) {
		cout << "Input file did not open correctly.\n";
		exit(1);
	}
	while (!in.eof()) {
		in >> word;
		Process(counter, word);
	}
	in.close();
}

///*************************************************************************************
//Name:  Process
//Precondition: The array int counter[] has been initialized to an array of zeroes. The 
//variable string word has been initialized.
//Postcondition: The array int counter[] has been updated with the frequency of words and 
//letters in a file.
//Description: The array int counter[] counts the frequency of words and letters in a file.
//counter[0] stores the frequency of words, and the values of counter[1] through 
//counter[27] stores the frequency of each letter in the aplhabet. 
//*************************************************************************************

void Process(int counter[], string word) {
	int i;
	char letter;
	
	counter[0]++;
	for (i = 0; i < word.length(); i++) {
		letter = word[i];
		if (letter >= 'A' && letter <= 'Z') {
			counter[letter - 64]++;
		}
		else if (letter >= 'a' && letter <= 'z') {
			counter[letter - 96]++;
		}
	}

}

///*************************************************************************************
//Name:  Output
//Precondition: The array int counter[] has been initialized.
//Postcondition: The array int counter[] has been printed to the screen.
//Description:  Print output (values of int counter[]) to the screen.
//*************************************************************************************

void Output(int counter[], const int size) {
	int i;
	
	cout << counter[0] << "\twords\n";
	for (i = 1; i < size; i++) {
		if (counter[i] != 0)
			cout << counter[i] << "\t" << static_cast<char>(i + 96) << endl;
	}
}

//Driver to test the program

int main(){
	string word;
	ifstream in;
	const int size = 27;
	int counter[size] = { 0 };
	
	Input(in, word, counter);
	Output(counter, size);
	return 0;
}
