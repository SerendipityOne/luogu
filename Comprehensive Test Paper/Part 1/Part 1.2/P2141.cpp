#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
int a[105];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      int t = a[i] - a[j];           // 另一个被加数
      bool flag = false;             //是否有被加数在集合中
      for (int k = 0; k < i; k++) {  //找被加数
        if (j == k) continue;
        if (t == a[k]) {
          flag = true;
          ans++;
          break;
        }
      }
      if (flag) break;
    }
  }

  cout << ans << endl;
  return 0;
}
