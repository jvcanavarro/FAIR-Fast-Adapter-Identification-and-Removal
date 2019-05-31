#include "SingleFASTQFile.cpp"

class PairedFASTQFile
{
	string file;
	SingleFASTQFile forward, reverse;
	PairedFASTQ pairedSequence;
	pair<string, string> adapters;

public:
	bool openFASTQInputFile(string forward, string reverse, int quality);
	bool openFASTQOutputFile(string file);
	bool hasNext();
	PairedFASTQ getNext();
	pair<string, string> identifyAdapters();
	void trim(int minQuality, int minSequenceLength);
	void removeAdapters(bool onlyRemove, string adapter1, string adapter2);
	void write();
	void closeOutput();
};

bool PairedFASTQFile::openFASTQInputFile(string forward, string reverse, int quality)
{
	if (this->forward.openFASTQInput(forward, quality) && this->reverse.openFASTQInput(reverse, quality))
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
	return (forward.hasNext() && reverse.hasNext());
}

PairedFASTQ PairedFASTQFile::getNext()
{
	pairedSequence.setPair(forward.getNext(), reverse.getNext());
	return pairedSequence;
}

pair<string, string> PairedFASTQFile::identifyAdapters()
{
	adapters.first = forward.identifyAdapter();
	adapters.second = reverse.identifyAdapter();
	return adapters;
}

void PairedFASTQFile::trim(int minQuality, int minSequenceLength)
{
	// TODO: add pair <adapter1, adapter2>;
	forward.trim(0, 0);
	reverse.trim(0, 0);
}

void PairedFASTQFile::removeAdapters(bool onlyRemove, string adapter1, string adapter2)
{
	forward.removeAdapter(onlyRemove, adapter1);
	reverse.removeAdapter(onlyRemove, adapter2);
}

void PairedFASTQFile::write()
{
	cerr << "Writing PairedFASTQ" << endl;

	forward.write();
	reverse.write();
}

void PairedFASTQFile::closeOutput()
{
	forward.closeOutput();
	reverse.closeOutput();
}