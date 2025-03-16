
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, at, b, bt, t1, t2, st, fin, now, ans;
    string s;

    // Read input
    cin >> a >> at >> b >> bt >> s;

    // Convert time string to minutes
    t1 = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));

    // Calculate start and finish times
    st = t2 + (t1 - 5) * 60;
    fin = st + at;

    // Initialize now and ans
    now = 0;
    ans = 0;

    // Loop until now is less than fin and now is less than 1140
    while (now < fin && now < 1140) {
        if (now + bt > st) {  // Check if adding bt to now would exceed the start time
            ans++;  // Increment ans if the condition is met
        }
        now += b;  // Increment now by b
    }

    // Print the final value of ans
    cout << ans << endl;

    return 0;
}
