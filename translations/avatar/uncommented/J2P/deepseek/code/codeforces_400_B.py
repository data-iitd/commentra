def main():
    n, m = map(int, input().split())
    arrs = [input().strip() for _ in range(n)]
    length = []
    
    for tmp in arrs:
        dexG = tmp.find("G")
        dexS = tmp.find("S")
        if dexG > dexS:
            print(-1)
            return
        length.append(dexS - dexG)
    
    unique_lengths = set(length)
    print(len(unique_lengths))

if __name__ == "__main__":
    main()
