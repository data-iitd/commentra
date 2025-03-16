
# <START-OF-CODE>
n = int(input())
c = [chr(i) for i in range(97,97+n)]
for i in range(0,n,4):
    c[i:i+4] = [chr(i) for i in range(97,97+4)]
print(''.join(c))
# 