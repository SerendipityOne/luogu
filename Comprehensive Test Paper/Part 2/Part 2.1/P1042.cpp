#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
string s;

void func(int score) {
  int WC = 0, LC = 0;
  for (int i = 0; i < s.length(); i++) {
		if(s[i] == 'W') WC++;
		if(s[i] == 'L') LC++;
    if ((WC >= score || LC >= score) && (abs(WC - LC) >= 2)) {
      printf("%d:%d\n", WC, LC);
      WC = 0;
      LC = 0;
    }
  }
  printf("%d:%d\n", WC, LC);  // 输出最后一局
}

int main() {
  char c;
  while (cin >> c && c != 'E') {
    s += c;
  }
  func(11);
  printf("\n");
  func(21);
}
