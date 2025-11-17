#include <iostream>
using namespace std;

int a[105];
int len;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    a[len++] = t;
    cin >> t;
  }
	for(int i = len-1; i >= 0; i--){
		cout << a[i] << " ";
	}
}