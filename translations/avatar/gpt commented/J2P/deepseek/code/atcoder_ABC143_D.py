def find(li, from_index, target):
    low = from_index
    upp = len(li) - 1
    
    if upp - low < 0:
        return 0
    if li[from_index] >= target:
        return 0
    if li[upp] < target:
        return upp - low + 1
    
    while upp - low > 1:
        mid = (low + upp) // 2
        if li[mid] >= target:
            upp = mid
        else:
            low = mid
    
    return low - from_index + 1

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    L = []
    
    for i in range(N):
        L.append(int(data[index]))
        index += 1
    
    L.sort()
    count = 0
    
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            res = find(L, j + 1, a + b)
            count += res
    
    print(count)

if __name__ == "__main__":
    main()
