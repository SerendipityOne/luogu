#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double a, b, c, d;

// 计算函数值
double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

// 二分法寻找根
double findRoot(double left, double right) {
    while (right - left > 0.001) {  // 精度要求
        double mid = (left + right) / 2;
        if (f(left) * f(mid) <= 0) {  // 如果在区间[left, mid]内有根
            right = mid;
        } else {
            left = mid;
        }
    }
    return (left + right) / 2;
}

int main() {
    cin >> a >> b >> c >> d;

    // 遍历可能存在根的区间
    for (double x = -100; x <= 100; x += 1) {
        double x1 = x;
        double x2 = x + 1;

        // 如果在区间[x1, x2]内有根
        if (f(x1) == 0) {  // 如果x1是根直接输出
            cout << fixed << setprecision(2) << x1 << " ";
        }
        if (f(x1) * f(x2) < 0) {
            double root = findRoot(x1, x2);
            cout << fixed << setprecision(2) << root << " ";
        }
    }

    // 检查最后一个点x=100
    if (f(100) == 0) {
        cout << fixed << setprecision(2) << 100.00;
    }

    return 0;
}
