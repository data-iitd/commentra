
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int FfriendPerDay[367];
    int MfriendPerDay[367];
    int answer = 0;

    for (int i = 0; i < n; i++) {
        char c;
        int a, b;
        scanf("%c %d %d", &c, &a, &b);

        for (int j = a; j <= b; j++) {
            if (c == 'M')
                MfriendPerDay[j]++;
            else
                FfriendPerDay[j]++;

            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                if (MfriendPerDay[j] > answer)
                    answer = MfriendPerDay[j];
            } else {
                if (FfriendPerDay[j] > answer)
                    answer = FfriendPerDay[j];
            }
        }
    }

    printf("%d", answer * 2);

    return 0;
}

