#include <iostream>
using namespace std;
int n, a;
int main() {
  cin >> n;
  for (int i = n; i >= 0; i--) {
    cin >> a;
    if (a) {
      if (i != n && a > 0) cout << "+";    // 非最高项，且系数为正
      if (i > 0) {                         // 非常数项
        if (a != 1 && a != -1) cout << a;  // 系数不为正负1
        if (a == -1) cout << "-";          // 系数为-1
        if (i > 1) cout << "x^" << i;
        if (i == 1) cout << "x";
      } else {  // 常数项
        cout << a;
      }
    }
  }
}