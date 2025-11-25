#include <iostream>
using namespace std;
const int MAXN = 40;
int n;
int a[MAXN][MAXN];

int main() {
  cin >> n;
  a[0][n / 2] = 1;  // 首先将 1 写在第一行的中间

  int last_x = 0, last_y = n / 2;  // last_x 和 last_y 表示上一个数的位置
  for (int i = 2; i <= n * n; i++) {
    // 若 (K−1) 在第一行但不在最后一列，则将 K 填在最后一行， (K−1) 所在列的右一列；
    if (last_x == 0 && last_y != n - 1) {
      a[n - 1][last_y + 1] = i;
      last_x = n - 1, last_y = last_y + 1;
    }
    // 若 (K−1) 在最后一列但不在第一行，则将 K 填在第一列， (K−1) 所在行的上一行；
    else if (last_y == n - 1 && last_x != 0) {
      a[last_x - 1][0] = i;
      last_x = last_x - 1, last_y = 0;
    }
    // 若 (K−1) 在第一行最后一列，则将 K 填在 (K−1) 的正下方；
    else if (last_x == 0 && last_y == n - 1) {
      a[last_x + 1][last_y] = i;
      last_x = last_x + 1;
    }
    // 若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数，则将 K 填在 (K−1) 的右上方，否则将 K 填在 (K−1) 的正下方。
    else if (last_x != 0 && last_y != n - 1) {
      if (a[last_x - 1][last_y + 1] == 0) {
        a[last_x - 1][last_y + 1] = i;
        last_x = last_x - 1, last_y = last_y + 1;
      } else {
        a[last_x + 1][last_y] = i;
        last_x = last_x + 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}