def main():
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        ai, bi = map(int, input().split())
        a.append(ai)
        b.append(bi)

    happy_alex = False
    for i in range(n):
        for j in range(n):
            if a[i] < a[j] and b[i] > b[j]:
                happy_alex = True
                break
        if happy_alex:
            break

    if happy_alex:
        print("Happy Alex")
    else:
        print("Poor Alex")


if __name__ == "__main__":
    main()
