import sys

def main():
    # Read the first line of input containing 4 integers and store them in ns list
    print("Reading input")
    ns = list(map(int, sys.stdin.readline().split()))

    # Sort the ns list in ascending order
    print("Sorting the numbers in ns list")
    ns.sort()

    # Check if the sorted ns list matches the specific condition (1, 4, 7, 9)
    print("Checking the condition")
    if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
        print("The condition is true, print YES")
        print("Output: YES")
        print()
        print("End of the program")
        return
    else:
        print("The condition is false, print NO")
        print("Output: NO")
        print()
        print("End of the program")
        return

if __name__ == "__main__":
    main()
