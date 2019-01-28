#include <iostream>
#include <vector>
#include "SingleFASTQ.cpp"
using namespace std;

class PairedFASTQ
{
	pair <SingleFASTQ, SingleFASTQ> pair; 
public:
	void setPair(SingleFASTQ foward, SingleFASTQ reverse);
	pair <SingleFASTQ, SingleFASTQ> getPair();
	void trim(string adapter1, string adapter2, int minQuality, int minSequenceLength);
};

void PairedFASTQ::setPair(SingleFASTQ foward, SingleFASTQ reverse)
{
	pair = make_pair(foward, reverse);
}
pair <SingleFASTQ, SingleFASTQ> PairedFASTQ::getPair(){
	return pair;
}

void PairedFASTQ::trim(string adapter, int minQuality, int minSequenceLength){
	;
}