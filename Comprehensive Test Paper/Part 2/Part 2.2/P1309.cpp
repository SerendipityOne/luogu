#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 2 * (1e5 + 5);
int n, r, q;

typedef struct {
    int num;    // 编号
    int score;  // 分数
    int power;  // 实力值
} Player;

bool cmp(Player& a, Player& b) {
    if (a.score == b.score) return a.num < b.num;
    return a.score > b.score;
}

// 胜者组跟败者组，这两组内部已经有序，只需要进行归并即可
Player p[MAXN], win[MAXN], lose[MAXN];

int main() {
    cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; i++) {
        p[i].num = i;
        cin >> p[i].score;
    }
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i].power;
    }

    sort(p + 1, p + 2 * n + 1, cmp);

    // R轮比赛
    while (r--) {
        int wcnt = 0, lcnt = 0;
        for (int i = 1; i <= 2 * n; i += 2) {
            if (p[i].power > p[i + 1].power) {
                p[i].score++;
                win[++wcnt] = p[i];
                lose[++lcnt] = p[i + 1];
            } else {
                p[i + 1].score++;
                win[++wcnt] = p[i + 1];
                lose[++lcnt] = p[i];
            }
        }
        merge(win + 1, win + wcnt + 1, lose + 1, lose + lcnt + 1, p + 1, cmp);
    }
    cout << p[q].num << endl;
}