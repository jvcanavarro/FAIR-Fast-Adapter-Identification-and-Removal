#include "source/sbndmq4.cpp"


class SingleFASTQ
{
	string id, seq, pholder, qual;
	friend ostream &operator<<(ostream &os, const SingleFASTQ &single);

public:
	void setIdentifier(string id);
	string getIdentifier();
	void setSequence(string seq);
	string getSequence();
	void setPlaceHolder(string pholder);
	string getPlaceHolder();
	void setQuality(string qual);
	string getQuality();
	vector<int> convertQ33ToInteger();
	vector<int> convertQ64ToInteger();
	void erase(string adapter);
	void trim(string adapter, int minQuality, int minSequenceLength);
};

string test = "#AAFFJJJJJJJFJJJJJJFJJJJJJFJJJJJJJJJJJJJJFJJJA";

void SingleFASTQ::setIdentifier(string id)
{
	this->id = id;
}
string SingleFASTQ::getIdentifier()
{
	return id;
}

void SingleFASTQ::setSequence(string seq)
{
	this->seq = seq;
}
string SingleFASTQ::getSequence()
{
	return seq;
}

void SingleFASTQ::setPlaceHolder(string pholder)
{
	this->pholder = pholder;
}
string SingleFASTQ::getPlaceHolder()
{
	return pholder;
}

void SingleFASTQ::setQuality(string qual)
{
	this->qual = qual;
}
string SingleFASTQ::getQuality()
{
	return qual;
}

vector<int> SingleFASTQ::convertQ33ToInteger()
{
	vector<int> intQuality;

	// Base 33 : Sanger, Illumina 1.8+.
	for (int i = 0; i < test.length(); i++)
		intQuality.push_back(static_cast<int>(test[i]) - 33);

	return intQuality;
}
vector<int> SingleFASTQ::convertQ64ToInteger()
{

	vector<int> intQuality;

	// Base 64 : Solexa, Illumina-1.3, Illumina-1.5.
	for (int i = 0; i < test.length(); i++)
		intQuality.push_back(static_cast<int>(test[i]) - 64);

	return intQuality;
}

void SingleFASTQ::erase(string adapter)
{
	vector<int>index;

	char seq_c[seq.length() + 1];
	char adapter_c[adapter.length() + 1];

	strcpy(seq_c, seq.c_str());
	strcpy(adapter_c, adapter.c_str());

	index = search(adapter_c, adapter.length(), seq_c, seq.length());

	for(auto&& i: index)
	{
		seq.erase(i, adapter.length());
		qual.erase(i, adapter.length());
	}
}

void SingleFASTQ::trim(string adapter, int minQuality, int minSequenceLength)
{
	// TODO: Identify Phred Offset to Int Quality

	// Trim 'N' Bases on 5/3
	cerr << "Removing 'N' Bases on 5'/3' & Trimming by Quality" << endl << endl;
	for (int i = seq.length(); i = 0; i--)
	{
		if (seq.at(i) == 'N')
		{
			seq.erase(i);
			qual.erase(i);
		}

		if (qual[i] < minQuality)
		{
			seq.erase(i);
			qual.erase(i);
		}
	}
}

ostream &operator<<(ostream &os, const SingleFASTQ &single)
{
	os << single.id << endl;
	os << single.seq << endl;
	os << single.pholder << endl;
	os << single.qual << endl;
	return os;
}