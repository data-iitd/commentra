
N = int(input())
values = list(map(float, input().split()))
values.sort()
generated = 0
for i in range(N-1):
    generated = (values[i] + values[i+1]) / 2
    values[i+1] = generated

print(generated)

