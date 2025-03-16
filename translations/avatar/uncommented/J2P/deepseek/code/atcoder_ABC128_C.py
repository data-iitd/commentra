def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    M = int(data[index + 1])
    index += 2
    
    a = [0] * N
    switches = []
    
    for i in range(N):
        switches.append([])
    
    for i in range(M):
        k = int(data[index])
        index += 1
        for j in range(k):
            s = int(data[index]) - 1
            index += 1
            switches[s].append(i)
    
    p = 0
    for i in range(M):
        x = int(data[index])
        index += 1
        p |= (x << i)
    
    ans = 0
    for s in range(1 << N):
        t = 0
        for i in range(N):
            if (s >> i) & 1:
                for switch in switches[i]:
                    t ^= (1 << switch)
        if p == t:
            ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()
