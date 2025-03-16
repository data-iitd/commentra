
import sys

N = int(sys.stdin.readline())
values = []
for i in range(N):
    values.append(float(sys.stdin.readline()))

values.sort()
generated = 0
for i in range(N-1):
    generated = (values[i] + values[i+1]) / 2
    values[i+1] = generated

print(generated)

