import math

def main():
    n = int(input())
    sqrt = int(math.sqrt(n))
    answer = 0
    i = 2
    while i <= sqrt:
        count = 0
        while n % i == 0:
            n //= i
            count += 1
        j = 1
        while count - j >= 0:
            count -= j
            answer += 1
            j += 1
        i += 1
    if n > 1:
        answer += 1
    print(answer)

if __name__ == "__main__":
    main()
