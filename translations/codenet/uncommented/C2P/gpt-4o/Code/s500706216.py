def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    light = [0] * (n + 2)

    for i in range(n):
        r = i - a[i]
        l = i + a[i]
        light[max(0, r)] += 1
        light[min(n + 1, l + 1)] -= 1

    for _ in range(k):
        sum_light = 0
        tmpa = a[:]
        for j in range(n):
            sum_light += light[j]
            a[j] = sum_light

        for j in range(n):
            r = j - tmpa[j]
            l = j + tmpa[j]
            light[max(0, r)] -= 1
            light[min(n + 1, l + 1)] += 1
            r = j - a[j]
            l = j + a[j]
            light[max(0, r)] += 1
            light[min(n + 1, l + 1)] -= 1

        is_same = all(a[j] == a[j + 1] for j in range(n - 1))
        if is_same and a[0] == n:
            break

    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()
# <END-OF-CODE>
