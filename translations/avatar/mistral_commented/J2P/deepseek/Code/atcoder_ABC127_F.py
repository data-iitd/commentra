import sys
import heapq

def main():
    input = sys.stdin.readline
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
            ans1 = sumMax - ans1
            print(min_val, ans + ans1 + sumb)
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
                top = -heapq.heappop(pqmin)
                heapq.heappush(pqmax, top)
                sumMax += top
                sumMin -= top
            elif len(pqmin) < len(pqmax):
                top = heapq.heappop(pqmax)
                heapq.heappush(pqmin, -top)
                sumMin += top
                sumMax -= top

            min_val = -pqmin[0]

if __name__ == "__main__":
    main()

