#include <stdio.h>
#include <string.h>

def main(argc, argv):
    s = input()

    for j in range(len(s)):
        for i in range(len(s)):
            if (i != j) and (s[i] == s[j]):
                print("no")
                return 0

    print("yes")

    return 0

