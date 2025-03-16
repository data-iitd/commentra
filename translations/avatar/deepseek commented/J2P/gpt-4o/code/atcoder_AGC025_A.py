def sum_of_digits(a):
    ans = 0
    while a >= 10:
        ans += a % 10
        a //= 10
    ans += a
    return ans

def main():
    N = int(input())
    
    # Calculate n as half of N if N is even, or half of N plus one if N is odd
    n = N // 2 if N % 2 == 0 else (N + 1) // 2
    
    # Initialize ans with the sum of digits of 1 and N-1
    ans = sum_of_digits(1) + sum_of_digits(N - 1)
    
    # Iterate from 1 to n to find the minimum sum of digits of A and N-A
    for A in range(1, n + 1):
        current_sum = sum_of_digits(A) + sum_of_digits(N - A)
        if current_sum < ans:
            ans = current_sum
    
    # Print the minimum ans
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
