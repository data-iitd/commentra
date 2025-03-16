# Import necessary libraries
from collections import Counter

# Define the main function
def main():
    n, k = map(int, input().split())  # Read the number of elements 'n' and the number of frequencies to consider 'k'

    # Read the elements and count their frequencies
    elements = list(map(int, input().split()))
    cnt = Counter(elements)  # Use Counter to count frequencies of elements

    # Extract the frequency counts and store them in a list
    a = list(cnt.values())

    ans = 0  # Initialize a variable 'ans' to store the sum of the first 'k' frequency counts

    a.sort()  # Sort the list 'a' in ascending order

    m = len(a) - k  # Calculate the index of the last frequency count to be considered

    for i in range(m):  # Loop through the first 'm' frequency counts and add them to 'ans'
        ans += a[i]

    print(ans)  # Print the result 'ans'

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
