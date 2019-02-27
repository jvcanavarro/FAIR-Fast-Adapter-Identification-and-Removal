#include "SingleFASTQFile.cpp"

class PairedFASTQFile
{
	SingleFASTQFile forward, reverse;
	PairedFASTQ pairedData;
	pair<string, string> adapter;
public:
	bool openFASTQFile(string forward, string reverse);
	bool hasNext();
	PairedFASTQ getNext();
	pair<string, string> identifyAdapters();
	void trim(string adapter1 ,string adapter2 ,int minQuality ,int minSequenceLength);
	void write(PairedFASTQ fastqPair);
	void closeOutput();
};

bool PairedFASTQFile::openFASTQFile(string forward, string reverse)
{
	if (this->forward.openFASTQInput(forward) && this->reverse.openFASTQInput(reverse))
		return true;
	else
	{
		cerr << "Failed To Open Forward & Reverse Files." << endl;
		return false;
	}
}

bool PairedFASTQFile::hasNext()
{
	if (forward.hasNext() && reverse.hasNext())
	{
		return true;
	}
	else 
	{
		cerr << "EOF" << endl;
		return false;
	}
}

PairedFASTQ PairedFASTQFile::getNext()
{
	pairedData.setPair(forward.getNext(), reverse.getNext());
	return pairedData;
}

pair<string, string> PairedFASTQFile::identifyAdapters()
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