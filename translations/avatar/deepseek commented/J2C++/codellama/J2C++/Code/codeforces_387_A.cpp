
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    string s, t;
    getline(cin, s);
    getline(cin, t);
    stringstream ss(s), st(t);
    int h1, m1, h2, m2;
    ss >> h1 >> m1;
    st >> h2 >> m2;
    tm x = {0}, y = {0};
    x.tm_hour = h1;
    x.tm_min = m1;
    y.tm_hour = h2;
    y.tm_min = m2;

    // Step 2: Calculate the difference between the two times
    tm z = {0};
    z.tm_hour = x.tm_hour - y.tm_hour;
    z.tm_min = x.tm_min - y.tm_min;
    if (z.tm_min < 0) {
        z.tm_hour--;
        z.tm_min += 60;
    }
    cout << setfill('0') << setw(2) << z.tm_hour << ":" << setfill('0') << setw(2) << z.tm_min << endl;

    return 0;
}

