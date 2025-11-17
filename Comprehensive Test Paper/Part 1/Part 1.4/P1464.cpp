#include <iostream>
using namespace std;

#define ll long long
ll a, b, c, ans;
ll vis[25][25][25];

ll w(ll a, ll b, ll c) {
  // 边界条件
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

  // 检查是否已经计算过
  if (vis[a][b][c] != 0) return vis[a][b][c];

  if (a < b && b < c) {
    vis[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  } else {
    vis[a][b][c] = w(a - 1, b, c) + w(a - 1, b, c - 1) + w(a - 1, b - 1, c) - w(a - 1, b - 1, c - 1);
  }

  return vis[a][b][c];
}

int main() {
  while (scanf("%lld%lld%lld", &a, &b, &c) && !(a == -1 && b == -1 && c == -1)) {
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
  }
}