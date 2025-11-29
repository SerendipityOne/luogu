#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int MAXN = 105;

typedef struct {
    int id;  // 出现的先后编号
    string name;
    int qimo_score;   // 期末平均成绩
    int class_score;  // 班级评议成绩
    char stu_ganbu;   // 是否是学生干部'Y'/'N'
    char west;        // 是否是西部省份学生'Y'/'N'
    int essay;        // 论文篇数
    ll money;         // 获得的奖学金
} Student;

bool cmp(Student& a, Student& b) {
    if (a.money == b.money) return a.id < b.id;
    return a.money > b.money;
}

Student stu[MAXN];
ll total_money;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        stu[i].id = i;
        cin >> stu[i].name >> stu[i].qimo_score >> stu[i].class_score >> stu[i].stu_ganbu >> stu[i].west >> stu[i].essay;

        if (stu[i].qimo_score > 80 && stu[i].essay >= 1) stu[i].money += 8000;
        if (stu[i].qimo_score > 85 && stu[i].class_score > 80) stu[i].money += 4000;
        if (stu[i].qimo_score > 90) stu[i].money += 2000;
        if (stu[i].qimo_score > 85 && stu[i].west == 'Y') stu[i].money += 1000;
        if (stu[i].class_score > 80 && stu[i].stu_ganbu == 'Y') stu[i].money += 850;

        total_money += stu[i].money;
    }

    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl
         << stu[0].money << endl
         << total_money << endl;
}