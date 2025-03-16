
A, B, C, D, E, F = map(int, input().split())

m1 = 0
m2 = 0
maxD = 0.0
for i in range(0, F+1, 100*A):
    for j in range(0, F+1-i, 100*B):
        for k in range(0, F+1-i-j, C):
            for l in range(0, F+1-i-j-k, D):
                if (i + j) * E / 100 < l + k:
                    break
                d = (l + k) / (i + j + k + l)
                if d > maxD:
                    m1 = i + j + k + l
                    m2 = k + l
                    maxD = d

if m1 == 0:
    m1 = 100 * A

print(m1, m2)
