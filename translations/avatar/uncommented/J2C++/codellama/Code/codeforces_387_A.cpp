
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    stringstream ss(s), tt(t);
    int h1, m1, h2, m2;
    ss >> h1 >> m1;
    tt >> h2 >> m2;
    tm time1, time2;
    time1.tm_hour = h1;
    time1.tm_min = m1;
    time2.tm_hour = h2;
    time2.tm_min = m2;
    time_t t1 = mktime(&time1);
    time_t t2 = mktime(&time2);
    time_t diff = difftime(t1, t2);
    int h = diff / 3600;
    int m = (diff - h * 3600) / 60;
    cout << h << ":" << m << endl;
    return 0;
}

