#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>

using namespace std;

ifstream::pos_type filesize(const char* filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg();
}


int exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return atoi(result.c_str());
}

int main (int argc, char *const argv[])
{
    string filepath = argv[1];
    string command = "wc -l " + filepath;
    // string result = exec(command.c_str());
    // int number_of_lines = atoi(result.c_str());
    int number_of_lines = exec(command.c_str());
    cerr << number_of_lines << endl;
    
    return 0;
}
