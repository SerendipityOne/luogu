#include <iostream>
using namespace std;
const int MAXN = 1e3 + 5;
int n;
int f[MAXN];  // 递推式：f[i] = 1 + f[0~n/2]的和

int main() {
  cin >> n;
  f[0] = 0;
  // 使用动态规划计算f[n]
  for (int i = 1; i <= n; i++) {
    f[i] = 1;  // 初始值为1
    // 累加f[0]到f[i/2]的值
    for (int k = 0; k <= i / 2; k++) {
      f[i] += f[k];
    }
  }
  cout << f[n] << endl;
}