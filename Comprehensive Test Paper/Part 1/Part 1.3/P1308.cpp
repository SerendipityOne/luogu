#include <cstring>
#include <iostream>
using namespace std;
string sub_s, s;
int count, first;
int main() {
  getline(cin, sub_s);
  getline(cin, s);
  // 全部转为大写
  for (int i = 0; i < sub_s.length(); i++) {
    sub_s[i] = toupper(sub_s[i]);
  }
  for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ')
      continue;
    string compare_str;
    while (i < s.length() && s[i] != ' ') {
      compare_str += s[i];
      i++;
    }
    // cout << "compare_str: " << compare_str << endl;
    if (sub_s == compare_str) {  // 匹配成功
      count++;
      if (count == 1) {
        first = i - sub_s.length();
      }
    }
  }
  if (count == 0) {
    cout << -1 << endl;
  } else {
    cout << count << " " << first << endl;
  }
}