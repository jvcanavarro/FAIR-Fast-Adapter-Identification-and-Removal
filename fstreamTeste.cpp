#include <iostream>
#include <fstream>

using namespace std;


int main (){
	ofstream myfile;
	myfile.open("exemple.txt");
	myfile << "Writing to this file.\n";
	myfile.close();
	
}