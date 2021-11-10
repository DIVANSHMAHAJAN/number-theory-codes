#include<bits/stdc++.h>
using namespace std;
int main() {
cout<<"ENTER THE NUMBER OF TEAMS FOR WHICH YOU WANT TO SCHEDULE ROUND ROBIN"<<"\n";
   int n;
   cin>>n;
   if(n%2==0)
   {
   for(int i=1;i<=n-1;i++)
   {
       cout<<"Round "<<i<<"\n";
       map<int,int>mp;
       set<pair<int,int>>st;
       if(i!=n-1)
       {
       for(int j=1;j<=n;j++)
       {
           for(int u=1;u<=n;u++)
           {
               if((u+j)%(n-1)==i&&u!=j&&u!=n&&j!=n)
               {
                   mp[u]++;
                   mp[j]++;
                   if(u<j)
                   st.insert({u,j});
                   else 
                   {
                       st.insert({j,u});
                   }
               }
           }
       }
       }
       else 
       {
            for(int j=1;j<=n;j++)
       {
           for(int u=1;u<=n;u++)
           {
               if((u+j)%(n-1)==0&&u!=j&&u!=n&&j!=n)
               {
                   mp[u]++;
                   mp[j]++;
                   if(u<j)
                   st.insert({u,j});
                   else 
                   {
                       st.insert({j,u});
                   }
                   //cout<<u<<" "<<j<<"\n";
               }
           }
       }
       }
       for(int h=1;h<=n-1;h++)
       {
           if(mp[h]==0)
           {
               st.insert({h,n});
           }
       }
       for(auto x:st)
       {
           cout<<x.first<<" "<<x.second<<"\n";
       }
       cout<<"\n";
   }
   }
   else 
   {
      int z=n+1;
      for(int i=1;i<=z-1;i++)
   {
       cout<<"Round "<<i<<"\n";
       map<int,int>mp;
       set<pair<int,int>>st;
       if(i!=z-1)
       {
       for(int j=1;j<=n;j++)
       {
           for(int u=1;u<=n;u++)
           {
               if((u+j)%(n)==i&&u!=j&&u!=z&&j!=z)
               {
                   mp[u]++;
                   mp[j]++;
                   if(u<j)
                   st.insert({u,j});
                   else 
                   {
                       st.insert({j,u});
                   }
               }
           }
       }
       }
       else 
       {
            for(int j=1;j<=n;j++)
       {
           for(int u=1;u<=n;u++)
           {
               if((u+j)%(n)==0&&u!=j&&u!=z&&j!=z)
               {
                   mp[u]++;
                   mp[j]++;
                   if(u<j)
                   st.insert({u,j});
                   else 
                   {
                       st.insert({j,u});
                   }
                   //cout<<u<<" "<<j<<"\n";
               }
           }
       }
       }
       for(int h=1;h<=z-1;h++)
       {
           if(mp[h]==0)
           {
               st.insert({h,z});
           }
       }
       for(auto x:st)
       {
           if(x.second!=z)
           cout<<x.first<<" "<<x.second<<"\n";
           else 
           {
               cout<<x.first<<" "<<"dummy/bye"<<"\n";
           }
       }
       cout<<"\n";
   }
   }
}
