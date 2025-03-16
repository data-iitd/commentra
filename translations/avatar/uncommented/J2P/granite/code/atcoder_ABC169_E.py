
import sys
import math
import bisect
import re
import heapq
from collections import deque
from collections import Counter
from functools import reduce
import itertools
import time
import string

def I(): return int(input())
def MI(): return map(int,input().split())
def LI(): return [int(i) for i in input().split()]
def LI_(): return [int(i)-1 for i in input().split()]
def StoI(): return [ord(i)-97 for i in input()]
def ItoS(nn): return chr(nn+97)
def LtoS(ls): return ''.join([chr(i+97) for i in ls])
def GI(V,E,Directed=False,index=0):
    org_inp=[]
    g=[[] for i in range(n)]
    for i in range(E):
        inp=LI()
        org_inp.append(inp)
        if index==0:
            a,b=inp[0]-1,inp[1]-1
            if not Directed:
                g[b].append(a)
            else:
                g[a].append(b)
        elif index==1:
            a,b=inp[0],inp[1]
            if not Directed:
                g[b].append(a)
            else:
                g[a].append(b)
        else:
            a,b=inp[0],inp[1]
            if not Directed:
                g[b].append(a)
            else:
                g[a].append(b)

    return g,org_inp

def bit_combination(k,n=2):
    rt=[]
    for tb in range(n**k):
        s=[tb//(n**bt)%n for bt in range(k)]
        rt+=[s]
    return rt

def show(*inp,end='\n'):
    if show_flg:
        print(*inp,end=end)

YN=['YES','NO']

mod=998244353
inf=float('inf')
l_alp=string.ascii_lowercase
u_alp=string.ascii_uppercase

#---------------------------------#

import math

def main():
    n=I()
    a=[I() for i in range(n)]
    b=[I() for i in range(n)]
    a.sort()
    b.sort()
    if n%2==1:
        ans=b[n//2]-a[n//2]+1
    else:
        ans=2*(b[n//2]+b[n//2-1]-a[n//2]-a[n//2-1]+1)//2+1
    print(ans)

if __name__ == '__main__':
    main()

