#include <iostream>
#include <vector>
#include <utility>
#include "SingleFASTQ.cpp"
using namespace std;

class PairedFASTQ
{
	pair <SingleFASTQ, SingleFASTQ> fastqPair; 
public:
	void setPair(SingleFASTQ forward, SingleFASTQ reverse);
	pair <SingleFASTQ, SingleFASTQ> getPair();
	void trim(string adapter1, string adapter2, int minQuality, int minSequenceLength);
};

void PairedFASTQ::setPair(SingleFASTQ forward, SingleFASTQ reverse)
{
	pair = make_pair(forward, reverse);
}
pair <SingleFASTQ, SingleFASTQ> PairedFASTQ::getPair(){
	return pair;
}

void PairedFASTQ::trim(string adapter, int minQuality, int minSequenceLength)
{
	;
}