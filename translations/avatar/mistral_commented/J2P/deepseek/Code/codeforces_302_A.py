def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    arr = list(map(int, data[2:n+2]))
    queries = []
    
    for i in range(n+2, len(data), 2):
        queries.append((int(data[i]), int(data[i+1])))
    
    o = arr.count(1)
    e = arr.count(0)
    
    result = []
    
    for l, r in queries:
        if (r - l + 1) % 2 == 1:
            result.append('0\n')
        else:
            if (r - l + 1) // 2 <= o:
                result.append('1\n')
            else:
                result.append('0\n')
    
    sys.stdout.write(''.join(result))


if __name__ == "__main__":
    main()
