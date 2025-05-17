#include<bits/stdc++.h>
#define  int  long long
using namespace std;

const int maxn =1e6+3;
const int mx=2e5+2;
int K, ans[mx], a[mx], sum;

struct Query{
    int index, L, R;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
};
int cnt[maxn];
//You should overwrite just add and remove function ...
//hence i am using zero based indexing ,after taking L and R input,they should be decremented
//n,q highest 10^5 otherwise TLE
void add(int idx){
   // sum+=a[index];
     int k=a[idx];
   cnt[k]++;

      if(cnt[k]==1)sum++;

}

void remove(int idx){
  //  sum-=a[index];
  int k=a[idx];

  cnt[k]--;
     if(cnt[k]==0)sum--;
 // if(cnt[a[idx]]==0)sum--;
}
inline  void  in( int  &x){scanf("%I64d",&x);}
  inline void outN(int & x){printf("%I64d\n",x);}
  inline void outS(int &x){printf("%I64d ",x);}

signed  main(){

   /* ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);*/
    int n,q;
     //in(n),in(q);
   cin>>n;

    K = sqrt(n);

    for(int i=0;i<n;i++){
    // in(a[i]);
   cin>>a[i];
    }


     int x,y;
        vector<Query>query;
        cin>>q;
    for(int i=0;i<q;i++){
        // in(x),in(y);
         cin>>x>>y;
         query.push_back({i,--x,--y});

    }
    sort(query.begin(), query.end());
    int L=0, R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = sum;
    }
    for(int i=0;i<q;i++){
     cout << ans[i] << "\n";
    // outN(ans[i]);
    }
    return 0;
}
