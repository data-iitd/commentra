
import math

def main():
    # Step 1: Read a long integer n from the user
    n = int(input())

    # Step 2: Calculate the integer square root of n
    sqrt = int(math.sqrt(n))

    # Step 3: Initialize an answer variable to 0
    answer = 0

    # Step 4: Iterate from 2 to the square root of n
    for i in range(2, sqrt + 1):
        # Step 5: For each number i in this range, count the number of times i divides n
        count = 0
        while 0 == (n % i):
            n //= i # Step 6: Update the value of n by dividing it by i
            count += 1

        # Step 7: Calculate the number of times i can be subtracted from the count
        for j in range(1, count + 1):
            count -= j # Step 8: Update the answer variable with the number of times i can be subtracted
            answer += 1

    # Step 9: If n is greater than 1 after the loop, it means n is a prime number and increments the answer by 1
    if n > 1:
        answer += 1

    # Step 10: Print the answer
    print(answer)

if __name__ == '__main__':
    main()

