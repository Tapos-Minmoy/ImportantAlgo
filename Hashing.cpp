#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=1e6+1;
 int  Hash[mx];
 int revHash[mx];
 const int mod=1e9+7;
 const int p=31;
 int InV[mx];
 long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 void Hash_it( string rev)
 {
      int power=1;
      Hash[0]=0;
      revHash[0]=0;
      string s=rev;
      reverse(rev.begin(),rev.end());
        for(int i=0;i<s.size();i++)
        {
            int cur=s[i]-'a'+1;
            int cur1=rev[i]-'a'+1;
             Hash[i+1]=(Hash[i]+(cur*power)%mod)%mod;
            revHash[i+1]=(revHash[i]+(cur1*power)%mod)%mod;
               cur=binpow(power,mod-2,mod);
            InV[i]=cur;
            power=(power*p)%mod;
        }
 }
 int get_hash(int L,int R)
 {

      int res=Hash[R]  -Hash[L-1] ;
      if(L==1)return res;
      int kk;
      kk=(res*InV[L-1])%mod;
     if(kk<0)kk+=mod;
     return kk;

 }

 int get_hashrev(int L,int R,int n)
 {

 int l=L;
      L=(n-R)+1;
      R=(n-l)+1;
    int res=revHash[R]  -revHash[L-1] ;
      if(L==1)return res;
     int kk=(res*InV[L-1])%mod;
     if(kk<0)kk+=mod;
     return kk;

 }
 bool is_palin(int l,int r,int n)
 {
      if(get_hash(l,r)==get_hashrev(l,r,n))return true;
      return false;
 }
  pair<int,int> OD(int mid,int n)
 {
    int l=1,r=min(mid-1,n-mid);
     int mx=0;
    while(l<=r)
    {
       int m=(l+r) /2;
       int L= mid-m;
       int R=mid+m;
       if(is_palin(L,R,n))
       {
            l=m+1;
            mx=max(mx,m);
       }
       else r=m-1;
       //  4
       //2
       //4-2=2
       //2 3 4

    }
    return make_pair(mid-mx,(mx*2)+1);

 }
 pair<int,int>EVN (int mid,int n)
 {
   int l=1,r=min(mid,n-mid);
     int mx=0;
    while(l<=r)
    {
       int m=(l+r) /2;
       int L= mid-m+1;
       int R=mid+m;
       if(is_palin(L,R,n))
       {
            l=m+1;
            mx=max(mx,m);
       }
       else r=m-1;
       //  4
       //2
       //4-2=2
       //2 3 4

    }
    return make_pair(mid-mx+1,mx*2);
 }
   signed main()
{








}
