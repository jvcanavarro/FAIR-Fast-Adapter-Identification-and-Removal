#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "PairedFASTQ.cpp"
using namespace std;

class SingleFASTQFile
{
	SingleFASTQ currentSequence;
	string file;
	ifstream fin;	// Stream class to read from files
	ofstream fout; // Stream class to write on files
public:
	bool openFASTQInput(string file);
	bool openFASTQOutput(string file);
	bool hasNext();
	SingleFASTQ getNext();
	void trim(string adapter, int minQuality, int minSequenceLength);
	void write(SingleFASTQ sequence);
	void closeOutput();
};


bool SingleFASTQFile::openFASTQInput(string file)
{
	this->file = file;
	fin.open(file);
	if (fin.is_open()) return true;
	else
	{
		cerr << "Failed to Open Input File" << file << endl;
		return false;
	}
}

bool SingleFASTQFile::openFASTQOutput(string file)
{
	this->file = file;
	fout.open(file);
	if (fout.is_open()) return true;
	else
	{
		cerr << "Failed to Open Output File" << file << endl;
	}
}

bool SingleFASTQFile::hasNext()
{
	string lines[4];
	for (int i = 0; i < 4; i++) if (!getline(fin, lines[i])) return false;

	currentSequence.setIdentifier(lines[0]);
	currentSequence.setSequence(lines[1]);
	currentSequence.setPlaceHolder(lines[2]);
	currentSequence.setQuality(lines[3]);
	return true; 
}

SingleFASTQ SingleFASTQFile::getNext()
{
	return currentSequence;
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

void SingleFASTQFile::closeOutput()
{
	fout.close();
}