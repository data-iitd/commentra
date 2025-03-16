
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter;
 char timing[10];
 scanf("%d %d %d %d %s", &a, &tA, &b, &tB, timing);
 hrs = atoi(timing);
 mins = atoi(timing + 3);
 simDeparture = hrs * 60 + mins;
 simArrival = simDeparture + tA;
 counter = 0;
 for (int i = 300; i < 1440; i += b) {
 int busDeparture = i;
 int busArrival = i + tB;
 if (busDeparture >= simArrival || simDeparture >= busArrival) {
 continue;
 }
 counter++;
 }
 printf("%d\n", counter);
 return 0;
}

