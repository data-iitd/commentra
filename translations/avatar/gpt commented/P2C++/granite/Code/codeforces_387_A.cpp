
#include <iostream>
#include <string>

using namespace std;

int main() {
    string time1, time2;
    cin >> time1 >> time2;

    int h1 = stoi(time1.substr(0, 2));
    int m1 = stoi(time1.substr(3, 2));
    int h2 = stoi(time2.substr(0, 2));
    int m2 = stoi(time2.substr(3, 2));

    int m2_total = (h1 * 60 + m1) - (h2 * 60 + m2);
    m2_total %= 1440;

    cout << setfill('0') << setw(2) << m2_total / 60 << ":" << setfill('0') << setw(2) << m2_total % 60 << endl;

    return 0;
}

