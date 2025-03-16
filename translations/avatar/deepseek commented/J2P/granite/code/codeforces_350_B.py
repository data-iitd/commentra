
import sys

def main():
    # Read the number of elements
    n = int(input())

    # Initialize arrays to store the input values
    a = [0] * (n + 1)
    b = [0] * (n + 1)
    num = [0] * (n + 1)

    # Read the elements of array a
    for i in range(1, n + 1):
        a[i] = int(input())

    # Read the elements of array b
    for i in range(1, n + 1):
        b[i] = int(input())

    # Count the occurrences of each element in array b
    for i in range(1, n + 1):
        num[b[i]] += 1

    # Initialize variables to store the result
    ss = ""
    ans = 0
    st = [False] * (n + 1)

    # Iterate through the elements of array a
    for i in range(1, n + 1):
        if a[i] == 1:
            # Mark the current element as visited
            st[i] = True

            # Build the sequence of indices
            sb = ""
            x = b[i]
            sss = ""
            sss += str(i)
            sb += " " + sss[::-1]
            s = 1

            # Continue building the sequence until a visited element or mismatch is found
            while not st[x] and num[x] == 1 and x!= 0 and a[x]!= 1:
                sss = ""
                sss += str(x)
                sb += " " + sss[::-1]
                st[x] = True
                x = b[x]
                s += 1

            # Update the result if a longer sequence is found
            if s > ans:
                ans = s
                ss = sb[::-1]

    # Print the result
    print(ans)
    print(ss)

if __name__ == "__main__":
    main()