
import sys

def main():
    S = input()

    l0, l1 = 0, 0
    for s in S:
        if s == '0':
            l0 += 1
        else:
            l1 += 1
    print(2 * min(l0, l1))

