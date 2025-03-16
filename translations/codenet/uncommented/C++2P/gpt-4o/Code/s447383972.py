def read():
    return int(input().strip())

def writeln(x):
    print(x)

N = 200010
a = [0] * N
q = [0] * N
n = read()
tot = 0

for i in range(1, n + 1):
    a[i] = read()

a[1:n + 1] = sorted(a[1:n + 1])

i = 1
while i <= n:
    if a[i] == a[i + 1]:
        q[tot + 1] = a[i]
        tot += 1
        i += 1
    i += 1

writeln(q[tot] * q[tot - 1])

# <END-OF-CODE>
