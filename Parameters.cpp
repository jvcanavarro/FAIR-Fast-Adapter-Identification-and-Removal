#include <iostream>
#include <string.h>
#include <fstream>
#include "PairedFASTQFile.cpp"
using namespace std;

class Parameters
{
	string outputDir,version, single, forward, reverse, interlaced, adapter, forwardAdapter, reverseAdapter;
	bool onlyIdentify , onlyRemove, trim, trimQuality;
	int minQuality, threads, phredOffset;
public:
	Parameters();
	bool parseParameters(int argc, char *const argv[]);
	void printHelp();
	void printVersion();
	string getOutputDir();
	string getSingle();
	string getForward();
	string getReverse();
	string getInterlaced();
	bool identifyOnly();
	bool removeOnly();
	bool trimm();
	bool trimmQuality();
	int getMinQuality();
	string getAdapter();
	string getForwardAdapter();
	string getReverseAdapter();
	int getThreads();
	int getPhredOffset();	// Quality
};

Parameters::Parameters()
{
	version = "1.0";
	onlyIdentify = false;
	onlyRemove = false;
	trim = false;
	trimQuality = false;
	threads = 1;
	phredOffset = 0;
}

bool Parameters::parseParameters(int argc, char *const argv[])
{
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
	{	
		printHelp();
		return 1;
	}
	else
	{
		cout << " OK " << endl;
		return 1;
	}
}
void Parameters::printHelp()
{	
	cout << ifstream("Help.md").rdbuf() << endl;
}
void Parameters::printVersion()
{

}
string Parameters::getOutputDir()
{

}
string Parameters::getSingle()
{

}
string Parameters::getForward()
{

}
string Parameters::getReverse()
{

}
string Parameters::getInterlaced()
{

}
bool Parameters::identifyOnly()
{

}
bool Parameters::removeOnly()
{

}
bool Parameters::trimm()
{

}
bool Parameters::trimmQuality()
{

}
int Parameters::getMinQuality()
{

}
string Parameters::getAdapter()
{

}
string Parameters::getForwardAdapter()
{

}
string Parameters::getReverseAdapter()
{

}
int Parameters::getThreads()
{

}
int Parameters::getPhredOffset()
{

}
