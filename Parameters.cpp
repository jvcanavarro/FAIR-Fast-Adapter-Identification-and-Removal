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
	threads = 4;
	phredOffset = 0;
}

bool Parameters::parseParameters(int argc, char *const argv[])
{
	// Basic Options
	if (argc<=2) // ./main -h
	{
		if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		{	
			printHelp();
			return true;
		}
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
		{
			printVersion();
			return true;
		}	
	}
	else if (argc >= 5) // ./main -s <file_name> -o <output_directory>
	{
		if (strcmp(argv[3], "-o") == 0 || strcmp(argv[3], "--output") == 0)
		{
			outputDir = argv[4];
			if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--single") == 0)
			{
				single = argv[2];
			}
			else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--forward") == 0)
			{
				forward = argv[2];
			}
			else if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--reverse") == 0)
			{
				reverse = argv[2];
			}
			else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--interlaced") == 0)
			{
				interlaced = argv[2];
			}	
		}
		if (argc > 5) // ./main -s <file_name> --only-identify -o <output_directory> ...
		{
			int num_args = 0;
			if (strcmp(argv[3], "--only-identify") == 0) onlyIdentify = true;
			if (strcmp(argv[3], "--only-remove") == 0) onlyRemove = true;
			if (strcmp(argv[3], "--trim") == 0) trim = true;
			if (strcmp(argv[3], "--trim-quality") == 0) trimQuality = true;
			if (strcmp(argv[3], "--min-quality") == 0)
			{
				minQuality = atoi(argv[4]);	
				num_args++ ; // --min-quality <int> -- adapter <adapter> -o <output_directory>
			}
			// Advanced Options.
			// if (strcmp(argv[]))
		}
		else return false;
	}
	else return false;
}
void Parameters::printHelp()
{	
	cout << ifstream("Help.md").rdbuf() << endl;
}
void Parameters::printVersion()
{
	cout << "FAIR - Fast Adapter Idenification and Removal v" << version << endl;
}
string Parameters::getOutputDir()
{
	return outputDir;
}
string Parameters::getSingle()
{
	return single;
}
string Parameters::getForward()
{
	return forward;
}
string Parameters::getReverse()
{
	return reverse;
}
string Parameters::getInterlaced()
{
	return interlaced;
}
bool Parameters::identifyOnly()
{
	if (onlyIdentify) return true;
	else return false;
}
bool Parameters::removeOnly()
{
	if (onlyRemove) return true;
	else return false;
}
bool Parameters::trimm()
{
	if (trim) return true;
	else return false;
}
bool Parameters::trimmQuality()
{
	if (trimQuality) return true;
	else return false;
}
int Parameters::getMinQuality()
{
	return minQuality;
}
string Parameters::getAdapter()
{
	return adapter;
}
string Parameters::getForwardAdapter()
{
	return forwardAdapter;
}
string Parameters::getReverseAdapter()
{
	return reverseAdapter;
}
int Parameters::getThreads()
{
	return threads;
}
int Parameters::getPhredOffset()
{
	return phredOffset;
}