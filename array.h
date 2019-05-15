#include <iostream>
using namespace std;

enum SortList{ACCENDANT, DECENDANT};

//void SortArray(int nInputArray[], unsigned nArraySize, SortList mList)
//Sorting Array with Parameter from the Array, the size, and how it should be sorted
void SortArray(int nInputArray[], unsigned nArraySize, SortList mList)
{
    int i,j,temp;
    if(mList==ACCENDANT)
    {
        for(i=0;i<=nArraySize;i++)
        {
            for(j=0;j<=nArraySize-i;j++)
            {
                if(nInputArray[j]>nInputArray[j+1])
                {
                    temp=nInputArray[j];
                    nInputArray[j]=nInputArray[j+1];
                    nInputArray[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(i=0;i<nArraySize;i++)
	    {		
            for(j=i+1;j<nArraySize;j++)
            {
                if(nInputArray[i]<nInputArray[j])
                {
                    temp = nInputArray[i];
                    nInputArray[i] = nInputArray[j];
                    nInputArray[j] = temp;
                }
            }
	    }
    }
    
    
}

//void _89LinearSearch_SearchKeyInArray(float fInputArray[], int nArraySize, const float key)
//with this method the System will 
//search the Key in the Array from the beginning to 
//end of the Array until it found the Key
void _89LinearSearch_SearchKeyInArray(float fInputArray[], int nArraySize, const float key)
{
    bool bKeyFounded= false;
    for(int i=0;i<nArraySize;i++)
    {
        if(fInputArray[i]==key)
        {
            bKeyFounded=true;
            cout<<"Key founded in Array at Element ["<<i<<"]"<<endl;
            break;
        }
    }
    if(!bKeyFounded) cout<<"Key not founded"<<endl;
}


void _90BinarySearch(int nInputArray[], int nArraySize, const int key)
{
    bool bKeyFounded= false; 
    SortArray(nInputArray,nArraySize,ACCENDANT);
    int lowIndex=0, highIndex=nArraySize-1, middleIndex;
    while(1)
    {
        middleIndex=(lowIndex+highIndex)/2;
        if(key>nInputArray[middleIndex])
        {
            cout<<"1: "<<lowIndex<<"|"<<middleIndex<<"|"<<highIndex<<"|key:"<<key<<"|array:"<<nInputArray[middleIndex]<<endl;
            lowIndex=middleIndex+1;     
        }
        else if(key==nInputArray[middleIndex]) 
        {
            bKeyFounded= true;
            cout<<"2: "<<lowIndex<<"|"<<middleIndex<<"|"<<highIndex<<"|key:"<<key<<"|array:"<<nInputArray[middleIndex]<<endl; 
            cout<<"Key founded in Array"<<endl;
            break;
        }
        else
        {
            cout<<"3: "<<lowIndex<<"|"<<middleIndex<<"|"<<highIndex<<"|key:"<<key<<"|array:"<<nInputArray[middleIndex]<<endl;
            highIndex = middleIndex-1;
        }
        if(lowIndex>highIndex) 
        {
            bKeyFounded= false;
            break;
        }
    }
    if(!bKeyFounded) cout<<"Key not founded"<<endl;
}