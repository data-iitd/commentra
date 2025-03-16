#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    int n;
    fscanf(fp, "%d", &n);

    char *ans = "second";
    for (int i = 0; i < n; i++) {
        int a;
        fscanf(fp, "%d", &a);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    
    fprintf(wfp, "%s\n", ans);

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
