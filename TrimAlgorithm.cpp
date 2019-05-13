#include "PairedFASTQ.cpp"
class TrimAlgorithm
{
	static string default_adapter;
	int minQuality, minSequenceLength;
public:
	void setPreferences(int minQuality ,int minSequenceLength);
	static SingleFASTQ removingAdapter(SingleFASTQ untrimmedSequence, string adapter = "GAGAGT");
};

void TrimAlgorithm::setPreferences(int minQuality, int minSequenceLength)
{
	this->minQuality = minQuality;
	this->minSequenceLength = minSequenceLength;
}

SingleFASTQ TrimAlgorithm::removingAdapter(SingleFASTQ untrimmedSequence, string adapter)
{
	string trimmedSequence = untrimmedSequence.getSequence();
	
	char seq_c[trimmedSequence.length() + 1];
	char adapter_c[adapter.length() + 1];
	
	strcpy(seq_c, trimmedSequence.c_str());
	strcpy(adapter_c, adapter.c_str());
	cout << "Adapter: " << adapter << endl;
	int occurencies = search(adapter_c, adapter.length(),seq_c , trimmedSequence.length());
	// untrimmedSequence.setSequence(trimmedSequence);
	cout << "Number of occurencies: " << occurencies << endl;
	return untrimmedSequence;
}
