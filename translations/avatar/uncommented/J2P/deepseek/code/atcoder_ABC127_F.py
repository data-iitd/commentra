import sys
import heapq

input = sys.stdin.readline
print = sys.stdout.write

def main():
    t = int(input())
    pqmax = []
    pqmin = []
    sumMin = 0
    sumMax = 0
    sumb = 0
    min_val = 0
    
    for _ in range(t):
        s = input().split()
        if s[0][0] == '2':
            ans = min_val
            ans *= len(pqmin)
            ans -= sumMin
            ans1 = min_val
            ans1 *= len(pqmax)
            ans1 = sumMax - ans1
            print(f"{min_val} {ans + ans1 + sumb}\n")
        else:
            in_val = int(s[1])
            sumb += int(s[2])
            if in_val > min_val:
                heapq.heappush(pqmax, in_val)
                sumMax += in_val
            else:
                heapq.heappush(pqmin, -in_val)
                sumMin += in_val
            if len(pqmin) > len(pqmax):
                heapq.heappush(pqmax, -heapq.heappop(pqmin))
                sumMax += heapq.heappop(pqmax)
                sumMin -= heapq.heappop(pqmax)
            if len(pqmin) < len(pqmax):
                heapq.heappush(pqmin, -heapq.heappop(pqmax))
                sumMin += heapq.heappop(pqmin)
                sumMax -= heapq.heappop(pqmin)
            min_val = -pqmin[0]

if __name__ == "__main__":
    main()
