#include <iostream>
#include <vector>
#include <fstream>
#include "SingleFASTQ.cpp"
using namespace std;

class SingleFASTQFile
{
	string file;
	ifstream fin;	
	ofstream fout;
	bool next;
public:
	bool openFASTQInput(string file);
	bool openFASTQOutput(string file);
	bool hasNext();
	SingleFASTQ getNext();
	void trim(string adapter, int minQuality, int minSequenceLength);
	void write(SingleFASTQ sequence);
	bool closeOutput();
};


bool SingleFASTQFile::openFASTQInput(string file){
	
}