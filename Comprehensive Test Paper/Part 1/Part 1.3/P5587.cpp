#include <iostream>
using namespace std;
const int MAXN = 1e4 + 5;

string essays[MAXN], s[MAXN], input;  // 范文，比对的字符串组
int e_len;                            // essay总行数
int s_len;                            // 打字的总行数
int right_num = 0;                    // 跟范文对应上的词的个数

int main() {
  // 范文
  while (getline(cin, input), input != "EOF") {
    e_len++;
    for (char c : input) {  // 遍历每一个字符
      if (c == '<') {
        if (!essays[e_len].empty()) essays[e_len].pop_back();  // 遇到<时，弹出最后一个字符
      } else {
        essays[e_len].push_back(c);
      }
    }
  }

  // 打字
  while (getline(cin, input), input != "EOF") {
    if (++s_len > e_len) break;  // 超出范文长度，结束
    for (char c : input) {       // 遍历每一个字符
      if (c == '<') {
        if (!s[s_len].empty()) s[s_len].pop_back();  // 遇到<时，弹出最后一个字符
      } else {
        s[s_len].push_back(c);
      }
    }

    // 比对该行跟范文的对应词
    for (int i = 0; i < min(essays[s_len].length(), s[s_len].length()); i++) {
      right_num += (essays[s_len][i] == s[s_len][i]);  // 跟范文对应上的词的个数
    }
  }

  int time = 0;
  cin >> time;                                             // 输入时间(s)
  // double time_in_min = time / 60.0;                        // 时间换算成分
  // cout << (int)((right_num / time_in_min) + 0.5) << endl;  // 输出每分钟跟范文对应上的词的个数
	cout << (int)(right_num * 60.0 / time + 0.5) << endl;  // 输出每分钟跟范文对应上的词的个数
}