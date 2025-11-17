#include <iostream>
using namespace std;

int n;

int main(int argc, char const* argv[]) {
  cin >> n;
  int row = 1;  // n所在行数
  int i = 1;
  int index = 1;  // 第row行开始的编号
  while (index < n) {
    index += i++;
    row++;
  }
  if (index > n) {
    index -= --i;
    row--;
  }
  /*
	行数为奇数，分子递增，分母递减，行数为偶数则相反
	*/
  int cnt = n - index;  //在这行第几个，从0开始
  int a = 1 + cnt, b = row - cnt;
  if (row % 2 == 0)
    printf("%d/%d", a, b);
  else
    printf("%d/%d", b, a);
  return 0;
}
