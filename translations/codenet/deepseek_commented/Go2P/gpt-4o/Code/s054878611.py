def solution(n, a):
    memo = [0] * (int(1e5) + 2)
    for num in a:
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1
    
    out = 0
    for count in memo:
        if count > 0:
            out = max(out, count)
    
    return out

def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(solution(n, a))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
