#include "SingleFASTQFile.cpp"

class PairedFASTQFile
{
	string file;
	SingleFASTQFile forward, reverse;
	PairedFASTQ pairedData;
	pair<string, string> adapter;
	
public:
	bool openFASTQInputFile(string forward, string reverse);
	bool openFASTQOutputFile(string file);
	bool hasNext();
	PairedFASTQ getNext();
	pair<string, string> identifyAdapters();
	void trim(string adapter1 ,string adapter2 ,int minQuality ,int minSequenceLength);
	void write(PairedFASTQ pairedData);
	void closeOutput();
};

bool PairedFASTQFile::openFASTQInputFile(string forward, string reverse)
{
	if (this->forward.openFASTQInput(forward) && this->reverse.openFASTQInput(reverse))
	{
		return true;
	}

	cerr << "Failed To Open Forward & Reverse Files." << endl;
	return false;
}

bool PairedFASTQFile::openFASTQOutputFile(string file)
{
	this->file = file;

	if (this->forward.openFASTQOutput(file) && this->reverse.openFASTQOutput(file) == true)
	{
		return true;
	} 

	return false;
}

bool PairedFASTQFile::hasNext()
{
	if (forward.hasNext() && reverse.hasNext())
	{
		return true;
	}

	return false;
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
	// TODO: add pair <adapter1, adapter2>;
	forward.trim(adapter1, 0, 0);
	reverse.trim(adapter2, 0, 0);
}

void PairedFASTQFile::write(PairedFASTQ pairedData)
{
	cerr << "Writing Sequence (PairedFASTQFile).." << endl;

	reverse.write(get<0>(pairedData.getPair()));
	forward.write(get<1>(pairedData.getPair()));
}

void PairedFASTQFile::closeOutput()
{
	forward.closeOutput();
	reverse.closeOutput();
}