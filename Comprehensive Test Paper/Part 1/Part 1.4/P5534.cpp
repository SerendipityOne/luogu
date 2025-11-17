#include <iostream>
using namespace std;
#define ll long long
ll a1, a2, n, an;
ll d;

int main() {
  cin >> a1 >> a2 >> n;
  d = a2 - a1;
  an = a1 + (n - 1) * d;
  cout << n * (a1 + an) / 2 << endl;
}