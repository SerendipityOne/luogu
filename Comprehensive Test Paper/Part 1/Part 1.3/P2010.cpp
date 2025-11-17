#include <iostream>
using namespace std;
int start_date, end_date;
int ans;
// 是否是闰年
bool is_leap(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return true;
  return false;
}

bool is_real_date(int date) {
  int year = date / 10000;
  int month = date / 100 % 100;
  int day = date % 100;
  if (month <= 0 || month > 12) return false;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    if (day > 31) return false;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) return false;
  }

  if (is_leap(year)) {
    if (month == 2 && day > 29) return false;
  } else {
    if (month == 2 && day > 28) return false;
  }
  return true;
}

int main() {
  cin >> start_date >> end_date;

  int start_year = start_date / 10000;
  int end_year = end_date / 10000;
  for (int year = start_year; year <= end_year; year++) {
    int temp_num = year;
    int temp = year;

    while (temp) {
      int t = temp % 10;
      temp_num *= 10;
      temp_num += t;
      temp /= 10;
    }
    if (is_real_date(temp_num)) {
      int temp_year = temp_num / 10000;
      int temp_month = temp_num / 100 % 100;
      int temp_day = temp_num % 100;
      int end_month = end_date / 100 % 100;
      int end_day = temp_num % 100;
      if (temp_year == end_year) {
        if (temp_month > end_month || temp_day > end_day) continue;
      }
      // cout << temp_num << " ";
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
