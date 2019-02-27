#ifndef STRNGFUNCTIONS_H
#define STRNGFUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
#include <limits>

/*+++++++++++++++++++++
 *Luis Romero
 *String Functions
 *8/29/2013
+++++++++++++++++++++*/

using namespace std;
void StrngCopy(char mystring[], char copy_of_my[]);
int StrngCmp(char   mystring[], char mystring2[]);
int StrngLength(char mystring[]);
void StrngConcat(char mystring[], char mystring2[]);
void SubStr(char Str[], char Sub[], int start, int length);
int Find(char Str[], char FindThis[], int pos);
int Find(char FindHere[],char target, int pos);
int FindAny(char Str[], char FindThese[], int pos);
int FindNotAny(char Str[], char FindThese[], int pos);//Dont like it
int ToInt(char Str[], int pos);//EDIT: do not use pow function
float ToFloat(char str[],int pos);//need this
int AtoI(char ConvertThis[]);
void ToLower(char str[]);
bool Eq (char str[], char compare[]);
bool GT (char str[], char compare[]);
bool LT (char str[], char compare[]);

const int MAX=100;

/*+++++++++++++++++++++
 *Function Name: void StrngCopy(char mystring[], char copy_of_my[])
 *Arguments:char mystring[], char copy_of_my[]
 *Function: copies string into a another array
+++++++++++++++++++++*/
void StrngCopy(char mystring[], char copy_of_my[])
{
    int i, mystringLenght=StrngLength(mystring);//limit of loop

    for(i=0;i<mystringLenght;i++)
    copy_of_my[i]=mystring[i];//every element in mystring goes into copy_of_my
    copy_of_my[i]='\0';//add NULL at end or you're gonna have a bad time
}

/*+++++++++++++++++++++
 *Function Name: int StrngCmp(char mystring[], char mystring2[])
 *Arguments: char mystring[], char mystring2[]
 *Function: compares string to another string
+++++++++++++++++++++*/
int StrngCmp(char mystring[], char mystring2[])
{
    int i=0, count=0;
//compare every char for only the amount of the smallest string size.
//it does not make sense to me to copare that to something that does not exist
     if(StrngLength(mystring)<StrngLength(mystring2))
     count=StrngLength(mystring);
     if(StrngLength(mystring)>StrngLength(mystring2))
     count=StrngLength(mystring2);
     else count=StrngLength(mystring);

    while(i<count)
    {
        if(mystring[i]==mystring2[i])//compare the next element in string
            i++;
        else if(mystring[i]>mystring2[i])
            return 1;//return 1 if mystring is larger
        else if(mystring[i]<mystring2[i])//else -1
            return -1;
    }return 0;//return 0 if they are equal
}

/*+++++++++++++++++++++
 *Function Name: int StrngLength(char mystring[])
 *Arguments: char mystring[]
 *Function: returns size of string
+++++++++++++++++++++*/
int StrngLength(char mystring[])
{
    int i=0;
    while(mystring[i]!='\0')
        i++;//keeps incrementing until NULL is found
    return i;
}

/*+++++++++++++++++++++
 *Function Name: void StrngConcat(char mystring[], char mystring2[])
 *Arguments: char mystring[], char mystring2[]
 *Function: adds mystring2[] to char mystring1[]
+++++++++++++++++++++*/
void StrngConcat(char mystring[], char mystring2[])
{
    int lengthstring1=StrngLength(mystring),//get length of mystring1
        lengthstring2=StrngLength(mystring2),//get length of mystring2
        i=0;

    for(i=0;i<lengthstring2;i++)
    {
        mystring[i+lengthstring1]= mystring2[i];//add the chars of mystring2 to mystring1
    }mystring[i+lengthstring1]=NULL;// add NULL to end
}

/*+++++++++++++++++++++
 *Function Name: void SubStr(char Str[], char Sub[], int start, int length)
 *Arguments: char Str[], char Sub[], int start, int length
 *Function: takes part of string and stores it into Sub[]
+++++++++++++++++++++*/
void SubStr(char Str[], char Sub[], int start, int length)
{
    // if(length+start>StrnLength(Str)) make sure you sont go further than the defined lenght of Str
    int i;
    for(i=0; i<length; i++)//for the desired length of string
    {
        Sub[i]=Str[start+i];// let a subtring, Sub[], be PART of a copy of Str[] starting at start until the lenght is reached
    }Sub[i]=NULL;
}

/*+++++++++++++++++++++
 *Function Name: int Find(char Str[], char FindThis[], int pos)// find the position of a string starting at pos. test with sub string.
 *Arguments: char Str[], char FindThis[], int pos
 *Function: Finds a string of chars in block string
+++++++++++++++++++++*/
int Find(char Str[], char FindThis[], int pos)
{
    char compare[MAX];//sub-string of Str that will be compared to FindThis[]
    int start=Find(Str,FindThis[0],pos), length=StrngLength(FindThis);// starting at 'start' for amount of 'length'

    if(start==-1)//if start =-1, means Find() did not find that char in Str
        return -1;
    SubStr(Str,compare,start,length);//create substring of Str
    //and compare it to FindThis[]
    if(StrngCmp(compare,FindThis)!=0)
       return-1;//if not same
    else
       return start;//if same
}

/*+++++++++++++++++++++
 *Function Name: int Find(char FindHere[],char target, int pos)
 *Arguments: char FindHere[],char target, int pos
 *Function: finds a particular char in string and returns pos of it
+++++++++++++++++++++*/
int Find(char FindHere[],char target, int pos)
{
    int limit=StrngLength(FindHere);//limit will length of Str

    for(int i=pos;i<limit;i++)
    {
        if(FindHere[i]==target)
            return i;//if it is found, return pos of the char in FindHere[]
    }
    return -1;//else return -1 of not found
}

/*+++++++++++++++++++++
 *Function Name: int FindAny(char Str[], char FindThese[], int pos)
 *Arguments: char Str[], char FindThese[], int pos
 *Function: searches str[] for any of chars in FindThese[] and returns pos of it
+++++++++++++++++++++*/
int FindAny(char Str[], char FindThese[], int pos)//BUG MAY BE RESOLVED
{
    int limit1=StrngLength(FindThese),
        limit2=StrngLength(Str);

    for(int i=pos;i<limit2;i++)
    {
        for(int a=0;a<limit1;a++)
        {
            if(Str[i]==FindThese[a])
                return i;//retun the first occurence of a set of FindThese[] in Str[]
        }
    }
    return -1;//return -1 if none of the chars of the set FindThese[] is found
}

/*+++++++++++++++++++++
 *Function Name: int FindNotAny(char Str[], char FindThese[], int pos)
 *Arguments: char Str[], char FindThese[], int pos
 *Function: finds where there is not a char of a set in a string
+++++++++++++++++++++*/
int FindNotAny(char Str[], char FindThese[], int pos)
{
    int limit1=StrngLength(FindThese),
        limit2=StrngLength(Str);
    int i=pos,a=0;

    for(i=pos;i<limit2;i++)
    {
        for(a=0;a<limit1;a++)
        {
            if(Str[i]==FindThese[a])
            a=limit1;//BRUTE! HACK! ddont like style but if element of FindThese[]
                     //is found in Str[], then set a=limit to exit loop. REVISE IT.
            else if(Str[i]!=FindThese[a] && a==limit1-1)//has reached the end of set and not found any.
                return i;//else return the pos of Str[] that is not any of elements in FindThese[]
        }
    }return -1;//else return -1 if all elements of FindThese were found in Str.
}

/*+++++++++++++++++++++
 *Function Name: int ToInt(char Str[], int pos)
 *Arguments: char Str[], int pos
 *Function: FInds char number starting at pos
+++++++++++++++++++++*/
int ToInt(char Str[], int pos)
{
    char numbs[]="0123456789";//numbers to look for
    char num[MAX];//char rep of number
    int start=FindAny(Str,numbs,pos);//look for the first occurence of any numbers in set numbs[]

    if(start==-1)//if none is found, return 0(zero) numbers
        return 0;
    int end=FindNotAny(Str,numbs,start);//find pos in Str that is not any numbs[]
    int length=end-start;//get lenght of char of string repping number
    SubStr(Str,num,start,length);//create substring of that number in Str

    return AtoI(num);//convert it to an actuall int number
}

/**********************************************
 *Function Name: int AtoI(char ConvertThis[])
 *Arguments: char ConvertThis[
 *Function: turns char into int
***********************************************/
int AtoI(char ConvertThis[])
{
    double StrNumber[MAX],number=0; //number is returned number
    int length=StrngLength(ConvertThis), i=0;

    for(i=0;i<length;i++)
    {
        StrNumber[i]=ConvertThis[i]-48;//get int rep of each char number
    }
    int a;
    for(a=0,i=length-1;a<length,i>=0;a++,i--)
    {
        number=number+StrNumber[a]*pow(10.0,i);//DO NOT USE POW!
    }
    return number;// int number of
}

/*+++++++++++++++++++++
 *Function Name: void ToLower(char str[]
 *Arguments: char Str[]
 *Function: makes upper case into lower case
+++++++++++++++++++++*/
void ToLower(char str[])//makes upper case into lower case
{
    int length=StrngLength(str);

    for(int i=0;i<length;i++)
    {
        if(str[i]>=65&&str[i]<=90)//check to see the char is in the upper case interval set in ASCII
            str[i]=str[i]+32;//add 32 to jump char to the lower case interval of ASCII
    }
}

/*+++++++++++++++++++++
 *Function Name: bool Eq (char str[], char compare[])
 *Arguments: char Str[], char compare[]
 *Function: Returns true if Str[]==compare[]
+++++++++++++++++++++*/
bool Eq (char str[], char compare[])//equal characters
{
    if(StrngLength(str)>StrngLength(compare)||StrngLength(str)<StrngLength(compare))
        return false;//False if lengths were not equal

    char strCopy[MAX], compareCopy[MAX];//copies Str[] and compare[] in lower case.

    StrngCopy(str,strCopy);//copied so that original is not changed
    StrngCopy(compare,compareCopy);

    ToLower(strCopy);//make all lower case
    ToLower(compareCopy);

    if(StrngCmp(strCopy,compareCopy)==0)
        return true;//true if all chars are equal in ASCII
    else
        return false;//False otherwise
}

/*+++++++++++++++++++++
 *Function Name: bool GT (char str[], char compare[])
 *Arguments: char str[], char compare[]
 *Function: Returns true if Str[]>compare[]
+++++++++++++++++++++*/
bool GT (char str[], char compare[])
{
    //Process like EQ(): copies and lower case all.
    char strCopy[MAX], compareCopy[MAX];

    StrngCopy(str,strCopy);
    StrngCopy(compare,compareCopy);

    ToLower(strCopy);
    ToLower(compareCopy);

    if(StrngCmp(strCopy,compareCopy)==1)
        return true;//true if Str[]>compare[] in ASCII which means a char at Str[i] comes before compare[i]
    else
        return false;
}

/*+++++++++++++++++++++
 *Function Name: bool LT (char str[], char compare[])
 *Arguments: char str[], char compare[]
 *Function: Returns true if Str[]<compare[]
+++++++++++++++++++++*/
bool LT (char str[], char compare[])
{
    //Process same as EQ() and GT()
    char strCopy[MAX], compareCopy[MAX];

    StrngCopy(str,strCopy);
    StrngCopy(compare,compareCopy);

    ToLower(strCopy);
    ToLower(compareCopy);

    if(StrngCmp(strCopy,compareCopy)==-1)
        return true;
    else
        return false;
}
#endif // STRNGFUNCTIONS_H
