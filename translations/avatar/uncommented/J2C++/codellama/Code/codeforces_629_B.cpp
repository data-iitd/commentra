#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    int FfriendPerDay[367];
    int MfriendPerDay[367];
    int answer = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        for (int j = a; j <= b; j++) {
            if (c == 'M') MfriendPerDay[j]++;
            else FfriendPerDay[j]++;
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                if (MfriendPerDay[j] > answer) answer = MfriendPerDay[j];
            } else {
                if (FfriendPerDay[j] > answer) answer = FfriendPerDay[j];
            }
        }
    }
    cout << answer * 2 << endl;
    return 0;
}
