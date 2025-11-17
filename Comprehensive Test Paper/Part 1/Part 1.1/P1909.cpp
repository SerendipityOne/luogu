#include <cmath>
#include <iostream>
using namespace std;

int res = 0x7fffffff, n;

int main() {
  cin >> n;
  int count, price;
  for (int i = 0; i < 3; i++) {
    cin >> count >> price;
    int bcnt = n / count;            // 买这种铅笔需要的包装个数
    bcnt += n % count == 0 ? 0 : 1;  // 只能多买，不能少买
    int money = bcnt * price;
    res = min(money, res);
  }
  cout << res << endl;
}