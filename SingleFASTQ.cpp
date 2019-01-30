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
	vector <int> convertQ33ToInteger();
	vector <int> convertQ64ToInteger();
	void trim(string adapter, int minQuality, int minSequenceLength);
};
string test = "#AAFFJJJJJJJFJJJJJJFJJJJJJFJJJJJJJJJJJJJJFJJJA";

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

vector <int> singleFASTQ::convertQ33ToInteger()
{
	
	vector <int> intQuality;	
	
	// Base 33 (Ilumina, Ion Torrent, PacBio and Sanger)
	for (int i = 0; i < test.length(); i++) intQuality.push_back(static_cast <int> (test[i]) - 33);

	return intQuality;
}
vector <int> singleFASTQ::convertQ64ToInteger()
{
	
	vector <int> intQuality;
	
	// Base 64 (Old Illumina)
	for (int i = 0; i < test.length(); i++) intQuality.push_back(static_cast <int> (test[i]) - 64);
		
	return intQuality;
}

void singleFASTQ::trim(string adapter, int minQuality, int minSequenceLength){
	;
}