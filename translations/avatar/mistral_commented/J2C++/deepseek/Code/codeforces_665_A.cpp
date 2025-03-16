#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
 int a, tA, b, tB;
 string timing;

 // Read the first line of input and parse the integers
 cin >> a >> tA;

 // Read the second line of input and parse the integers
 cin >> b >> tB;

 // Read the third line of input and parse the string
 cin >> timing;
 int hrs = stoi(timing.substr(0, 2));
 int mins = stoi(timing.substr(3));
 int simDeparture = hrs * 60 + mins;
 int simArrival = simDeparture + tA;

 int counter = 0;

 // Loop through the bus timings to find the number of buses that can accommodate students
 for (int i = 300; i < 1440; i += b) {
 int busDeparture = i;
 int busArrival = i + tB;

 if (busDeparture >= simArrival || simDeparture >= busArrival) {
 continue;
 }
 counter++;
 }

 // Write the output to the console
 cout << counter << endl;

 return 0;
}

