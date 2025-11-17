#include <iostream>
using namespace std;
double sn;
int k;
int main(int argc, char const* argv[]) {
  cin >> k;
  int n = 0;
  while (sn <= k) {
    sn += 1.0 / ++n;
  }
  cout << n;
  return 0;
}
