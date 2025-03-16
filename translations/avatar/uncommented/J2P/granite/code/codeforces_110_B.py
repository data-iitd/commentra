
n = int(input())
c = [chr(97+i) for i in range(n)]
for i in range(4):
    for j in range(i,n,4):
        c[j] = chr(97+i)
print(''.join(c))
