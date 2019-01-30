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
}

bool SingleFASTQFile::openFASTQOutput(string file)
{
	fout.open(file);
}

SingleFASTQ SingleFASTQFile::getNext()
{

}

void SingleFASTQFile::trim(string adapter, int minQuality, int minSequenceLength)
{

}

void SingleFASTQFile::write(SingleFASTQ sequence)
{

}

bool SingleFASTQFile::closeOutput()
{

}