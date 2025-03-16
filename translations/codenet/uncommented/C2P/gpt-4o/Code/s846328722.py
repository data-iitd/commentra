def linersearch(a, n, key):
    a.append(key)  # Append the key to the end of the list

    i = 0
    while a[i] != key:
        i += 1

    return i != n  # Return True if the key was found, False otherwise

def main():
    n = int(input())
    s = list(map(int, input().split()))  # Read n integers into a list

    q = int(input())
    count = 0

    for _ in range(q):
        t = int(input())
        if linersearch(s, n, t):
            count += 1

    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
