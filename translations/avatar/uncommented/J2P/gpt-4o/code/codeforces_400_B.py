def main():
    n = int(input())
    m = int(input())
    arrs = [input() for _ in range(n)]
    length = []
    returnDex = 0

    for tmp in arrs:
        dexG = tmp.find("G")
        dexS = tmp.find("S")
        if dexG > dexS:
            returnDex = -1
        length.append(dexS - dexG)

    unique_lengths = set(length)

    if returnDex == -1:
        print(returnDex)
    else:
        print(len(unique_lengths))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
