
import sys

# Function to calculate the answer
def calculate_answer(A):
    # Initializing the answer variable to zero
    ans = 0

    # Calculating the answer using the given formula
    for i in range(60):
        # Initializing the variable a to zero
        a = 0
        # Initializing the variable count1 to zero
        count1 = 0

        # Counting the number of elements in the array A with the i-th bit set to 1
        for j in range(len(A)):
            if (A[j] >> i & 1) == 1:
                # Incrementing the count1 variable
                count1 += 1

        # Calculating the contribution of the i-th bit to the answer
        a = a + count1 * (len(A) - count1)

        # Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
        for j in range(i):
            a = (a << 1) % 1000000007

        # Adding the contribution to the answer
        ans += a
        ans %= 1000000007

    # Returning the answer
    return ans

# Main function
if __name__ == "__main__":
    # Reading the number of elements in the array
    n = int(input())

    # Creating an array of long type with size n
    A = [0] * n

    # Reading the elements of the array A
    for i in range(n):
        A[i] = int(input())

    # Calculating the answer
    ans = calculate_answer(A)

    # Printing the answer
    print(ans)

