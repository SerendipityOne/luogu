#include <iostream>
using namespace std;
#define ll long long
ll m;
ll ll_fib, l_fib, fib;  // 分别为上上次，上次，当前
ll ans;

int main() {
  cin >> m;
  ll_fib = 0, l_fib = 1;
  ll range = ans = m * m;
  for (size_t i = 2; i <= range; i++) {
    fib = (ll_fib + l_fib) % m;
    if (l_fib == 0 && fib == 1) {
      ans = i - 1;
      break;
    }
    ll_fib = l_fib;
    l_fib = fib;
  }
  cout << ans << endl;
}
