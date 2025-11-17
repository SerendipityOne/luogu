#include <iostream>
using namespace std;

// jm表示当前的钱，mm表示妈妈手上的前
int jm, mm;

int main(int argc, char const* argv[]) {
  for (int i = 1; i <= 12; i++) {  // 12个月
    int ys;
    cin >> ys;     // 每个月的预算
    jm += 300;     // 拿钱
    jm -= ys;      //扣除预算
    if (jm < 0) {  // 钱不够
      printf("-%d", i);
      return 0;
    }
    int temp = (jm / 100) * 100;  //要存在妈妈那的钱
    mm += temp;
    jm -= temp;
  }
  cout << jm + mm * 1.2 << endl;

  return 0;
}
