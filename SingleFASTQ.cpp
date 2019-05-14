#include "source/qf43.cpp"

class SingleFASTQ
{
	string id, seq, pholder, qual;
	friend ostream & operator << (ostream &os, const SingleFASTQ& single);
	
public:
	void setIdentifier(string id);
	string getIdentifier();
	void setSequence(string seq);
	string getSequence();
	void setPlaceHolder(string pholder);
	string getPlaceHolder();
	void setQuality(string qual);
	string getQuality();
	vector <int> convertQ33ToInteger();
	vector <int> convertQ64ToInteger();
	void trim(string adapter, int minQuality, int minSequenceLength);
};

// string test = "#AAFFJJJJJJJFJJJJJJFJJJJJJFJJJJJJJJJJJJJJFJJJA";

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

vector <int> SingleFASTQ::convertQ33ToInteger()
{
	
	vector <int> intQuality;	
	
	// Base 33 (Ilumina, Ion Torrent, PacBio and Sanger)
	for (int i = 0; i < test.length(); i++) intQuality.push_back(static_cast <int> (test[i]) - 33);

	return intQuality;
}
vector <int> SingleFASTQ::convertQ64ToInteger()
{
	
	vector <int> intQuality;
	
	// Base 64 (Old Illumina)
	for (int i = 0; i < test.length(); i++) intQuality.push_back(static_cast <int> (test[i]) - 64);
		
	return intQuality;
}

void SingleFASTQ::trim(string adapter, int minQuality, int minSequenceLength)
{
	;
}

ostream & operator << (ostream &os, const SingleFASTQ& single)
{
	os << single.id << endl;
	os << single.seq << endl;
	os << single.pholder << endl;
	os << single.qual << endl;
	return os;
}