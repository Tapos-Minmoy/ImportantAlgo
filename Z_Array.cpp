#include<bits/stdc++.h>
#define pb  push_back
using namespace std;
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int main()
{


 int  n,k;cin>>n>>k;

   string s;cin>>s;

     vector<int>Z=z_function(s);

     int idx=-1;
     int i=1;

     while(i<n)
     {
          if(s[i]>s[0]){break; }
          if(s[i]<s[0])
          {
               i++;
          }
          else
          {
               //check it now on Z function
               if(i==Z[i])
               {
                    //all char matched
                    i+=Z[i];
               }
               else
               {

               int l=i;
               int r=i+Z[i];
               //2 5
               if(r>=n){idx=i;break; }

               if(s[r]<s[Z[i]])
               {
                  //  cout<<"yes"<<" "<<ans<<endl;
                    i+=Z[i];
                    i++;
               }

               else
               {
                 break;

               }

               }
          }

     }

     //cout<<i<<endl;
     string cur=s.substr(0,i);


   //  cout<<ans<<endl;
    string ans;

     while( (int)ans.size()<k)
     {
          ans+=cur;
     }

     for(int i=0;i<k;i++)
     {
          cout<<ans[i];
     }

     cout<<endl;

}
