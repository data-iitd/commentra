
import sys
import collections

def main():
    n = int(raw_input())
    ara = [int(raw_input()) for i in range(n)]
    map = collections.defaultdict(int)
    for i in range(n):
        v = int(raw_input())
        ara[i] = v
        if v not in map:
            map[v] = 1
        else:
            map[v] += 1
    max = 0
    for i in map.values():
        max = max(max, i)
    mm = collections.defaultdict(int)
    for i in range(n):
        if ara[i] not in mm:
            mm[ara[i]] = 1
            if mm[ara[i]] == max:
                print ara[i]
                return
        else:
            mm[ara[i]] += 1
            if mm[ara[i]] == max:
                print ara[i]
                return

if __name__ == "__main__":
    main()

