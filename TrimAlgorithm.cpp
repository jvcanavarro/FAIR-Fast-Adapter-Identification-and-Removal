#include "PairedFASTQ.cpp"
class TrimAlgorithm
{
	static string default_adapter;
	int minQuality, minSequenceLength;
public:
	TrimAlgorithm(int minQuality ,int minSequenceLength);
	SingleFASTQ removingAdapter(SingleFASTQ untrimmedSequence, string adapter = default_adapter);
};

TrimAlgorithm::TrimAlgorithm(int minQuality, int minSequenceLength)
{
	this->minQuality = minQuality;
	this->minSequenceLength = minSequenceLength;
}

SingleFASTQ TrimAlgorithm::removingAdapter(SingleFASTQ untrimmedSequence, string adapter)
{
	string trimmedSequence = untrimmedSequence.getSequence();
	// search(pattern, pattern_len, text, text_len)
	unsigned char seq_c[trimmedSequence.length()];
	unsigned char adapter_c[adapter.length()];
	
	strcpy( (char*) seq_c, trimmedSequence);
	strcpy( (char*) adapter_c, adapter_c);
	search(adapter_c, adapter.length(),seq_c , trimmedSequence.length());
	untrimmedSequence.setSequence(trimmedSequence);
	return untrimmedSequence;
}
