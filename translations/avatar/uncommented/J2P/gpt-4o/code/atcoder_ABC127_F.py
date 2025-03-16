import sys
import heapq

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])
    pqmax = []  # max-heap (using negative values)
    pqmin = []  # min-heap
    sumMin = 0
    sumMax = 0
    sumb = 0
    min_val = 0
    
    results = []
    
    for i in range(1, t + 1):
        s = data[i].split()
        if s[0][0] == '2':
            ans = min_val * len(pqmin) - sumMin
            ans1 = min_val * len(pqmax)
            ans1 = sumMax - ans1
            results.append(f"{min_val} {ans + ans1 + sumb}")
        else:
            in_val = int(s[1])
            sumb += int(s[2])
            if in_val > min_val:
                heapq.heappush(pqmax, -in_val)  # push negative for max-heap
                sumMax += in_val
            else:
                heapq.heappush(pqmin, in_val)
                sumMin += in_val
            
            # Balance the heaps
            if len(pqmin) > len(pqmax):
                sumMax += pqmin[0]
                sumMin -= pqmin[0]
                heapq.heappush(pqmax, -heapq.heappop(pqmin))
            if len(pqmin) < len(pqmax):
                sumMax -= -pqmax[0]
                sumMin += -pqmax[0]
                heapq.heappush(pqmin, -heapq.heappop(pqmax))
            
            min_val = pqmin[0] if pqmin else 0
    
    print("\n".join(results))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
