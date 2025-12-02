#include <iostream>
using namespace std;
#define ll long long
const int MAXN = (1e5 + 2) * 5;
int n;
int a[MAXN];
int temp[MAXN];  // 临时数组用于归并（从小到大）
ll ans;

/**
 * 归并排序函数，同时统计逆序对数量
 * @param l 排序区间的左边界
 * @param r 排序区间的右边界
 */
void merge_sort(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    // 左半部分起始、右半部分起始和临时数组的当前位置
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            ans += mid - i + 1;  // 统计逆序对
        }
    }

    // 将剩余的元素复制到临时数组中
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int i = l; i <= r; i++) a[i] = temp[i];  // 将临时数组中的有序元素部分复制回原数组
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(0, n - 1);
    cout << ans << endl;
    return 0;
}
