
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter;
    string timing;

    cin >> a >> tA >> b >> tB >> timing;

    stringstream ss(timing);
    ss >> hrs >> mins;

    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;

    for (int i = 300; i < 1440; i += b) {
        int busDeparture = i;
        int busArrival = i + tB;

        if (busDeparture >= simArrival || simDeparture >= busArrival) {
            continue;
        }
        counter++;
    }

    cout << counter << endl;

    return 0;
}

