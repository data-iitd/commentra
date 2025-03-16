#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, tA, b, tB;
    char timing[6];
    int hrs, mins, simDeparture, simArrival;
    int counter = 0;

    scanf("%d %d", &a, &tA);
    scanf("%d %d", &b, &tB);
    scanf("%s", timing);

    hrs = (timing[0] - '0') * 10 + (timing[1] - '0');
    mins = (timing[3] - '0') * 10 + (timing[4] - '0');
    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;

    for (int i = 300; i < 1440; i += b) {
        int busDeparture = i;
        int busArrival = i + tB;
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue;
        counter++;
    }

    printf("%d\n", counter);
    return 0;
}
