
import sys

T = int(raw_input())
S = int(raw_input())
q = int(raw_input())

previous = S
answer = 0

while previous < T:
    answer += 1
    previous *= q

print answer

#