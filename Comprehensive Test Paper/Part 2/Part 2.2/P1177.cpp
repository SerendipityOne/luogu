#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e5;
int n;
int a[MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}