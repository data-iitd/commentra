def main():
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if p[j] < p[min_index]:
                min_index = j
        if min_index != i:
            p[i], p[min_index] = p[min_index], p[i]
    
    o = sum(p[:k])
    print(o)

if __name__ == "__main__":
    main()
