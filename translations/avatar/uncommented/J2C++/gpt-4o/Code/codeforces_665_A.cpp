#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, tA, b, tB;
    cin >> a >> tA >> b >> tB;
    cin.ignore(); // To ignore the newline after the last integer input

    string timing;
    getline(cin, timing);
    
    int hrs = stoi(timing.substr(0, 2));
    int mins = stoi(timing.substr(3, 2));
    
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

// <END-OF-CODE>
