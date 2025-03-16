import sys

def main():
    # Read the number of pairs of integers to be processed
    n = int(input())

    # Initialize an array to store the characters representing the actions
    ch = [None] * n

    # Initialize sums for two different actions
    s1 = 0
    s2 = 0

    # Loop variables
    i = 0
    j = 0
    flag = 0
    dif = 0

    # Process each pair of integers
    for i in range(n):
        # Read the next pair of integers
        x = int(input())
        y = int(input())

        # Calculate temporary sums for the current iteration
        temp1 = s1 + x
        temp2 = s2 + y

        # Check if adding x to s1 keeps the difference within 500
        if abs(temp1 - s2) <= 500:
            s1 += x
            ch[j] = 'A'
            j += 1
            continue

        # Check if adding y to s2 keeps the difference within 500
        if abs(temp2 - s1) <= 500:
            s2 += y
            ch[j] = 'G'
            j += 1
            continue

        # If neither condition is met, set flag to indicate failure
        flag = 1
        break

    # Check if the loop was exited due to a failure condition
    if flag == 1:
        print(-1)
    else:
        # Convert the character array to a string and print the result
        ans = ''.join(ch)
        print(ans)

if __name__ == "__main__":
    main()

