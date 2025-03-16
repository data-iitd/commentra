
import sys

in = list(map(int, sys.stdin.readline().split()))
in.sort()

print(in[2]*10 + in[1] + in[0])

