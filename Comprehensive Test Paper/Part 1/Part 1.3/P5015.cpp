#include <iostream>
using namespace std;
char s[10];
int len, ans;
int main() {
  char c;
  while (true) {
    c = getchar();  // 读取一个字符
    if (c == '\n') break;
    s[len++] = c;
  }
  for (int i = 0; i < len; i++) {
    if (s[i] == ' ' || s[i] == '\n') continue;
    ans++;
  }
  cout << ans;
}