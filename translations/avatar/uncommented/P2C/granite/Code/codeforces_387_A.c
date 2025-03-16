
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char *h1_str = strtok(buf, ":");
    char *m1_str = strtok(NULL, ":");
    int h1 = atoi(h1_str);
    int m1 = atoi(m1_str);
    int m1_total = h1 * 60 + m1;
    fgets(buf, sizeof(buf), stdin);
    char *h2_str = strtok(buf, ":");
    char *m2_str = strtok(NULL, ":");
    int h2 = atoi(h2_str);
    int m2 = atoi(m2_str);
    int m2_total = h2 * 60 + m2;
    int m2_total_from_m1 = m1_total - m2_total;
    if (m2_total_from_m1 < 0) {
        m2_total_from_m1 += 1440;
    }
    int h2_from_m1 = m2_total_from_m1 / 60;
    int m2_from_m1 = m2_total_from_m1 % 60;
    printf("%02d:%02d\n", h2_from_m1, m2_from_m1);
    return 0;
}
