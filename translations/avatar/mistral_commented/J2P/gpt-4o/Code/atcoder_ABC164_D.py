# Importing the necessary module
import sys

def main():
    S = input().strip()  # Reading the first line of input as a string
    N = len(S)  # Getting the length of the string

    mod_arr = [0] * N  # Creating an array of size N to store intermediate results
    mod_cnt = [0] * 2019  # Creating an array of size 2019 to count the frequency of each number
    radix = 1  # Initializing the radix to 1

    for i in range(N):  # Iterating through each character in the string
        tmp = 0  # Initializing a temporary variable to store the intermediate result

        # Calculating the value of the current digit in the given base
        tmp = (int(S[N - 1 - i]) * radix) % 2019

        # Updating the temporary variable with the carry from the previous digit
        if i != 0:
            tmp = (tmp + mod_arr[i - 1]) % 2019

        # Storing the intermediate result in the array
        mod_arr[i] = tmp

        # Updating the frequency count of the current number in the array
        mod_cnt[tmp] += 1

        # Updating the radix for the next iteration
        radix = (radix * 10) % 2019

    ans = 0  # Initializing a variable to store the final answer

    # Calculating the answer by summing up the terms of the formula
    for i in range(2019):
        ans += mod_cnt[i] * (mod_cnt[i] - 1) // 2

    print(ans)  # Printing the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
