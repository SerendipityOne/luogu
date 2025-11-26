#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 5e4 + 5;

typedef struct {
  int k;  // 报名号
  int s;  // 成绩
} player;

int n, m;
player p[MAXN];

bool cmp(player a, player b) {
  if (a.s == b.s) return a.k < b.k;
  return a.s > b.s;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].k >> p[i].s;
  }
  sort(p + 1, p + n + 1, cmp);
  m = (int)(m * 1.5);

  int score_line = p[m].s;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (p[i].s >= score_line)
      cnt++;
    else
      break;
  }
  cout << score_line << " " << cnt << endl;
  for (int i = 1; i <= cnt; i++) cout << p[i].k << " " << p[i].s << endl;
}