
import sys

# Global list to hold the sieve flags for prime numbers
flag = [False] * 50001

# Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
def prime(num):
    i, j = 2, 0
    while i * i <= num:
        if not flag[i]:
            for j in range(2, num // i + 1):
                flag[i * j] = True
        i += 1

# Main function to execute the program
def main():
    while True:
        n = int(input())
        if n == 0:
            break
        i, cnt = 2, 0
        while i * 2 <= n:
            if not flag[i] and not flag[n - i]:
                cnt += 1
            i += 1
        print(cnt)

if __name__ == "__main__":
    prime(50000)
    main()

