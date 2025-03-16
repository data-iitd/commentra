#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int FfriendPerDay[367]; // Array for female friends
    int MfriendPerDay[367]; // Array for male friends
    int answer = 0; // Variable to store the maximum number of friends present on any day
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (c == 'M')
                MfriendPerDay[j]++;
            else
                FfriendPerDay[j]++;
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                if (MfriendPerDay[j] > answer)
                    answer = MfriendPerDay[j];
            } else {
                if (FfriendPerDay[j] > answer)
                    answer = FfriendPerDay[j];
            }
        }
    }
    cout << answer * 2 << "\n";
    return 0;
}

