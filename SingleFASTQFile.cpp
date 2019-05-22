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
	void identifyQuality();
	void trim(string adapter, int minQuality, int minSequenceLength);
	void removeAdapter(bool onlyRemove, string adapter);
	void write();
	void closeOutput();
};

bool SingleFASTQFile::openFASTQInput(string file)
{
	this->file = file;

	identifyQuality();

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
	// this->file = file;

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

void SingleFASTQFile::identifyQuality()
{
	cout << endl << "Phred Quality Offset of " << file << ":" << endl;
	
	string command = "sed -n '2p' " + file + " > seq_sample.fastq";

	system(command.c_str());
	system("python3 source/identify-phred.py seq_sample.fastq");
	system("rm seq_sample.fastq");

	cout << endl;
}

void SingleFASTQFile::trim(string adapter, int minQuality, int minSequenceLength)
{
	;
}

void SingleFASTQFile::removeAdapter(bool onlyRemove, string adapter)
{
	// TODO: Add this->adapter or remove it.
	cerr << file << endl;
	string newSequence = currentSequence.getSequence();

	if (onlyRemove) // String OK
	{
		this->adapter = adapter;
	}
	else // Need to Identify
	{
		adapter = identifyAdapter();
	}


	char seq_c[newSequence.length() + 1];
	char adapter_c[adapter.length() + 1];

	strcpy(seq_c, newSequence.c_str());
	strcpy(adapter_c, adapter.c_str());

	vector<int> index = search(adapter_c, adapter.length(), seq_c, newSequence.length());

	cerr << "Adapters Indexes: ";
	for (auto it = index.cbegin(); it != index.cend(); it++)
	{
		cerr << *it << ' ';
	}
	cerr << endl;
	// cerr << endl << "Adapter: " << adapter << endl;
}

void SingleFASTQFile::write()
{
	cerr << "Writing SingleFASTQ Sequence..." << endl;

	// fout << currentSequence.getIdentifier() << "\n";
	fout << currentSequence.getSequence() << "\n";
	// fout << currentSequence.getPlaceHolder() << "\n";
	// fout << currentSequence.getQuality() << "\n";
}

void SingleFASTQFile::closeOutput()
{
	fout.close();
}
