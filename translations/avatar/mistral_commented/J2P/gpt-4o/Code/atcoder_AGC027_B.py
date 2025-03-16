import sys  # Importing the sys module for input handling

class Main:  # Defining the Main class
    INF = float('inf')  # Initializing INF with infinity

    def solve(self):  # Method to solve the problem
        input = sys.stdin.read  # Reading all input at once
        data = input().split()  # Splitting the input into a list of strings

        N = int(data[0])  # Reading the number of elements in the array
        X = int(data[1])  # Reading the value of X
        x = list(map(int, data[2:2 + N]))  # Creating a list of size N to store the elements
        xsum = [0] * (N + 1)  # Creating a list of size N+1 to store the sum of elements up to that index

        for i in range(N):  # Loop to read and store the elements in the list
            xsum[i + 1] = xsum[i] + x[i]  # Updating the sum of elements up to the current index

        ans = X * N + 5 * xsum[N]  # Initializing the answer with the first calculation

        for i in range(1, N):  # Loop to find the minimum cost
            cost = X * i + 5 * (xsum[N] - xsum[N - i])  # Calculating the cost for the current i
            for j in range(5, 1000000, 2):  # Nested loop to check the cost for different j
                k = N - i  # Setting k based on the current i
                if k < 0:  # If k is negative, break the loop
                    break
                cost += j * (xsum[k] - xsum[max(k - i, 0)])  # Updating the cost with the sum of elements between k and k-i
                if cost > ans:  # If the cost is greater than the current answer, break the loop
                    break
            ans = min(ans, cost)  # Updating the answer with the minimum cost found so far

        print(ans + N * X)  # Printing the final answer

if __name__ == "__main__":  # Main entry point of the program
    Main().solve()  # Creating an instance of the Main class and calling the solve method

# <END-OF-CODE>
