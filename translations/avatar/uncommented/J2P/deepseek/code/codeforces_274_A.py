import sys

def main():
    n = int(input().strip())
    k = int(input().strip())
    arr = list(map(int, input().strip().split()))
    arr.sort()
    count = 0
    seen = set()
    
    for num in arr:
        if num % k != 0 and num not in seen:
            count += 1
            seen.add(num)
        elif num % k == 0 and num // k not in seen:
            count += 1
            seen.add(num)
    
    print(count)

if __name__ == "__main__":
    main()
