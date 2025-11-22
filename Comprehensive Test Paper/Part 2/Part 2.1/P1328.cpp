#include <iostream>
using namespace std;
const int MAXN = 205;
int n, a, b;
int score[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0},
};  // score[i][j] = i对j的评分
int qa[MAXN], qb[MAXN];  // a,b的出拳记录
int score_a, score_b;    // a,b的得分

int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> qa[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> qb[i];
  }
	
  for (int i = 0; i < n; i++) {  // 猜拳轮数
    score_a += score[qa[i % a]][qb[i % b]];
    score_b += score[qb[i % b]][qa[i % a]];
  }
  cout << score_a << " " << score_b << endl;
}