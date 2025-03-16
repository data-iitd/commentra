import sys

def main():
    N = int(sys.stdin.readline())
    nums = []
    map = {}
    for i in range(N):
        num = int(sys.stdin.readline())
        nums.append(num)
        map[num] = i
    bin = 0
    diff = 0
    while len(nums) > 0:
        num = nums.pop(0)
        idx = map[num]
        if (bin % 2) != (idx % 2):
            diff += 1
        bin += 1
        bin %= 2
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()

