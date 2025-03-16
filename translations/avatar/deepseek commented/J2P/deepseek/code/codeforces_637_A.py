def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    ara = [int(x) for x in data[1:n+1]]
    map_count = {}
    
    for v in ara:
        if v not in map_count:
            map_count[v] = 1
        else:
            map_count[v] += 1
    
    max_count = max(map_count.values())
    map_freq = {}
    
    for i, v in enumerate(ara):
        if v not in map_freq:
            map_freq[v] = 1
            if map_freq[v] == max_count:
                print(v)
                break
        else:
            map_freq[v] += 1
            if map_freq[v] == max_count:
                print(v)
                break

if __name__ == "__main__":
    main()
