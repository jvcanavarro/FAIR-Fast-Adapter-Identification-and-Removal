#include "TrimAlgorithm.cpp"

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
	void write(SingleFASTQ sequence);
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
	;
}

void SingleFASTQFile::trim(string adapter, int minQuality, int minSequenceLength)
{
	// TODO:add pattern matching algorithm to search a given adapter
	TrimAlgorithm trimmer;
	currentSequence = trimmer.removingAdapter(currentSequence);
	cerr <<" SINGLE FASTQ FILE TRIM" << endl;
}

void SingleFASTQFile::write(SingleFASTQ sequence)
{
	cerr << "Writing Sequence (SingleFASTQFile) .." << endl;
	fout << sequence.getSequence() << "\n";
}

void SingleFASTQFile::closeOutput()
{
	fout.close();
}


