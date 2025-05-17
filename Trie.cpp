#include <bits/stdc++.h>
using namespace std;
typedef struct MyType
{

     int we = 0;
     int prefix = 0;
     struct MyType *bit[31];
} NewType;
bool bit1(int n, int k)
{
     if (n & (1 << k))
          return true;
     else
          return false;
}

NewType *getNode()
{
     NewType *Newnode = new NewType;
     for (int i = 0; i < 31; i++)
     {
          Newnode->bit[i] = NULL;
     }

     return Newnode;
}

void append(int x, NewType *root)
{
     int sz = log2(x) + 1;
     for (int i = sz; i >= 0; i--)
     {
          int mask = (1 << i);
          if (bit1(x, i))
          {
               if (root->bit[i] == NULL)
               {
                    root->bit[i] = getNode();
               }

               root = root->bit[i];
               root->prefix++;
          }
     }

     root->we++;
}
void del(int x, NewType *root)
{

     int sz = log2(x) + 1;

     for (int i = sz; i >= 0; i--)
     {
          int mask = (1 << i);
          if (bit1(x, i))
          {
               root = root->bit[i];
               root->prefix--;
          }
     }

     root->we--;
}

int mx_possible(int x, NewType *root)
{
     int ans = x;
     for (int i = 30; i >= 0; i--)
     {
          int mask = (1 << i);
          if (!bit1(x, i))
          {
               // cout<<mask<<" "<<endl;
               if (root->bit[i] != NULL)
               {
                    ans += mask;
                    root = root->bit[i];
               }
          }
     }

     while (root->we < 1)
     {
          bool ok = false;
          for (int i = 0; i < 31; i++)
          {
               int mask = (1 << i);
               if (root->bit[i] != NULL)
               {
                    ok = true;
                    if (bit1(x, i))
                         ans -= mask;
                    else
                         ans += mask;
                    root = root->bit[i];
                    break;
               }
          }
          if (!ok)
          {
               break;
          }
     }
     if (root->we <= 0)
          ans = x;

     return max(ans, x);
}
int main()
{

     NewType *root = getNode();

     int n;
     cin >> n;
     char ch;
     int x;
     for (int i = 0; i < n; i++)
     {
          cin >> ch;
          cin >> x;
          if (ch == '+')
          {

               append(x, root);
          }
          else if (ch == '-')
          {

               del(x, root);
          }
          else
          {

               int ans = mx_possible(x, root);
               cout << ans << endl;
          }
     }

     return 0;
}
