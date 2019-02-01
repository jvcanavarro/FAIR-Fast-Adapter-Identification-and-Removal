#include <iostream>
#include <vector>
#include <fstream>
#include "SingleFASTQ.cpp"
using namespace std;

class SingleFASTQFile
{
	string file;
	ifstream fin;	// Stream class to read from files
	ofstream fout; // Stream class to write on files
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


bool SingleFASTQFile::openFASTQInput(string file)
{
	fin.open(file);	
	if (fin.is_open()) return 1;
	else return 0; // TODO: Error message
}

bool SingleFASTQFile::openFASTQOutput(string file)
{
	fout.open(file);
	if (fout.is_open()) return 1;
	else return 0; // TODO: Error message
}

bool SingleFASTQFile::hasNext(){
	;
}

SingleFASTQ SingleFASTQFile::getNext()
{
	;
}

void SingleFASTQFile::trim(string adapter, int minQuality, int minSequenceLength)
{
	;
}

void SingleFASTQFile::write(SingleFASTQ sequence)
{
	// fin << sequence;
	;
}

bool SingleFASTQFile::closeOutput()
{
	fout.close();
}