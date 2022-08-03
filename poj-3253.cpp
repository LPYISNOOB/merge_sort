/*
问题描述：
农民约翰想修复牧场周围的一小段围栏。他测量了围栏，发现他需要N（1≤N≤20，000）木板，
每块都有一些整数长度的Li（1≤Li ≤50，000）单位。
然后，他购买了一块足够长的长板，足以锯入N块木板（即，其长度是长度Li的总和）。FJ忽略了“割缝”，
即在进行锯切时锯末损失的额外长度;你也应该忽略它。
FJ悲伤地意识到他没有一把锯子来切割木材，所以他用这块长板来到农夫唐的农场，礼貌地问他是否可以借用锯子。
农夫唐，一个壁橱资本家，没有借给FJ一把锯子，而是提出向农夫约翰收取每块N-1切割木板的费用。
切割一块木头的电荷正好等于其长度。切割一块长度为21的木板需要花费21美分。

然后，农民唐让农民约翰决定切割木板的顺序和位置。帮助农民约翰确定他可以花在制作N块木板上的最小金额。
FJ知道他可以按照各种不同的顺序切割板，这将导致不同的电荷，因为产生的中间板材具有不同的长度。
*
求解思路：贪心算法+哈夫曼树 
（1）首先读取木板数量和每块木板的长度 
（2）每次先找到最短的两块木板 
（3）将他们合并，再重新放到队列中，选取最短的两块合并，重复上述过程 
（4）每次合并将长度叠加，直到所有木板合并成一块 
	   
*
提交状态：AC
*
AC结果：
288K	532MS
*
出错次数：
1、2次
错误结果：

测试数据的范围不准确认知，对数据的范围和特殊值把握不准

*/
#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int t=a;
	a = b;
	b = t;
}
const int MAX_N = 60000;
typedef long long ll;
int N,L[MAX_N];
void solve(){
	ll ans = 0;
	while(N>1){
		//找到最短和次短的短板 
		int min1 = 0,min2 = 1;
		if(L[min1] > L[min2]) swap(min1,min2);
		for(int i=2;i<N;i++)
			if(L[i] < L[min1]){
				min2 = min1;
				min1 = i;
			} 
			else if(L[i] < L[min2]){
				min2 = i;
			}
		//合并木板 
		int t = L[min1] + L[min2];
		ans += t;
		 
		if(min1 == N-1) swap(min1,min2);
		L[min1] = t;
		L[min2] = L[N-1];
		N--;
	}
	cout << ans << endl;
}
int main()
{
	while(cin >> N){
		for(int i=0;i<N;i++)
			cin >> L[i];
		solve();
	}
	return 0;
}















































