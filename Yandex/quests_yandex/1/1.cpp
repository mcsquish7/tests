#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{   
    ifstream file_1;
    file_1.open("input.txt");
    string line;
    int A, B;
    while (getline(file_1, line))
    {
        istringstream iss(line);
        if (!(iss >> A >> B))
        {
            cerr << "Error parsing line: " << line << endl;
            continue;
        }
    }
    ofstream file_2;
    file_2.open("output.txt");
    file_2 << A + B;
    return 0;
}
