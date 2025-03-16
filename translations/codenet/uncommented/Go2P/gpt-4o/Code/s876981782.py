N = int(input())
values = [float(input()) for _ in range(N)]

values.sort()
generated = 0.0

for i in range(N - 1):
    generated = (values[i] + values[i + 1]) / 2
    values[i + 1] = generated

print(generated)
# <END-OF-CODE>
