#include <iostream>
using namespace std;
const int MAXN = 100005;

typedef struct {
  int x, y, xl, yl;  // 左下角坐标和长宽
} Carpets;           // 存储所有地毯信息

Carpets carpets[MAXN];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> carpets[i].x >> carpets[i].y >> carpets[i].xl >> carpets[i].yl;
  }
  int x, y;
  cin >> x >> y;  // 检查坐标是否在任意地毯内
  for (int i = n; i >= 1; i--) {
    if (x >= carpets[i].x && x <= carpets[i].x + carpets[i].xl && y >= carpets[i].y && y <= carpets[i].y + carpets[i].yl) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
