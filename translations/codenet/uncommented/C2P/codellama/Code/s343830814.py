#include <stdio.h>
#include <string.h>

def main(argc, argv):
    buf = [0] * 512
    fgets(buf, sizeof(buf), stdin)
    len = strlen(buf)
    printf("%c%d%c\n", buf[0], len-3, buf[len-2])
    return 0

