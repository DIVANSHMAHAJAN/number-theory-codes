#include <bits/stdc++.h>
using namespace std;
#define TABLE_SIZE 5000
#define PRIME 4969
 
class DoubleHash
{
    // Pointer to an array containing buckets
    int *hashTable;
    int curr_size;
 
public:
 
    // function to check if hash table is full
    bool isFull()
    {
 
        // if hash size reaches maximum size
        return (curr_size == TABLE_SIZE);
    }
 
    
    int hash1(int key)
    {
        return (key % PRIME);
    }
 
    int hash2(int key)
    {
        return (key+1)%(PRIME-2);
    }
 
    DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i=0; i<TABLE_SIZE; i++)
            hashTable[i] = -1;
    }
 
    
    void insertHash(int key)
    {
       
        if (isFull())
            return;
 
        
        int index = hash1(key);
       
       
        if (hashTable[index] != -1)
        {
            // get index2 from second hash
            int index2 = hash2(key);
            int i = 1;
            while (1)
            {
                int newIndex = (index + i * index2) %
                                        PRIME;
                if (hashTable[newIndex] == -1)
                {

                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }
 
        
        else
            hashTable[index] = key;
        curr_size++;
    }
    void displayHash()
    {
    	cout<<"HASH TABLE WILL BE AS FOLLOWS"<<"\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (hashTable[i] != -1)
                cout << i << " --> "
                     << hashTable[i] << endl;
           
        }
    }
};
int main()
{
	cout<<"ENTER THE NUMBER OF KEYS TO BE STORED"<<"\n";
	int n;
	cin>>n;
	int a[n];
    for(int i=0;i<n;i++)
    {
    	cout<<"ENTER THE VALUE TO BE STORED"<<"\n";
    	cin>>a[i];
    	
	}
	
 
 
    
    DoubleHash h;
    for (int i = 0; i < n; i++)
        h.insertHash(a[i]);
 
    h.displayHash();
    
}
