import heapq

def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    sum_ = 0
    heap = []
    for i in range(n):
        heapq.heappush(heap, arr[i])
        if arr[i] <= heap[0]:
            sum_ += 1
    return sum_

if __name__ == "__main__":
    print(solve())
