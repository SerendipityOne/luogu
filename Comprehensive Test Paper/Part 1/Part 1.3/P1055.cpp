#include <iostream>
using namespace std;
char s[20];
int len = 13, _cnt;
int count;
int sum;
int main() {
  char c;
  for (int i = 0; i < len; i++) {
    cin >> c;
    s[i] = c;
  }
  for (int i = 0; i < len; i++) {
    if (s[i] == '-') {
      _cnt++;
      if (_cnt == 3) break;
      continue;
    }
    sum += (s[i] - '0') * ++count;
  }
  int t = sum % 11;
  if (t == 10)
    c = 'X';
  else
    c = t + '0';
  if (s[len - 1] == c)
    cout << "Right" << endl;
  else {
    s[len - 1] = c;
    cout << s << endl;
  }
}