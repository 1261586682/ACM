#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=10;
const int M=1005;
int n;
int xid[N][N];
int yid[N][N];
int mapp[N][N];
int v[M],first[M],ext[M],num,sum,like[M],p[M];
bool vis[M];
void add(int x,int y)
{
    v[++num]=y;
    ext[num]=first[x];
    first[x]=num;
}
bool scc(int x)
{
    for(int i=first[x]; ~i; i=ext[i])
    {
        int k=v[i];
        if(!vis[k])
        {
            vis[k]=true;
            if(!p[k]||scc(p[k]))
            {
                p[k]=x;
                like[x]=k;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(cin>>n&&n)
    {
        num=sum=0;
        memset(like,0,sizeof(like));
        memset(first,-1,sizeof(first));
        memset(p,0,sizeof(p));
        memset(mapp,0,sizeof(mapp));
        memset(xid,0,sizeof(xid));
        memset(yid,0,sizeof(yid));
        char c;
        int l;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
            {
                cin>>c;
                if(c=='X')
                    mapp[i][j]=1;
            }
        int cnt=0;
        for(int i=1; i<=n; ++i)
        {
            cnt++;
            for(int j=1; j<=n; ++j)
            {
                if(mapp[i][j])
                {
                    cnt++;
                    continue;
                }
                xid[i][j]=cnt;
            }
        }
        l=cnt;
        for(int i=1; i<=n; ++i)
        {
            cnt++;
            for(int j=1; j<=n; ++j)
            {
                if(mapp[j][i])
                {
                    cnt++;
                    continue;
                }
                yid[j][i]=cnt;
            }
        }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
            {
                if(xid[i][j]&&yid[i][j])
                    add(xid[i][j],yid[i][j]);
            }
        for(int i=1; i<=l; ++i)
        {
            memset(vis,0,sizeof(vis));
            if(scc(i))
            {
                sum++;
            }
        }

        cout<<sum<<endl;
    }
    return 0;
}
//hdu1045
//??????????????????????????????????????????????????????????????????????????????????????????
//
//1.?????????????????????????????????????????????????????????????????????xid??????????????????????????????yid???
//
//2.??????a[x][y]???????????????????????????xid[x][y]??????yid[x][y]???????????????????????????????????????[x][y]????????????????????????????????????xid[x][y]??????yid[x][y]????????????????????????????????????????????????????????????????????????????????????
//
//3.??????????????????????????????x?????????y??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
