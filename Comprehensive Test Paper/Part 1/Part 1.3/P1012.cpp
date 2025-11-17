#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n;
string nums[25];

/*
2 和 19 ，比较 2 和 19 哪个放在前面使字典序最大，也就是即比较 219 和 192
哪个大，因为 219 比 192 大，所以把 2 放在 19 前面
*/

// 比较字符串拼接后根据字典顺序排序（升序）
int cmp(string a, string b) {
  return a + b > b + a;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums, nums + n, cmp);
  for (int i = 0; i < n; i++) {
    cout << nums[i];
  }
}