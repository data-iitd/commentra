def scan_array_int():
    return list(map(int, input().split()))

def main():
    arr = scan_array_int()
    a, b = arr[0], arr[1]
    tap = 0
    consent = 1
    while consent < b:
        consent += a - 1
        tap += 1
    print(tap)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
