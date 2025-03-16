def pow2(a):
    ret = 1
    for i in range(a):
        ret *= 2
    return ret

def count(hw, a, b):
    sum_count = 0
    for i in range(len(hw)):
        for j in range(len(hw[0])):
            if (a >> i) & 1 and (b >> j) & 1 and hw[i][j] == 1:
                sum_count += 1
    return sum_count

def main():
    h, w, k = map(int, input().split())
    hw = [[0] * w for _ in range(h)]
    for i in range(h):
        row = input().strip()
        for j in range(w):
            if row[j] == '#':
                hw[i][j] = 1

    sum_count = 0
    for i in range(pow2(h)):
        for j in range(pow2(w)):
            if count(hw, i, j) == k:
                sum_count += 1

    print(sum_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
