
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <limits>
#include <fstream>
#include "TokenizingFunctions.h"
#include "StrngFunctions.h"

using namespace std;

int main()
{
    char mystring[MAX];//string that will hold file data
    char Token[MAX];// A token of the data
    char tokenType, Table[MAX][MAX];//The type of data it will be, Table[][] will hold a particular token type
    int pos=0, count=0, Freq[MAX];
    // pos resets to 0 fro every line read
    //count gives frequency of a token. Freq[MAX] holds count number to correspond it to a

    ifstream file;

    file.open("text");// "text" is open
    while(!file.eof())
    {
        file.getline(mystring,MAX,'\n');// READING LINE BY LINE, use file.read
        cout<<mystring;//Show what was read. Can be excluded
        pos=0;//reset pos to start at pos=0 for every line copied into mystring[]
        while(GetToken(mystring,Token,tokenType,pos)!=true)
        {
            if(tokenType=='A')//only take in alphabet characters. can tke other tokens
            {
                Insert(Table, Token ,count, Freq);//inserts token into Table[][]
            }
        }
    }
    file.close();// close file
    Show2D(Table ,count, Freq);//show 2darray of unique words or characters
    Alphabetize(Table,Freq,count);//alphbetize those words or chars.

    system("pause");

    return 0;
}

