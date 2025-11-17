#include <stdbool.h>
#include <iostream>
using namespace std;

const int MAXN = 25;

int n, k, ans;
int arr[MAXN];
int path[MAXN];  // 选取路径

/**
 * @brief 快速判断一个数是否为素数
 * 
 * @param a 待判断的正整数
 * @return true 如果n是素数
 * @return false 如果n不是素数
 */
bool isPrime(int a) {
  if (a <= 1) return false;                    // 1. 处理小于等于1的数
  if (a <= 3) return true;                     // 2. 处理2和3
  if (a % 2 == 0 || a % 3 == 0) return false;  // 3. 处理能被2或3整除的数，这样做可以让我们后续的步长为6

  // 数学原理：所有大于3的素数都可以表示为6k±1的形式
  // 循环从5开始（即6*1-1），每次步长为6，这样可以同时检查6k-1和6k+1两种形式的数。
  for (int i = 5; i * i <= a; i += 6) {                // 4. 处理剩下的数，步长为6
    if (a % i == 0 || a % (i + 2) == 0) return false;  // 检查 i 和 i+2 是否是 n 的因子
  }

  return true;  // 5. 如果循环结束都没有找到因子，那么n是素数
}

/**
 * @brief 从数组中选取k个数
 * @param path_start 当前选取的路径索引
 * @param path_size 当前选取的路径长度
 * @param curr_sum 当前选取的路径和
 */
void dfs(int path_start, int path_size, int curr_sum) {
  if (path_size == k) {       // 选完
    if (isPrime(curr_sum)) {  // 是素数
      ans++;
    }
    // 打印路径和
    // for (int i = 0; i < path_size; i++) {
    //   cout << path[i] << "+";
    // }
    // cout << curr_sum << endl;

    return;
  }

  // 开始选
  for (int i = path_start; i < n; i++) {
		// 做选择：将当前元素arr[i]加入路径
    path[path_size] = arr[i];
    dfs(i + 1, path_size + 1, curr_sum + arr[i]);
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
	dfs(0, 0, 0);
  cout << ans << endl;
}