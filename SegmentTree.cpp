#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+1;
int tree[4*mx];
int lazy[4*mx];
int a[mx];
const int INF=INT_MAX;

//building for RMQ
void build(int si,int ss,int se)
{

   if(ss==se)
   {
        tree[si]=a[ss];
        return;
   }

   int mid=(ss+se)/2;

   build(2*si,ss,mid);
   build(2*si+1,mid+1,se);

   tree[si]=tree[2*si]+tree[2*si+1];

}

int query(int si,int ss,int se,int qs,int qe)
{

     if(lazy[si]!=0)
     {

          //updating lazy things
          int dx=lazy[si];
          tree[si]+=(se-ss+1)*dx;
          lazy[si]=0;
          if(ss!=se)
          {
               lazy[si*2]+=dx;
               lazy[si*2+1]+=dx;
          }

     }
     if(ss>qe ||se<qs )
     {
          //completely outside
          //return something that will not effect our result
          return 0;
     }
     //another case is when completely inside
     if(ss>=qs && se<=qe)
     {
          return tree[si];
     }
     //somehting is touching here ,,call it again

  int mid=(ss+se)/2;
    return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe); //operation


}

  void update(int si,int ss,int se,int qs,int qe,int val)
  {
     if(lazy[si]!=0)
     {

          //updating lazy things
          tree[si]+=(se-ss+1)*val;
          lazy[si]=0;
          //things are you 
          if(ss!=se)
          {
               lazy[si*2]+=val;
               lazy[si*2+1]+=val;
          }

     }

       if(se<qs ||ss>qe) return;

     if(ss>=qs && se<=qe)
     {
          tree[si]+=(se-ss+1)*val;
          if(ss!=se)
          {
               lazy[si*2]+=val;
               lazy[si*2+1]+=val;
          }
          return ;

     }


    int mid=(ss+se)/2;
     update(si*2,ss,mid,qs,qe,val);
      update(si*2+1,mid+1,se,qs,qe,val);

     tree[si]=tree[si*2]+tree[si*2+1]; 
     //operation

  }


bool is_possible(int x,int *a,int *b,int n)
{

     for(int i=1;i<=4*n;i++)
     {
          tree[i]=0,lazy[i]=0;
     }

   for(int i=1;i<=n;i++)
   {
      int l=i-b[i];
      int r=i+b[i];
      update(1,1,n,max(l,1),min(r,n),a[i]);
   }


   for(int i=1;i<=n;i++)
  {
     int key=query(1,1,n,i,i);
     int Del=min(key,x);
     update(1,1,n,i,i,-1*Del);
  }

  for(int i=1;i<=n;i++)
  {
     int key=query(1,1,n,i,i);
     if(key>0)
     {
          return false;
     }

  }

  return true;


}

int main()
{


     int n;cin>>n;
      for(int i=1;i<=n;i++)
      {
           cin>>a[i];
      }
        build(1,1,n);
      int q;cin>>q;
      while(q--){
          int l,r;cin>>l>>r;

          cout<<query(1,1,n,l,r)<<endl;
         update(1,1,n,3,6,6);
      }


}
