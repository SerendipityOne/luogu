#include <iostream>
#define ll long long
using namespace std;
bool flag = false;  // 是否为负数
ll n, res;
int main(int argc, char const* argv[]) {
  cin >> n;
  while (n) {
    ll t = n % 10ll;  // 取出最后一位
    if (t < 0) {
      flag = true;
      t = -t;
    }
    res = res * 10 + t;
    n /= 10ll;
  }
	cout << (flag ? -res : res);
  return 0;
}
