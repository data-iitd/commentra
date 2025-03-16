#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

def main(argc, argv):
    a, b = input().split()
    a, b = int(a), int(b)

    ans = 0
    if a >= 13:
        ans = b
    elif a >= 6:
        ans = b/2

    print(ans)

    return 0

