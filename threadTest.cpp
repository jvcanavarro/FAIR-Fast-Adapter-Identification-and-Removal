#include <iostream>
#include <thread>
#include <string>
using namespace std;

void task(string msg)
{
    cout << "task1 says: " << msg << endl;
}

int main ()
{
    string msg = "Hello";
    thread t1(task, msg);
   
    t1.join();
    return 0;
}
