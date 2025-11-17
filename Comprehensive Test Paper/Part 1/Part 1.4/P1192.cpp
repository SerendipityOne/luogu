#include <iostream>
using namespace std;
#define ll  long long
#define MOD 100003
const int MAXN = 100005;
ll n, k;
ll fib[MAXN];

int main() {
  cin >> n >> k;
  fib[1] = 1;                     // 走上台阶1就一种方法
  for (int i = 2; i <= k; i++) {  // 根据规律发现，走2到k台阶的方法数都是2^(i-1)
    fib[i] = 1;
    for (int j = 0; j < i - 1; j++) {  // 这里不用pow函数是因为pow函数会爆精度，数值太大
      fib[i] *= 2;
      fib[i] %= MOD;
    }
  }
  for (int i = k + 1; i <= n; i++) {  // 走k+1到n台阶的方法数都是前k个台阶的方法数之和
    fib[i] = 0;
    for (int j = 1; j <= k; j++) {
      fib[i] += fib[i - j];
    }
    fib[i] %= MOD;
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << fib[i] << " ";
  // }
  cout << fib[n] << endl;
}