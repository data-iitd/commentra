def main():
    A = [0] * 100
    n = int(input())
    for i in range(n):
        A[i] = int(input())

    sw = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if A[j] < A[mini]:
                mini = j
        A[i], A[mini] = A[mini], A[i]
        if i != mini:
            sw += 1

    print(" ".join(map(str, A[:n])))
    print(sw)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
