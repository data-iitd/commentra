import sys

def main():
    n, d = map(int, sys.stdin.readline().split())
    nums = list(map(int, sys.stdin.readline().split()))
    
    result = 0
    for i in range(1, n):
        a = nums[i - 1] - nums[i]
        if a >= 0:
            result += (a + d - 1) // d
            nums[i] += ((a + d - 1) // d) * d
    
    print(result)

if __name__ == "__main__":
    main()
