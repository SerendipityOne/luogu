#include <iostream>
using namespace std;
#define MAX_SIZE 10005
int l, m;
int tree[MAX_SIZE];
int ans;
int main() {
  cin >> l >> m;
  for (int i = 0; i <= l; i++) {
    tree[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    for (int j = u; j <= v; j++) {
      tree[j] = 0;
    }
  }

  for (int i = 0; i <= l; i++) {
    if (tree[i] == 1) ans++;
  }
  cout << ans << endl;
}