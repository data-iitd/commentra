import sys
import heapq

def main():
    X, Y, Z, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    
    A.sort(reverse=True)
    B.sort(reverse=True)
    C.sort(reverse=True)
    
    AB = []
    for a in A:
        for b in B:
            heapq.heappush(AB, -(a + b))
    
    AB = [-heapq.heappop(AB) for _ in range(min(K, len(AB)))]
    
    ABC = []
    for ab in AB:
        for c in C:
            heapq.heappush(ABC, -(ab + c))
    
    ABC = [-heapq.heappop(ABC) for _ in range(K)]
    
    for abc in ABC:
        print(abc)

if __name__ == "__main__":
    main()
