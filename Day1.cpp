#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Vars
string fileName = "Day1Data.csv";
int list1[1000];
int list2[1000];
int list1s[1000];
unordered_map<int, int> smap;
int answer = 0;
int answer2 = 0;

string line;

int readFile(string fileName)
{
    int index = 0;
    ifstream file(fileName);
    if(!file.is_open()) return -1;
    while(getline(file, line))
    {
        //Read off data into 2 arrays
        std::stringstream ss(line);
        ss >> list1[index];
        ss >> list2[index];
        //Keep track of how many times things show up in second array
        if(smap[list1[index]]==NULL)
            smap[list1[index]] = 0;
        if(smap[list2[index]]==NULL)
            smap[list2[index]] = 1;
        else
            smap[list2[index]]++;
        index++;
    }
    return 0;
}

int main() 
{
    if(readFile(fileName) < 0)
        cout << "Read File Error!";
    else
    {
        int n = sizeof(list1)/sizeof(list1[0]);
        sort(list1, list1+n);
        sort(list2, list2+n);
        for(int i = 0; i<1000; i++)
        {
            //add distance
            answer += abs(list1[i] - list2[i]);
            //multiply from map we already initialized
            answer2 += list1[i]*smap[list1[i]];
        }
        cout << "The Answer is: ";
        cout << answer;
        cout << "\nThe Second Answer is: ";
        cout << answer2;
    }
    return 0;
}