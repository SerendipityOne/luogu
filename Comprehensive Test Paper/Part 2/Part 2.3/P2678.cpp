#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 50005;
int L, N, M;
int a[MAXN];

/**
 * 检查是否可以移除不超过M个石头，使得相邻石头间距至少为mid
 * @param mid 最小间距要求
 * @return bool 是否可以满足条件
 */
bool check(int mid) {
    int last = 0;     // 上一个保留的石头位置
    int removed = 0;  // 已移走的石头数量

    // 遍历所有石头
    for (int i = 0; i < N; i++) {
        // 如果当前石头与上一个保留的石头距离小于mid，则需要移除当前石头
        if (a[i] - last < mid) {
            removed++;
            // 如果已移除石头数超过M，提前返回false
            if (removed > M) return false;  // 提前终止
        } else {
            // 保留当前石头，更新上一个保留的石头位置
            last = a[i];
        }
    }

    // 终点判断可以合并到循环中
    // 检查最终移除的石头数是否不超过M
    return removed <= M;
}

int main() {
    ios::sync_with_stdio(false);  // 加速输入输出
    cin.tie(nullptr);

    cin >> L >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 优化二分范围
    int left = 1;
    int right = L / (N - M + 1);  // 优化上界
    int answer = 0;

    while (left <= right) {
        // 假设当前mid为最优最小距离最大化
        int mid = left + (right - left) / 2;  // 防止溢出
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
