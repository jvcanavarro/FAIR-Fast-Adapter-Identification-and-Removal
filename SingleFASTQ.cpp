#include <iostream>
#include <vector>
using namespace std;

class singleFASTQ
{
	string id, seq, pholder, qual;
public:
	void setIdentifier(string id);
	string getIdentifier();
	void setSequence(string seq);
	string getSequence();
	void setPlaceHolder(string pholder);
	string getPlaceHolder();
	void setQuality(string qual);
	string getQuality();
	vector <int> convertQualityToInteger();
	void trim(string adapter, int minQuality, int minSequenceLength);
};


void singleFASTQ::setIdentifier(string id)
{
	id = id;
}

string singleFASTQ::getIdentifier()
{
	return id;
}
void singleFASTQ::setSequence(string seq)
{
	seq = seq;
}

string singleFASTQ::getSequence()
{
	return seq;
}
void singleFASTQ::setPlaceHolder(string pholder)
{
	pholder = pholder;
}

string singleFASTQ::getPlaceHolder()
{
	return pholder;
}
void singleFASTQ::setQuality(string qual)
{
	qual = qual;
}

string singleFASTQ::getQuality()
{
	return qual;
}