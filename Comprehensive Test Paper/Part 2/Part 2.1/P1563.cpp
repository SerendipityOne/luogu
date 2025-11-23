#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m;
string s[MAXN];  // 角色
int a[MAXN];     // 朝向

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> s[i];
  }

  int cur = 0;  // 当前位置
  int aa, ss;   // 朝向，人数
  for (int i = 0; i < m; i++) {
    cin >> aa >> ss;
    if (aa) {  // 向右
      if (a[cur]) {
        cur = cur + n - ss;
      } else {
        cur += ss;
      }
    } else {         // 向左
      if (a[cur]) {  // 朝向圈外，顺逆时针
        cur = cur + ss;
      } else {  // 朝向圈内，顺时针
        cur = cur + n - ss;
      }
    }
    cur %= n;
  }
  cout << s[cur] << endl;
}