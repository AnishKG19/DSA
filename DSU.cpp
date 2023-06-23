#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define lp(i, a, b) for (ll i = a; i <= b; i++)

class DisjointSet
{
  vector<int> rank, parent ,size;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUparent(int node)
  {
    if (node == parent[node])
    {
      return node;
    }

    return parent[node] = findUparent(parent[node]);
  }

  void UnioinByRank(int u, int v)
  {
    int ulp_u = findUparent(u);
    int ulp_v = findUparent(v);
    if (ulp_u == ulp_v)
      return;

    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
  void UnionBySize(int u ,int v){
    int ulp_u = findUparent(u);
    int ulp_v = findUparent(v);
    if(ulp_u == ulp_v ) return;

    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];

    }
    else{
       parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];

    }
    
  }

};

void solve()
{
 
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif

  DisjointSet ds(7);
  ds.UnioinByRank(1,2);
  ds.UnioinByRank(2,3);
  ds.UnioinByRank(4,5);
  ds.UnioinByRank(6,7);
  ds.UnioinByRank(5,6);
  ds.UnioinByRank(1,3);
  if(ds.findUparent(3) == ds.findUparent(7)){
    cout<<"Same"<<"\n";
  }
  else{
    cout<<"Not Same"<<"\n";
  }
  ds.UnionBySize(3,7);
  if(ds.findUparent(3) == ds.findUparent(7)){
    cout<<"Same"<<"\n";
  }
  else{
    cout<<"Not Same"<<"\n";

  }
  return 0;


  // ll t;
  // cin >> t;
  // while (t--)
  // {
  //   solve();
  // }
  // return 0;
}