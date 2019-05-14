#include "PairedFASTQ.cpp"

class SingleFASTQFile
{
	SingleFASTQ currentSequence;
	string file, adapter;
	ifstream fin;
	ofstream fout;

public:
	bool openFASTQInput(string file);
	bool openFASTQOutput(string file);
	bool hasNext();
	SingleFASTQ getNext();
	string identifyAdapter();
	void trim(string adapter, int minQuality, int minSequenceLength);
	void removeAdapter(string adapter, bool onlyRemove);
	void write();
	void closeOutput();
};


bool SingleFASTQFile::openFASTQInput(string file)
{
	this->file = file;

	fin.open(file);
	if (fin.is_open())
	{
		return true;
	}
	
	cerr << "Failed to Open Input File" << file << endl;
	return false;
}

bool SingleFASTQFile::openFASTQOutput(string file)
{
	this->file = file;

	fout.open(file);
	if (fout.is_open())
	{
		return true;
	}

	cerr << "Failed to Open Output File" << file << endl;
	return false;
}

bool SingleFASTQFile::hasNext()
{
	string lines[4];

	for (int i = 0; i < 4; i++) 
		if (!getline(fin, lines[i]))
			return false;

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

string SingleFASTQFile::identifyAdapter()
{
	// TODO
	return adapter;
}

void SingleFASTQFile::trim(string adapter, int minQuality, int minSequenceLength)
{
	;
}

void SingleFASTQFile::removeAdapter(string adapter, bool onlyRemove)
{
	// TODO: Add this->adapter or remove it.
	string newSequence = currentSequence.getSequence();

	if (!onlyRemove)
	{
		adapter = identifyAdapter();
	}

	char seq_c[newSequence.length() + 1];
	char adapter_c[adapter.length() + 1];
	
	strcpy(seq_c, newSequence.c_str());
	strcpy(adapter_c, adapter.c_str());

	int removed = search(adapter_c, adapter.length(),seq_c , newSequence.length());
	// currentSequence.setSequence(newSequence);

	cerr << "Adapter: " << adapter << endl;
	cerr << "Adapters Removed: " << removed << endl;

}

void SingleFASTQFile::write()
{
	cerr << "Writing Sequence (SingleFASTQFile) .." << endl;

	// fout << currentSequence.getIdentifier() << "\n";
	fout << currentSequence.getSequence() << "\n";
	// fout << currentSequence.getPlaceHolder() << "\n";
	// fout << currentSequence.getQuality() << "\n";
}

void SingleFASTQFile::closeOutput()
{
	fout.close();
}


