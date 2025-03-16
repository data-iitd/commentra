import sys

def main():
    mod = int(1e9 + 7)  # Assigning the value of 1e9 + 7 to a variable named mod
    input = sys.stdin.read
    data = input().split()  # Reading all input at once and splitting it into a list
    n = int(data[0])  # Reading the first integer input and assigning it to the variable n
    k = int(data[1])  # Reading the second integer input and assigning it to the variable k

    len_list = []  # Creating an empty list named len_list to store the lengths of subsequences
    l = 1  # Initializing the variable l to 1

    while l <= n:  # Starting a while loop that runs as long as l is less than or equal to n
        r = n // (n // l)  # Calculating the right end of the current subsequence
        len_list.append(r - l + 1)  # Adding the length of the current subsequence to the list len_list
        l = r + 1  # Incrementing the variable l to consider the next subsequence

    q = len(len_list)  # Assigning the size of the list len_list to the variable q
    dp = [0] * (k * (q + 1))  # Creating a list named dp of size k * (q + 1) to store the dynamic programming results

    for j in range(1, q + 1):  # Starting a for loop that runs from 1 to q
        dp[j] = len_list[j - 1] + dp[j - 1]  # Calculating the dp value for the current subsequence length

    for i in range(1, k):  # Starting a nested for loop that runs from 1 to k - 1 for the number of overlapping subsequences
        for j in range(1, q + 1):  # Starting an inner for loop that runs from 1 to q for the length of the current subsequence
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + 
                                    dp[(i - 1) * (q + 1) + q - j + 1] * len_list[j - 1]) % mod  # Calculating the dp value
    print(dp[k * (q + 1) - 1])  # Printing the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
