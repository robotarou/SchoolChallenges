#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000000 // 1MB

int main()
{
    // loading
    ifstream ifs("../data/The_Sins_of_the_Cities_of_the_Plain_by_Jack_Saul.txt");
    if (ifs.fail())
    {
        cerr << "Error loading" << endl;
        return -1;
    }
    int begin = static_cast<int>(ifs.tellg());
    ifs.seekg(0, ifs.end);
    int end = static_cast<int>(ifs.tellg());
    int size = end - begin;
    ifs.clear();  
    ifs.seekg(0, ifs.beg);
    char* str = new char[size + 1];
    ifs.read(str, size);

    // Result output
    for(int i=0; i < size; i++)
        cout << str[i] << endl;
    // cout << "size: " << size << "    strlen: " << strlen(str) << endl;
    delete[] str;

    return 0;
}
