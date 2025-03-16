import sys

MOD = int(1e9 + 7)  # Declaring a constant named MOD

def main():
    input = sys.stdin.read  # Using sys.stdin.read for faster input
    data = input().split()  # Reading all input at once and splitting into a list
    index = 0  # Initializing an index to track the current position in the data list
    t = int(data[index])  # Reading the number of test cases
    index += 1  # Incrementing the index

    results = []  # List to store results for each test case

    for _ in range(t):  # Looping through each test case
        n = int(data[index])  # Reading the value of n
        index += 1  # Incrementing the index
        a = int(data[index])  # Reading the value of a
        index += 1  # Incrementing the index
        b = int(data[index])  # Reading the value of b
        index += 1  # Incrementing the index

        if n < a:  # Checking if n is less than a
            results.append("No")  # If true, appending "No" to results
            continue  # Skipping to the next test case

        if a == b:  # Checking if a is equal to b
            if n % a == 0:  # Checking if n is divisible by a
                results.append("Yes")  # If true, appending "Yes" to results
            else:  # If false
                results.append("No")  # Appending "No" to results
            continue  # Skipping to the next test case

        x = b // (b - a)  # Calculating the value of x
        if n > x * a:  # Checking if n is greater than x * a
            results.append("Yes")  # If true, appending "Yes" to results
            continue  # Skipping to the next test case

        low = 1  # Initializing low to 1
        high = x + 1  # Initializing high to x + 1
        ans = 1  # Initializing ans to 1

        while low <= high:  # Looping until low is less than or equal to high
            mid = (low + high) // 2  # Calculating the middle value of low and high
            if mid * a < n:  # Checking if mid * a is less than n
                low = mid + 1  # If true, setting low to mid + 1
            else:  # If false
                ans = mid  # Setting ans to mid
                high = mid - 1  # Setting high to mid - 1

        if n > (ans - 1) * b and n < ans * a:  # Checking if n is between (ans - 1) * b and ans * a
            results.append("No")  # If true, appending "No" to results
        else:  # If false
            results.append("Yes")  # Appending "Yes" to results

    print("\n".join(results))  # Printing all results at once

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
