#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long a[200],dp[200][5];
//sta=0 �� sta=1 ��һλ��5 sta=2 ��һλ��52 sta=3 ��520��
long long dfs(long long pos,long long before,long long doing)//pos��λ������1��ʼ���λ��before��ǰһλ�Ƿ�Ϊ6  1/0  doing�������Ƿ����� 0/1
{
    long long ans=0,s,i;//ans�����������ֵĸ�����
    if(pos==0)//�ܵ���λ����ʱ��ÿ�����ַ��������Ļ�����1����
        return before==3;
    if((!doing)&&dp[pos][before]!=-1)//�������� ������ͬ״̬�������Ѿ�����ˣ�
        return dp[pos][before];
    s=doing?a[pos]:9;//�����ж�
    for(i=0; i<=s; i++)
    {
        long long nowsta;
        if(before==3)
            nowsta=3;
        else if(i==5)
            nowsta=1;
        else if(before==1&&i==2)
            nowsta=2;
        else if(before==2&&i==0)
            nowsta=3;
        else
            nowsta=0;
        ans+=dfs(pos-1,nowsta,doing&&i==s);
    }
    if(!doing)//����������������м��䡣
        dp[pos][before]=ans;//ÿ������ֳ����࣬һ����ǰ��Ϊ6�ģ���һ��Ϊǰ�治Ϊ6�ġ�����1~100����λ����0~9��Ϊ���֣�һ��ǰ��Ϊ6��Ϊdp[pos][before]=8������λ���䲻��2Ҳ����4������10-2=8��,��һ��Ϊ��������Ϊ9��������4����
    return ans;
}
long long solve(long long n)
{
    long long len=0;
    memset(a,0,sizeof(a));
    while(n)
    {
        a[++len]=n%10;
        n/=10;
    }//�����������ֵ�λ�����ӵ�һλ��ʼ���棬100->a[1]=0,a[2]=0,a[3]=1;
    return dfs(len,0,1);
}
int main()
{
    long long t;
    scanf("%lld",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",solve(n)-solve(1));
    }
}
//���ϴ�ѧ��ʮ�Ľ�ACM F��Find the AFei Numbers��
//ţ�ͣ�https://ac.nowcoder.com/acm/contest/338#question��
