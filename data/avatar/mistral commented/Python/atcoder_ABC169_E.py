# Function to resolve the problem
def resolve( ):

    # Read the number of test cases
    n = int(input())

    # Initialize empty lists to store low and high values
    low = []
    high = []

    # Read low and high values for each test case and append to respective lists
    for i in range(n):
        a, b = map(int, input().split())
        low.append(a)
        high.append(b)

    # Sort the low and high lists in ascending order
    low.sort()
    high.sort()

    # Check if the number of test cases is odd
    if n % 2:
        # If it is odd, print the difference between the middle low and middle high values
        print(high[(n+1)//2-1] - low[(n+1)//2-1] + 1)
    else:
        # If it is even, calculate the average of middle low and middle high values
        hh = (high[(n)//2-1] + high[(n)//2]) / 2
        ll = (low[(n)//2-1] + low[(n)//2]) / 2

        # Print the result which is twice the difference between the averages
        print(int((hh-ll)*2)+1)
