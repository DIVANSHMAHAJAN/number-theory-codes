#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cout<<"ENTER THE STRING "<<"\n";
    cin>>s;
    int n=s.size();
    int k=5;
    int size=0;
    vector<string>store;
    string str="";
    for(int i=0;i<n;i++)
    {
       int val=s[i]-'A';
       if(size==4)
       {
           
           str+=to_string(val);
           str+=" ";
           store.push_back(str);
           str="";
           size=0;
       }
       else 
       {
           
           str+=to_string(val);
           str+=" ";
           size++;
       }
    }
    if(n%5!=0)
    {
        store.push_back(str);
    }
    vector<string>store2;
    for(auto x:store)
    {
        string storedval=x;
        int num=0;
        for(int i=0;i<storedval.size();i++)
        {
            if(storedval[i]==' ')
            {
                num=(num+k)%26;
               
               store2.push_back(to_string(num));
               num=0;
            }
            else 
            {
               
                num=num*10+storedval[i]-'0';
            }
        }
    }
    string encryptedmsg="";
    size=0;
    for(auto x:store2)
    {
       
        if(size==4)
        {
           encryptedmsg+=(char)(stoi(x)+65);
           encryptedmsg+=" ";
           size=0;
        }
        else 
        {
            encryptedmsg+=(char)(stoi(x)+65);
            size++;
        }
    }
    cout<<"ENCRYPTED MSG USING CAESAR CRYPTOGRAPHY IS "<<encryptedmsg<<"\n";
    //decryption func
    string decryptionmsg=""; 
    for(int y=0;y<encryptedmsg.size();y++)
    {
      if(encryptedmsg[y]==' ')
      {

      }
      else 
      {
          int u=encryptedmsg[y]-'A';
          if((u-k)<0)
          {
             int val=(u-k+26)%26;
             decryptionmsg+=char(val+65);
          }
          else
          {
              int val=(u-k)%26;
              decryptionmsg+=char(val+65);
          }
      }
    }
    cout<<"DECRYPTED MSG USING CAESAR CRYPTOGRAPHY IS "<<decryptionmsg<<" ";
}