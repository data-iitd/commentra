def linear_search(S, n, key):
    i = 0
    count = 0

    while S[i] != key:
        i += 1
        if i >= n:
            count = 1
            return count
    return 0

def main():
    n = int(input("Enter the size of the array S: "))
    S = []
    print(f"Enter {n} integers for array S:")
    for i in range(n):
        S.append(int(input(f"Enter integer S[{i}]: ")))

    q = int(input("Enter the number of queries: "))
    T = []
    print(f"Enter {q} integers for array T:")
    for j in range(q):
        T.append(int(input(f"Enter integer T[{j}]: ")))

    count = 0
    for j in range(q):
        key = T[j]
        if linear_search(S, n, key) == 1:
            count += 1

    print(f"Number of integers in array S that are not present in array T: {count}")

main()
