
#include <stdio.h>

int main() {
    char buf[1024];
    fgets(buf, 1024, stdin);
    printf("%s", buf);
    return 0;
}
// END-OF-CODE