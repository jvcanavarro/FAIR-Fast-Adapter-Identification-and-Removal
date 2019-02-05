#include <iostream>
#include <string>
#include "PairedFASTQFile.cpp"
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
	bool trimm();
	bool trimmQuality();
	int getMinQuality();
	string getAdapter();
	string getForwardAdapter();
	string getReverseAdapter();
	int getThreads();
	int getPhredOffset();	// Quality
};

bool Parameters::parseParameters(int argc, char **argv)
{
	cout << "You have entered " << argc << " arguments." << endl;
	for (int i = 0; i < argc; i ++) cout << argv[i] << endl ;
}
void Parameters::printHelp()
{

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
