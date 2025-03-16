mod = 1000000007

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    q = int(data[1])
    c = data[2]
    
    range_queries = []
    index = 3
    for _ in range(q):
        left = int(data[index])
        right = int(data[index + 1])
        range_queries.append((left, right))
        index += 2
    
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)
    
    for i in range(2, n + 1):
        if c[i - 2] == 'A' and c[i - 1] == 'C':
            frag[i] += 1
        rui[i] = rui[i - 1] + frag[i]
    
    for left, right in range_queries:
        print(rui[right] - rui[left])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
