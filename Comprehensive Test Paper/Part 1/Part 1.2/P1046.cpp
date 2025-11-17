#include <iostream>
using namespace std;
int pg[10];
int h, ans;

int main() {
  for (int i = 0; i < 10; i++) {
    cin >> pg[i];
  }
  cin >> h;
  h += 30;
  for (int i = 0; i < 10; i++) {
    if (pg[i] - h <= 0) ans++;
  }
  cout << ans << endl;
}