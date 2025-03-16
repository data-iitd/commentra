
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    if (getenv("MASPY")) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2;
    }
    if (getenv("MASPYPY")) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    char buf[500001];
    fgets(buf, 500001, fp);
    char *token = strtok(buf, " ");
    int k = atoi(token);
    token = strtok(NULL, " ");
    int x = atoi(token);

    char *ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    fprintf(wfp, "%s\n", ans);

    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        fgets(buf, 500001, fp);
        token = strtok(buf, " ");
        k = atoi(token);
        token = strtok(NULL, " ");
        x = atoi(token);

        ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        fprintf(wfp, "%s\n", ans);
    }

    fclose(fp);
    fclose(wfp);

    return 0;
}
