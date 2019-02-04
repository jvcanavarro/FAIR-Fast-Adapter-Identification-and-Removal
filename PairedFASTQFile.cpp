#include <iostream>
#include <vector>
#include <string>
#include "SingleFASTQFile.cpp"
using namespace std;

class PairedFASTQFile
{
	SingleFASTQFile forward, reverse;
	bool next;
public:
	bool openFASTQFile(string forward, string reverse);
	bool hasNext();
	PairedFASTQ getNext();
	void trim(string adapter1 ,string adapter2 ,int minQuality ,int minSequenceLength);
	void write(PairedFASTQ fastqPair);
	void closeOutput();
};

bool PairedFASTQFile::openFASTQFile(string forw, string reve)
{
	return forward.openFASTQInput(forw) && reverse.openFASTQOutput(reve);
}

bool PairedFASTQFile::hasNext()
{
	;
}

PairedFASTQ PairedFASTQFile::getNext()
{
	;
}

void PairedFASTQFile::trim(string adapter1, string adapter2, int minQuality, int minSequenceLength)
{
	;
}

void PairedFASTQFile::write(PairedFASTQ fastqPair)
{
	;
}

void PairedFASTQFile::closeOutput()
{
	;
}