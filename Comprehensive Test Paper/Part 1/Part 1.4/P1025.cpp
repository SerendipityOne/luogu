#include <math.h>
#include <iostream>
using namespace std;
int n, k;
int dp[205][10];  // dp[i][j]表示数字i分成j份的方案数

int main() {
  cin >> n >> k;

  // 初始化边界条件
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;  // 将i分成1份的方案数只有一种
    dp[i][i] = 1;  // 将i分成i份的方案数只有一种，全是1
  }

  // 动态规划求解
  /* 
		考虑将i分成j份的情况，可以分为两类：
			a) 至少有一个1的情况：
				如果我们确定有一个1，那么剩下的i-1要分成j-1份
				这种情况的分法数是dp[i-1][j-1]

			b) 所有数都大于1的情况：
				如果所有数都大于1，我们可以先给每个数分配1
				这样就分配了j个1，还剩下i-j要分成j份
				这种情况的分法数是dp[i-j][j]
	*/
  for (int i = 2; i <= n; i++) {
    int range = min(i, k);  // 分成j份，j不能比i大，j最多分成i份，且j也不能比k大，比k大没意义(题目要求最大分成k份)
    for (int j = 2; j <= range; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
    }
  }

  cout << dp[n][k] << endl;
}