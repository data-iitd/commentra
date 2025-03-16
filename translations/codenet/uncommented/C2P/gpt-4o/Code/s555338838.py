def main():
    len = int(input())
    a = list(map(int, input().split()))

    for j in range(1, len):
        print(" ".join(map(str, a)))
        key = a[j]
        i = j - 1
        while i >= 0 and a[i] > key:
            a[i + 1] = a[i]
            i -= 1
        a[i + 1] = key

    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
