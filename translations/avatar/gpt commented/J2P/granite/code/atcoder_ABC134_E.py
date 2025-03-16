
import sys

def main():
    # Read the number of integers to process
    n = int(input())

    # Initialize a dictionary to store integers and their counts
    d = {}

    # Process each integer input
    for _ in range(n):
        # Read the next integer
        num = int(input())

        # Check if there is no lower key in the dictionary
        if num not in d:
            # If no lower key exists, increment the count for the current number
            d[num] = d.get(num, 0) + 1
        else:
            # If there is a lower key, get that key and its count
            key = num
            val = d[key]

            # If the count of the lower key is 1, remove it from the dictionary
            if val == 1:
                del d[key]
            else:
                # Otherwise, decrement the count of the lower key
                d[key] = val - 1

            # Increment the count for the current number
            d[num] = d.get(num, 0) + 1

    # Initialize a variable to hold the final answer
    ans = 0

    # Sum up all the counts in the dictionary
    for key in d:
        val = d[key]
        ans += val

    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

