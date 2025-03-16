
import sys
import math

# Global instance of input reader
inp = sys.stdin

# Global constants
mod = 1000000007

# Global variables

# <START-OF-CODE>
week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
s = input()
index = -1
for i, day in enumerate(week):
    if s == day:
        index = i
        break

print(7 - index)
# 