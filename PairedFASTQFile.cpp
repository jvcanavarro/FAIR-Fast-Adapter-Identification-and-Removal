#include <iostream>
#include <vector>
#include "SingleFASTQFile.cpp"
#include "PairedFASTQ.cpp"

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
	bool closeOutput();
};

