#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 105;
const int MAX_NUM = 1e4 + 5;
int n;
int a[MAXN];
bool vis[MAX_NUM] = {false};
int cur;  // 不重复的个数
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (vis[x]) continue;  // 如果已经存在，则跳过
    a[++cur] = x;
    vis[x] = true;
  }
  sort(a + 1, a + cur + 1);
  cout << cur << endl;
  for (int i = 1; i <= cur; i++) cout << a[i] << " ";
}