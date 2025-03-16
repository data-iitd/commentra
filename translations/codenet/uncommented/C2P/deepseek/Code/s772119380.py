def bubble_sort(a, n):
    d = 0
    for i in range(n):
        for j in range(n-1, i, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                d += 1
    return a, d

def main():
    n = int(input())
    a = list(map(int, input().split()))
    sorted_a, d = bubble_sort(a, n)
    print(" ".join(map(str, sorted_a)))
    print(d)

if __name__ == "__main__":
    main()
