#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[20],dp[20][2];
int dfs(int pos,int before,int doing)//pos��λ������1��ʼ���λ��before��ǰһλ�Ƿ�Ϊ6  1/0  doing�������Ƿ����� 0/1
{
    int ans=0,s,i;//ans�����������ֵĸ�����
    if(pos==0)//�ܵ���λ����ʱ��ÿ�����ַ��������Ļ�����1����
        return 1;
    if((!doing)&&dp[pos][before]!=-1)//�������� ������ͬ״̬�������Ѿ�����ˣ�
        return dp[pos][before];
    s=doing?a[pos]:9;//�����ж�
    for(i=0; i<=s; i++)
    {
        if(i==4||i==2&&before)//�����λ����4��������һλΪ6���ұ�λΪ2��Ҳ����4��62�����������ٽ������µ�������
            continue ;
        ans+=dfs(pos-1,i==6,doing&&i==s);//������
    }
    if(!doing)//����������������м��䡣
            dp[pos][before]=ans;//ÿ������ֳ����࣬һ����ǰ��Ϊ6�ģ���һ��Ϊǰ�治Ϊ6�ġ�����1~100����λ����0~9��Ϊ���֣�һ��ǰ��Ϊ6��Ϊdp[pos][before]=8������λ���䲻��2Ҳ����4������10-2=8��,��һ��Ϊ��������Ϊ9��������4����
    return ans;
}
int solve(int n)
{
    int len=0;
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
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(m)-solve(n-1));//���ض�Ӧ������Ч���ָ�����
    }
    return 0;
}
//HDU 2089