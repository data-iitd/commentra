import sys

def main():
    # Read the number of elements in the list from the standard input
    n = int(input().strip())

    # Create a list to store the unique and sorted list elements
    a = list(map(int, input().strip().split()))

    # Filter and sort the list
    a = sorted(set(a))

    # Check if there exists a sequence of three consecutive elements with a difference of 1
    found = False
    for i in range(len(a) - 2):
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
            found = True
            break

    # Write the output to the standard output
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()
