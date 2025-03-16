def main():
    # Read the number of elements from user input
    n = int(input())

    # Read the number of largest elements to sum from user input
    a = int(input())

    # Read the elements into a list from user input
    s = list(map(int, input().split()))

    # Sort the list in non-decreasing order
    s.sort()

    # Sum the largest 'a' elements from the sorted list
    sum_of_largest = sum(s[-a:])

    # Output the calculated sum of the largest 'a' elements
    print(sum_of_largest)


if __name__ == "__main__":
    main()
