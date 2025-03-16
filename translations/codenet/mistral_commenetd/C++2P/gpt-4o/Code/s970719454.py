# Importing necessary libraries
import sys

# Defining a function to handle the main logic
def main():
    # Initializing arrays
    here = [0] * 100001
    dp1 = [0] * 100001
    dp2 = [0] * 100001

    # Reading input
    while True:
        n, m = map(int, input().split())
        if n == 0:
            break

        # Resetting the arrays for new input
        here = [0] * 100001
        dp1 = [0] * 100001
        dp2 = [0] * 100001

        # Reading number of houses and queries
        dpflg = False
        
        # Reading queries
        for _ in range(m):
            a = int(input())
            # Setting the corresponding element of 'here' array to 1
            here[a] = 1
            # If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
            if a == 0:
                dpflg = True

        # Calculating the maximum length of a subsequence without any house
        maxi1 = 0
        for i in range(1, n + 1):
            if here[i] == 1:
                dp1[i] = dp1[i - 1] + 1
            maxi1 = max(dp1[i], maxi1)

        # Calculating the maximum length of a subsequence with at least one house
        maxi2 = 0
        for i in range(1, n + 1):
            if here[i] == 1:
                dp2[i] = dp2[i - 1] + 1
            else:
                dp2[i] = dp1[i - 1] + 1
            maxi2 = max(dp2[i], maxi2)

        # Printing the result
        if not dpflg:
            print(maxi1)
        else:
            print(maxi2)

# Running the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
