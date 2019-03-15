#include "SingleFASTQ.cpp"
class TrimAlgorithm
{
    static string default_adapter;
    int minQuality, minSequenceLength;
public:
    TrimAlgorithm(int minQuality ,int minSequenceLength);
    SingleFASTQ removeAdapter(SingleFASTQ untrimmedSequence, string adapter = default_adapter);
};

TrimAlgorithm::TrimAlgorithm(int minQuality, int minSequenceLength)
{
    this->minQuality = minQuality;
    this->minSequenceLength = minSequenceLength;
}

SingleFASTQ TrimAlgorithm::removeAdapter(SingleFASTQ untrimmedSequence, string adapter = default_adapter)
{
    string trimmedSequence = untrimmedSequence.getSequence();
    // trim sequence with adapter and algorithm
}