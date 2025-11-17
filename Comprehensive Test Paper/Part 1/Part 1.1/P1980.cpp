#include <iostream>
using namespace std;
int n, x;
int res;

void func(int num) {
  while (num) {
    int t = num % 10;
    if (t == x) {
      res++;
    }
    num /= 10;
  }
}

int main(int argc, char const* argv[]) {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    func(i);
  }
  cout << res;
  return 0;
}
