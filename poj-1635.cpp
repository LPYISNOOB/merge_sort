/*
����������
һЩ��Ҫ���������εĵ���ϵͳ�������κ�һ�Գ�վ֮�䣬��һ��Ҳ��ֻ��һ�ֵ�����ʽ��
���⣬��Щ�����еĴ��������һ�����ص����복վ������һ�£�������Щ����֮һ���οͣ�
����̽�����еĵ���ϵͳ��������복վ��ʼ�����ѡ��һ�������ߣ�Ȼ�����ϵ������ᡣ
ÿ�ε��ﳵվʱ��������ѡ��һ����δ��ʻ�ĵ�����·�������ǰ��վû��ʣ���̽���ռ䣬
�����Գ�����������ﳵվ�ĵ�����·��ֱ������������������·��ʻ���Σ�ÿ������һ�Ρ�
��ʱ�������������복վ��֮�����̽��˳��ļ�����������κθ���ʱ���������복վ��Զ���ǳ������복վ��
������Խ�������б���Ϊ�������ַ���������0�����ȡ�����ߣ�ʹ�������복վ��Զ��1�������������복վ����һ����վ��
����ĵ�һ���ǵ���������n������Ҫ��ѭ�Ĳ��Գ�����������
ÿ�����Գ�����������ɣ�ÿ�ж������������Ϊ 3000 ���ַ���0���͡�1���ַ�����
���߶������˵�����ϵͳ����ȷ̽��֮�á�
*
���˼·��ͬ�������ж� 
��1������solve(int l,int r)����������01������������ʽ����
��2������ÿ��·���ڵ㱣����vector�У� ��cnt==0ʱ��Ϊ �ػظýڵ㣬Ȼ��ݹ� 
��3����vector�е�Ԫ���������򣬹����µı�ʾ���������õ��µı��봮
��4���Ƚ����������±��봮�� 
*
�ύ״̬��AC
*
AC�����
596K	360MS
*
����������
1��2 �� 
��������
��ʱ 

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define next ne
using namespace std;
typedef long long ll;
int INF=1e9+7;
int n,ans,maxlen;
char s[10010];

string solve(int l,int r)
{
    vector<string> v;
    int cnt=0,p=l;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='0')
            cnt++;
        else
            cnt--;
        if(cnt==0)
        {
            v.push_back(solve(p+1,i-1));    //���������»ص���ǰ�ڵ�͵ݹ��������ڵ�
            p=i+1;
        }
    }
    sort(v.begin(),v.end());    //���ڵ㰴��������
    string re="0";
    for(int i=0;i<(int)v.size();i++)    //�����µı�ʾ����
        re=re+v[i];
    return re+"1";
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l;
        scanf(" %s",s);
        l=strlen(s);
        string a=solve(0,l-1);
        scanf(" %s",s);
        l=strlen(s);
        string b=solve(0,l-1);
        if(a==b)
            printf("same\n");
        else
            printf("different\n");
    }
}