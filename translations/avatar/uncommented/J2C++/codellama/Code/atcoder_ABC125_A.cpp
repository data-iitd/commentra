#include <iostream>
using namespace std;
int main() {
    int sec, per_num, max_sec, ans_num;
    cin >> sec >> per_num >> max_sec;
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    cout << ans_num << endl;
    return 0;
}
