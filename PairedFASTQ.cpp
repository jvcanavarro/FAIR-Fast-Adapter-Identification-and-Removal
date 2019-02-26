#include "SingleFASTQ.cpp"

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
	fastqPair = make_pair(forward, reverse);
}
pair <SingleFASTQ, SingleFASTQ> PairedFASTQ::getPair(){
	return fastqPair;
}

void PairedFASTQ::trim(string adapter1, string adapter2, int minQuality, int minSequenceLength)
{
	;
}