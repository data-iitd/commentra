#include <iostream>
#include <string>

def check(x, y):
    if y % 2 == 0:
        t = int(y/2) - x
        if t >= 0 and (x-t) >= 0:
            return "Yes"
    return "No"

x, y = map(int, input().split())
print(check(x, y))

