#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 void solve(string &s,int index , set<string>&seen,vector<string>&ans)
  {
      if(index==s.size())
      {
          if(seen.find(s)==seen.end())
          {
              ans.push_back(s);
              seen.insert(s);
          }
          return;
      }
      for(int i=index;i<s.size();i++)
      {
          swap(s[index],s[i]);
          solve(s,index+1,seen,ans);
          swap(s[index],s[i]);
      }
  }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,j,k;
        cin>>n>>j>>k;
        // find the permutations of n (12,123,1234)
        string s=to_string(n);
        vector<string>ans;
        set<string>seen;
        solve(s,0,seen,ans);

        sort(ans.begin(),ans.end());
        string s1=ans[j-1];
        string s2=ans[k-1];
        int m=s1.size();
        int k1=s2.size();
        int i=0,j1=0;
        int numa=0,numb=0;
        while(i<m &&j1<k1)
        {
            if(s1[i]==s2[j1])numa++;
            i++;
            j1++;
        }

        unordered_map<char,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[s1[i]]++;
        }

        for(int i=0;i<k1;i++)
        {
            if(mp.find(s2[i])!=mp.end())
            {
                numb++;
            }
        }


        cout<<numa<<'A'<<numb-numa<<'B'<<endl;

    }
}