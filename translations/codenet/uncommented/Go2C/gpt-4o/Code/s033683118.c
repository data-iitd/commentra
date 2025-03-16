#include <stdio.h>
#include <stdlib.h>

void solve(FILE *fp, FILE *wfp) {
    int k, x;
    fscanf(fp, "%d %d", &k, &x);

    const char *ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    fprintf(wfp, "%s\n", ans);
}

int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2;
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    solve(fp, wfp);
    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        solve(fp, wfp);
    }

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);
    
    return 0;
}

// <END-OF-CODE>
