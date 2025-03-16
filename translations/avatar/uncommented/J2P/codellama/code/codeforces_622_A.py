
import sys
import math

BUFFERSIZE = 512000

sc = sys.stdin
out = sys.stdout

def solve():
    position = sc.nextLong()
    nrstSeqStartIndx = 1
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1
    startIndex = getValueAtIndex(nrstSeqStartIndx)
    out.println((position - startIndex) + 1)

def getValueAtIndex(index):
    return 1 + ((index - 1) * index / 2)

solve()
out.close()

