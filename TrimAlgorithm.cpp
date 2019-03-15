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
    // trim sequence with adapter and algorithm
    untrimmedSequence.setSequence(trimmedSequence);
    return untrimmedSequence;
}