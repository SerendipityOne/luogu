#include <iostream>
using namespace std;
int t1, t2;  // t1表示上课时间， t2表示补习时间
int unhappy, unhappy_day;
int main(int argc, char const* argv[]) {
  for (int i = 1; i <= 7; i++) {
    cin >> t1 >> t2;
    int time = t1 + t2;
    if (time > 8 && unhappy < time) {
      unhappy = time;
      unhappy_day = i;
    }
  }
  cout << unhappy_day;
  return 0;
}
