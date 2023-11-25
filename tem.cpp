#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &p1 ,const pair<int ,int> &p2)
{
    if(p1.first>p2.first) return true;
    else if(p1.first==p2.first) return (p1.second<p2.second);
    return false;
}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
//integer to string to_string(num)
///call korte hbe function
///BFS
/*
void bfs(vector<vector<int>>v,int n,int source)
{
    //vector<vector<int>>v(n+1);
    queue<int>q;
    vector<int>leve(n+1,-1);
    q.push(source);
    leve[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x:v[u])
        {
            if(leve[x]==-1)
            {
                leve[x]=leve[u]+1;
                q.push(x);

            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        cout<<leve[j]<<endl;
    }

}
    cout<<"Enter node"<<endl;
    cin>>n;
    vector<vector<int>>v(n+1);
    cout<<"Enter edge"<<endl;
    cin>>m;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(v,n,6);
    return 0;

*/
///string substringh = s1.substr(fhpos1,ehpos1+1 - fhpos1);
///int timeh1=stoi(substringh);
/// 2DBFS
/*

#include<bits/stdc++.h>
using namespace std;
pair<int,int>s;
pair<int,int>d;
int n,m;
string grid[100];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool isvalid(int x,int y)
{
    return x<n && x>=0 && y<m && y>=0 && grid[x][y]!='#';
}
int main()
{
    int i,j;
    cin>>n>>m;
    //grid = vector<string>grid(n);
    int level[100][100];
     memset(level,-1,sizeof(level));
    //level[s.first][s.second]=0;
    queue<pair<int,int>>q;
    //q.push(s);
    for(i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    for(i=0;i<n;i++)
    {
       // cin>>grid[i];
        for(j=0;j<m;j++)
        {
            if(grid[i][j]=='S')
            {
                s.first=i;
                s.second=j;
                level[s.first][s.second]=0;
                q.push(s);
            }
            if(grid[i][j]=='D')
            {
                d.first=i;
                d.second=j;
            }
        }
    }


    while(!q.empty())
    {
        pair<int,int>u;
        u=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            pair<int,int>v={u.first+dx[i],u.second+dy[i]};
            if(isvalid(v.first,v.second) && level[v.first][v.second]==-1)
            {
                level[v.first][v.second]=level[u.first][u.second]+1;
                q.push(v);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<level[i][j]<<" ";
        }
        cout<<endl;
    }

  return 0;


}

*/
///STACK diye DFS
/*
#include<bits/stdc++.h>
using namespace std;
int const mx=10000;
vector<int>adj[mx];
bool vis[mx];
stack<int>st;
int main()
{

    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    /// adjacent gula dekhi
    cout<<"ADjacent gula dekhi"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"NODE....."<<i<<"    ";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    st.push(1);
    while(!st.empty())
    {
         cout<<st.top()<<" ";
         vis[st.top()]=1;
         int y=st.top();
         st.pop();
         for(auto x:adj[y])
         {

            if(vis[x]==0)
            {
             st.push(x);

            }
         }
    }


















    return 0;
}




*/
///GRID theke matrix er path ninoy by dfs
/*
#include<bits/stdc++.h>
using namespace std;
int const mx=1000+123;
int grid[mx][mx];
int vis[mx][mx];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int result;
int n,m;
bool isvalid(int a,int b)
{
    return a<=n && a>=1 && b<=m && b>=1 && grid[a][b]!=0;
}
int dfs(int i,int j)
{
    int k,x,y;
    vis[i][j]=1;
    result=result+grid[i][j];
    for(k=0;k<4;k++)
    {
        x=i+dx[k];
        y=j+dy[k];
        if(vis[x][y]==-1 && isvalid(x,y))
        {

            dfs(x,y);
        }
    }
    return result;
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
       int i,j;
       cin>>n>>m;
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               cin>>grid[i][j];
           }
       }
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               vis[i][j]=-1;
           }
       }
       int ans=0;
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               if(vis[i][j]==-1 && grid[i][j]!=0)
               {
                   result=0;
                   ans=max(ans,dfs(i,j));
               }
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}

*/
/// Dijstra algoridth
/*

#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>adj[10010];
int const mx=1e5+123;
int const max1=100000000;;
long long dis[mx],i;
int j,tt;
int path[10010];
map<int,pair<long long,long long>>mp;
void dst(long long s,long long n)
{
    pair<long long,long long>sc;
    sc.first=0;
    sc.second=s;
    dis[s]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    pq.push(sc);
    while(!pq.empty())
    {
        int u,curD;
        u=pq.top().second;
        curD=pq.top().first;
        pq.pop();
        for(auto x:adj[u])
        {
            int v,w;
            v=x.first;
            w=x.second;
            if(w+curD<dis[v])
            {   path[v]=u;
                dis[v]=w+curD;
                pq.push({w+curD,v});
            }
        }

    }
    for(i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }


}

int main()
{
   // cin>>tt;

   tt=1;
    for(j=1;j<=tt;j++)
    {
    int n,m;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    for(i=0;i<=n;i++)
    {
        dis[i]=max1;
    }
    dst(1,n);
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
    }

    }
    return 0;
}


*/
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {

    }
    return 0;
}

