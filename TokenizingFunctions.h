#ifndef TOKENIZINGFUNCTIONS_H
#define TOKENIZINGFUNCTIONS_H
#include "StrngFunctions.h"

int Zorg(char MyString[], char CharSet[], char Substring[], int pos);
//Determines what type of token a character represents, and creates an array containing the token.
bool GetToken(char Block[], char Token[], char &tokenType, int &pos);
//Determines what type of token a character represents, and creates an array containing the token.

void Insert(char Table[][MAX], char Token[], int &count, int Freq[]);
int Search(char Table[][MAX], char Token[], int count);
void Show2D(char Table[][MAX], int count, int Freq[]);
void Sort(char Table[][MAX], int Freq[], int count);
int IndexOfLargest(int Freq[], int index_start, int count);
void SwapTable(char T1[], char T2[]);
void Swap(int& a, int& b);
void Alphabetize(char Table[][MAX], int Freq[],int count);

char  ALPHAset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
      NUMBERset[]="1234567890",
      PUNCset[]="!@#$%^&*()`~_+-={}:|[]\;'<>""?,./' ";

/*+++++++++++++++++++++
 *Function Name: int Zorg(char MyString[], char CharSet[], char Substring[], int pos)
 *Arguments: char MyString[], char CharSet[], char Substring[], int pos
 *Function: Returns pos of next char substr to extract
+++++++++++++++++++++*/
int Zorg(char MyString[], char CharSet[], char Substring[], int pos)
{
    int length;//of substring to be extracted
    if(FindNotAny(MyString,CharSet,pos)==-1)//if not found, means reached end of strng at NULL
    {
    length=StrngLength(MyString)-FindAny(MyString,CharSet,pos);
    SubStr(MyString,Substring,pos,length);
    return StrngLength(MyString);//make Substr of Str of char set
    }

    else
    {
    length=FindNotAny(MyString,CharSet,pos)-FindAny(MyString,CharSet,pos);
    SubStr(MyString,Substring,pos,length);

    return FindNotAny(MyString,CharSet,pos);//make Substr of Str of char set
    }

}
/*+++++++++++++++++++++
 *Function Name: bool GetToken(char Block[], char Token[], char &tokenType, int &pos)
 *Arguments: char Block[], char Token[], char &tokenType, int &pos
 *Function: Returns true if Block[pos]==NULL
+++++++++++++++++++++*/
bool GetToken(char Block[], char Token[], char &tokenType, int &pos)
{
    if(Block[pos]==NULL)//retunr true if NULL is found
    {
        return true;
    }
    else
    {
    if(Find(ALPHAset,Block[pos],0)!=-1)//Alpha is found
    {
        pos=Zorg(Block,ALPHAset,Token,pos);//pos of next substr to extract
        tokenType='A';//Token type is 'A' to rep Alpha
    }

    else if(Find(NUMBERset,Block[pos],0)!=-1)//Numbers is found
    {
        pos=Zorg(Block,NUMBERset,Token,pos);//pos of next substr to extract
        tokenType='N';//Type 'N'umber
    }
    else if(Find(PUNCset,Block[pos],0)!=-1)
    {
        pos=Zorg(Block,PUNCset,Token,pos);
        tokenType='P';
    }
    }return false;
}
/***************************
 *Function: insert
 *Parameters: Table[][SIZE]
 *Purpose: insserts the token into table[] if it is unique
 *Returns: none
 **************************/
void Insert(char Table[][MAX], char Token[], int &count, int Freq[])
{

    int index(1);
    index=Search(Table, Token, count);//Searches for token in the Table, returns -1 if it is not found
    if(index>=0)
    {
        //token was found to be repeated, increase frequency
        Freq[index]++;
    }
    else if(index<0)
    {
        //copy and increase frequency
        StrngCopy(Token,Table[count]);
        Freq[count]=1;
        count++;
    }
}
/***************************
 *Function: Search
 *Parameters: char Table[][MAX], char Token[], int count
 *Purpose: searches if token has been inserted already in table[]
 *Returns: pos of repeated token
 **************************/

int Search(char Table[][MAX], char Token[], int count)
{

    for(int i=0; i<count; i++)
    {
        if(Eq(Table[i],Token)==true)//revise your StrngCompare function.
        {
            return i;//pos of repeated token in table[]
        }
    }
    return-1;
}
/***************************
 *Function: Show2D
 *Parameters: Table[][SIZE], count, Freq[]
 *Purpose: displays words stored in table
 *Returns: none
 **************************/
void Show2D(char Table[][MAX], int count, int Freq[])
{
    cout<<"\nTABLE OF WORDS USED WITH FREQUENCY: \n";
    for(int i=0;i<count;i++)
    {
         cout<<"\nFreq ["<<Freq[i]<<"]"<<"  "<<Table[i];
    }
    cout<<endl<<endl;
    Sort(Table,Freq, count);
}

/***************************
 *Function: Sort
 *Parameters: Table[][SIZE], count, Freq[]
 *Purpose: sorts table in in terms of frequncy
 *Returns: none
 **************************/
void Sort(char Table[][MAX], int Freq[], int count)
{
    int index_for_largest;
    for(int index=0; index<count-1; index++)
    {
        index_for_largest = IndexOfLargest(Freq, index, count);//finds largest frequency
        Swap(Freq[index], Freq[index_for_largest]);//swapping frequency
        SwapTable(Table[index], Table[index_for_largest]);//swapping table
    }
    //DO NOT COUT THIS HERE...
    cout<<"\nSORTED WITH RESPCT TO WORD FREQUENCY: \n";
    for(int i=0;i<count;i++)
    {
         cout<<"\nFreq ["<<Freq[i]<<"]"<<"  "<<Table[i];
    }
}


/***************************
 *Function: index_of_largest
 *Parameters: a[], index_start[]
 *Purpose: takes the index of the largest number
 *Returns: index  of largest
 ************************/
int IndexOfLargest(int Freq[], int index_start, int count)
{
    int MAX=Freq[index_start];
    int index_for_MAX = index_start;//finds the largest index number
    for(int index=index_start+1; index<count; index++)
    {
        if(MAX<Freq[index])
        {
            MAX = Freq[index];
            index_for_MAX=index;
        }
    }
    return index_for_MAX;
}

/***************************
 *Function: swap
 *Parameters: a, b
 *Purpose: swaps value of array[0] with largest
 *Returns:none
 ************************/
 void Swap(int& a, int& b)
 {
     int c;
     c=a;
     a=b;
     b=c;
 }
 /***************************
  *Function: swapTable
  *Parameters: T1[], T2[]
  *Purpose: swaps value of T[0] with largest most frequent array
  *Returns:none
  ************************/
 void SwapTable(char T1[], char T2[])
{
     char c[MAX];
     StrngCopy(T1,c);// c=T1
     StrngCopy(T2,T1);// T1=T2
     StrngCopy(c,T2);// T2=c
}
 /***************************
  *Function: alphabetized
  *Parameters: Table[][SIZE], Freq[], count
  *Purpose: alphabetizes the words
  *Returns:none
  ************************/
 void Alphabetize(char Table[][MAX], int Freq[],int count)
 {
     for(int i=0; i<count; i++)
     {
         for(int a=i+1; a<count; a++)
         {
             //use LS GT or EQ here
            if(GT(Table[i],Table[a])==true)
            {
                SwapTable(Table[i],Table[a]);
                Swap(Freq[i],Freq[a]);
            }
         }
     }
    //DO NOT COUT THIS IN FUNCTION
     cout<<"\n\nALPHABETIZED: \n ";
     for(int i=0; i<count; i++)
     {
         cout<<"\nFreq ["<<Freq[i]<<"]"<<"  "<<Table[i];
     }
}

#endif // TOKENIZINGFUNCTIONS_H
