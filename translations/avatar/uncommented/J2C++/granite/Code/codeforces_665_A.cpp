
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int a, tA;
    ss >> a >> tA;
    getline(cin, line);
    ss.clear();
    ss.str(line);
    int b, tB;
    ss >> b >> tB;
    getline(cin, line);
    int hrs = (line[0] - '0') * 10 + (line[1] - '0');
    int mins = (line[3] - '0') * 10 + (line[4] - '0');
    int simDeparture = hrs * 60 + mins;
    int simArrival = simDeparture + tA;
    int counter = 0;
    for (int i = 300; i < 1440; i += b) {
        int busDeparture = i;
        int busArrival = i + tB;
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue;
        counter++;
    }
    cout << counter << endl;
    return 0;
}
//END-OF-CODE