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
    // アルファベット、スペース、改行コード以外をスペースに変換
    for(int i=0; i < size; i++)
        if(isalpha(str[i]) == 0 && str[i] != '\n') str[i] = ' ';

    // Result output
    for(int i=0; i < size; i+=3)
        cout << str[i] << str[i+1] << str[i+2] << endl;
    // cout << "size: " << size << "    strlen: " << strlen(str) << endl;
    delete[] str;

    return 0;
}
