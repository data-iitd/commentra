
def merge(a, n, l, m, r):
    n1 = m - l
    n2 = r - m
    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)
    for i in range(n1):
        L[i] = a[l + i]
    for j in range(n2):
        R[j] = a[m + j]
    L[n1] = {"s": "Z", "v": 2000000000}
    R[n2] = {"s": "Z", "v": 2000000000}
    i = 0
    j = 0
    for k in range(l, r):
        if L[i]["v"] <= R[j]["v"]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def mergeSort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        mergeSort(a, n, l, m)
        mergeSort(a, n, m, r)
        merge(a, n, l, m, r)

def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j]["v"] <= x["v"]:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quickSort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quickSort(a, n, p, q - 1)
        quickSort(a, n, q + 1, r)

def main():
    n = int(input())
    a = []
    b = []
    for i in range(n):
        s, v = input().split()
        a.append({"s": s, "v": int(v)})
        b.append({"s": s, "v": int(v)})
    mergeSort(a, n, 0, n)
    quickSort(b, n, 0, n - 1)
    stable = True
    for i in range(n):
        if a[i]["s"]!= b[i]["s"]:
            stable = False
            break
    if stable:
        print("Stable")
    else:
        print("Not stable")
    for i in range(n):
        print(b[i]["s"], b[i]["v"])

if __name__ == "__main__":
    main()

