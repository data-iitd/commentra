#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 int a, tA, b, tB;
 char timing[6];
 int hrs, mins, simDeparture, simArrival, counter = 0;

 // Read the first line of input and parse the integers
 scanf("%d %d", &a, &tA);

 // Read the second line of input and parse the integers
 scanf("%d %d", &b, &tB);

 // Read the third line of input and parse the string
 scanf("%s", timing);
 hrs = atoi(timing);
 mins = atoi(timing + 3);
 simDeparture = hrs * 60 + mins;
 simArrival = simDeparture + tA;

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
 printf("%d\n", counter);

 return 0;
}
