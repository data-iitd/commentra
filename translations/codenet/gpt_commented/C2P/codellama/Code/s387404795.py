#include <stdio.h>
#include <string.h>

int main(void) {
    # Declare character arrays for input strings and temporary storage
    str = input("Enter a string: ")
    p = input("Enter a pattern: ")
    tmp = str
    str += tmp
    slen = len(str)
    plen = len(p)
    flag = 0
    for i in range(0, slen - plen):
        if str[i:i+plen] == p:
            flag = 1
    if flag:
        print("Yes")
    else:
        print("No")
    return 0
}

