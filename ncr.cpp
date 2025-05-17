const int N=1e5+3;
const int mod=1e9+7;
int fact[N];
int invMod[N];
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
void cal()
{

        fact[0]=1;
        invMod[0]=1;
        for(int i=1;i<N;i++)
        {
             fact[i]=(fact[i-1]*i)%mod;
             invMod[i]=binpow(fact[i],mod-2,mod);
        }
}

  int ncr( int n,int  r)
  {
       if(r==0 || r==n)
       {
            return 1;
       }
       if(r>n)
       {
            return 0;
       }

       int up=fact[n];
       int dn1=invMod[n-r];
       int dn2=invMod[r];

       return  (((up*dn1)%mod)*dn2)%mod;
  }
  int main()
  {

       return 0;
  }
