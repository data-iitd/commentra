mod = 1000000007

def main():
    n, q = map(int, input().split())
    c = input()
    range_queries = [list(map(int, input().split())) for _ in range(q)]
    
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)
    
    for i in range(1, n):
        if c[i - 1] == 'A' and c[i] == 'C':
            frag[i + 1] = 1
        rui[i + 1] = rui[i] + frag[i + 1]
    
    for left, right in range_queries:
        print(rui[right] - rui[left])

if __name__ == "__main__":
    main()
