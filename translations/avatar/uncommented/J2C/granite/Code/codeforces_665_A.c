
#include <stdio.h>
#include <string.h>

int main() {
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter, i, busDeparture, busArrival;
    char timing[5];
    scanf("%d %d %d %d %s", &a, &tA, &b, &tB, timing);
    hrs = (timing[0] - '0') * 10 + (timing[1] - '0');
    mins = (timing[3] - '0') * 10 + (timing[4] - '0');
    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;
    counter = 0;
    for (i = 300; i < 1440; i += b) {
        busDeparture = i;
        busArrival = i + tB;
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue;
        counter++;
    }
    printf("%d\n", counter);
    return 0;
}
//END-OF-CODE