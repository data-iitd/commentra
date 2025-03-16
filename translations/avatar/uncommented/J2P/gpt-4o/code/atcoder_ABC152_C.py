import heapq

def solve():
    N = int(input())
    arr = list(map(int, input().split()))
    sum_count = 0
    q = []
    
    for i in range(len(arr)):
        heapq.heappush(q, arr[i])
        if arr[i] <= q[0]:
            sum_count += 1
            
    return sum_count

if __name__ == "__main__":
    print(solve())

# <END-OF-CODE>
