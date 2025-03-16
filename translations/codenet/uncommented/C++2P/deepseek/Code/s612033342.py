def pow2(a):
    ret = 1
    for _ in range(a):
        ret *= 2
    return ret

def count(hw, a, b):
    sum = 0
    for i in range(len(hw)):
        for j in range(len(hw[0])):
            if (a & (1 << i) and b & (1 << j) and hw[i][j] == 1):
                sum += 1
    return sum

def main():
    h, w, k = map(int, input().split())
    hw = [[0] * w for _ in range(h)]
    for i in range(h):
        row = input()
        for j in range(w):
            if row[j] == '#':
                hw[i][j] = 1
    sum = 0
    for i in range(pow2(h)):
        for j in range(pow2(w)):
            if count(hw, i, j) == k:
                sum += 1
    print(sum)

main()
