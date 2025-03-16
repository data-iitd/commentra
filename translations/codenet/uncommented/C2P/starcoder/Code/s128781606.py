A,B = map(int,input().split())
C = A+B
D = A-B
E = A*B
max = C
if max<D:
    max = D
if max<E:
    max = E
print(max)
#