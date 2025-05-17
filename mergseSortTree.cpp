#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int mx=2e5+2;

vector<int>odTre[mx*4];
vector<int>evnTre[mx*4];
int a[mx];

void build( int si,int ss,int se)
{

     if(ss==se)
     {

           odTre[si].pb(a[ss]);

         return;

     }

     int mid=(ss+se)/2;
     build(si*2,ss,mid);
     build((si*2)+1,mid+1,se);
     merge(Tre[si*2].begin(),Tre[si*2].end(),Tre[(si*2)+1].begin(),Tre[1+(si*2)].end(),back_inserter(Tre[si]));




}

int query(int si,int ss,int se,int L,int R,int k)
{
    if(se<L || ss>R)
    {
         return 0;
    }

    if(ss>=L and se<=R)
    {
        // cout<<ss<<" "<<se<<" "<<odTre[si].size()<<" "<<si<<endl;
         auto kk=

    }
     int mid=(ss+se)/2;
      return query(si*2,ss,mid,L,R,idx,parity)+query(1+(si*2),mid+1,se,L,R,idx,parity);

}
int main()
{

    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
    }

    build(1,1,n);
    int half=k/2;
    long long   ans=0;

    for(int i=1;i<=n;i++)
    {
         //

         //calculate L and R
         if(i+k-1<=n)
         {
              int R=i+k-1;
              int key=min(i,half)-1;
              key*=2;
               int L=R-key;
               int res=query(1,1,n,L,R,i,i&1);
            //  cout<<(i+k-1)-key<<" "<<i+k-1<<" "<<i<<endl;
             // cout<<L<<" "<<R<<" "<<res<<" "<<i<<endl;
              int tot=(R-L)/2;tot+=1;
             // cout<<tot-res<<endl;
              ans+=(tot-res);
              //3  5 7
              //2 4 6
              //6-2=4/2=2
         }
        else
        {

          int R=i+k-1;
          int dif=R-n;
          int curi=i-dif;
          if(i+half+1>n)continue;
          //form curi to curi+k-1;
          int R1=curi+k-1;

          //curi i
          int rg=i-curi+1;
          int dif1=min(half-rg+1,curi)-1;


          //where i pointed to??
          //R1-rg+1;
          int calR=R1-rg+1;
          int calL=calR-(dif1*2);
          int res=query(1,1,n,calL,calR,i,i&1);
         // cout<<curi<<" "<<R1<<" "<<i<<" "<<rg<<endl;
         // cout<<calL<<" "<<calR<<" "<<res<<" "<<i<<endl;
          int tot=(calR-calL)/2;tot+=1;
             // cout<<tot-res<<endl;
              ans+=(tot-res);

           // cout<<curi<<" "<<curi+k-1<<" "<<i<<" "<<R1-rg+1<<" "<<dif1<<" "<<calL<<" "<<calR<<endl;



        }


    }

    cout<<ans<<endl;



}
