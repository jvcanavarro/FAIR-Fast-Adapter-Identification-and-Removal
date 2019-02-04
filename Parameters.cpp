#include <iostream>
#include <string>
using namespace std;

class Parameters
{
	string outputDir,version, single, forward, reverse, interlaced, adapter, forwardAdapter, reverseAdapter;
	bool onlyIdentify, onlyRemove, trim, trimQuality;
	int minQuality, threads, phredOffset;
public:
	bool parseParameters(int argc, char **argv);
	void printHelp();
	void printVersion();
	string getOutputDir();
	string getSingle();
	string getForward();
	string getReverse();
	string getInterlaced();
	bool identifyOnly();
	bool removeOnly();
	bool trim();
	bool trimQuality();
	int getMinQuality();
	string getAdapter();
	string getForwardAdapter();
	string getReverseAdapter();
	int getThreads();
	int getPhredOffset();	// Quality
}

bool Parameters::parseParameters(int argc, char **argv)
{
	
}