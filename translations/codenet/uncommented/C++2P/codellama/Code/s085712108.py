/*Lucky_Glass*/
import sys
from collections import deque

MOD = 7007

def hash(n):
    for i in range(len(Hash[n%MOD])):
        if n == Hash[n%MOD][i]:
            return False
    Hash[n%MOD].append(n)
    return True

def main():
    que = deque()
    que.append((Push.a, Push.b, Push.c, 0))
    while que:
        Fro = que.popleft()
        if Fro[0] == Fro[1] and Fro[1] == Fro[2]:
            print(Fro[3])
            return 0
        for i in range(6):
            Push = (Fro[0]+F[i][0], Fro[1]+F[i][1], Fro[2]+F[i][2], Fro[3]+1)
            n = Push[0]*10000+Push[1]*100+Push[2]
            if not hash(n):
                continue
            que.append(Push)
    return 0

F = ((1,1,0),(1,0,1),(0,1,1),(2,0,0),(0,2,0),(0,0,2))
Hash = [[] for i in range(MOD)]
Push = (0,0,0,0)
main()
