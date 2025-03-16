def sum_of_digits(a):
    ans = 0
    while a >= 10:
        ans += a % 10
        a //= 10
    ans += a
    return ans

def main():
    n = int(input())
    
    # Calculate n as half of N if N is even, or half of N plus one if N is odd
    if n % 2 == 0:
        n = n // 2
    else:
        n = (n + 1) // 2
    
    # Initialize ans with the sum of digits of 1 and N-1
    ans = sum_of_digits(1) + sum_of_digits(n - 1)
    
    # Iterate from 1 to n to find the minimum sum of digits of A and N-A
    for A in range(1, n + 1):
        if sum_of_digits(A) + sum_of_digits(n - A) < ans:
            ans = sum_of_digits(A) + sum_of_digits(n - A)
    
    # Print the minimum ans
    print(ans)

main()

