#include <iostream>
using namespace std;
int n, m, k;
int a[1005][1005];
int ans[1005];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int j = 0; j < m; j++) {  //按列遍历，当day出现在不同列，则安排的模拟场次数+1
    bool flag[1005] = {false};   //a[i][j]这天是否在这一列已经出现过
    for (int i = 0; i < n; i++) {
      if (!flag[a[i][j]]) {  // a[i][j]这天在这列还没出现过
        ans[a[i][j]]++;
        flag[a[i][j]] = true;
      }
    }
  }
	for(int i = 1; i <= k; i++){
		cout << ans[i] << " ";
	}
}