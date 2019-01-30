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
	return fin.is_open();
}

bool SingleFASTQFile::openFASTQOutput(string file)
{
	fout.open(file);
	return fout.is_open();
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
}

bool SingleFASTQFile::closeOutput()
{
	fout.close();
	// return fout.is_close(); ERRO
	// http://www.cplusplus.com/reference/ios/ios_base/iostate/
	// http://www.cplusplus.com/reference/ios/ios_base/failure/
	// http://www.cplusplus.com/reference/fstream/fstream/close/
}