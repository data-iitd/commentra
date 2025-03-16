import sys

def main():
    startTime = time.time()  # Start time measurement
    n = int(input().strip())  # Reading the number of elements in the array
    div = 10**9 + 7  # Modulus constant for efficient modular arithmetic
    A = list(map(int, input().strip().split()))  # Reading the elements of the array A
    ans = 0  # Initializing the answer variable to zero

    # Calculating the answer using the given formula
    for i in range(60):  # Looping through all the bits from 0 to 59
        a = 0  # Initializing the variable a to zero
        count1 = 0  # Initializing the variable count1 to zero

        # Counting the number of elements in the array A with the i-th bit set to 1
        for j in range(n):
            if (A[j] >> i) & 1:  # Checking if the i-th bit is set in the j-th element of the array A
                count1 += 1  # Incrementing the count1 variable

        # Calculating the contribution of the i-th bit to the answer
        a = (count1 * (n - count1))  # a = count1 * (n - count1)

        # Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
        for j in range(i):
            a <<= 1  # a <<= 1
            a %= div  # a %= div

        # Adding the contribution to the answer
        ans += a  # ans += a
        ans %= div  # ans %= div

    # Printing the answer
    print(ans)  # Printing the answer
    endTime = time.time()  # End time measurement
    print("Time taken by the program is :", (endTime - startTime) * 1000, "milliseconds")  # Printing the time taken by the program to execute

if __name__ == "__main__":
    import time
    main()
