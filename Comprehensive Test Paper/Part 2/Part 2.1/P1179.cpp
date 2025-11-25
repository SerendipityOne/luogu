#include <iostream>
using namespace std;
int l, r;
int ans;

void f(int n) {
  while (n) {
    if (n % 10 == 2) ans++;
    n /= 10;
  }
}

int main() {
  cin >> l >> r;
  for (int i = l; i <= r; i++) f(i);
  cout << ans;
}