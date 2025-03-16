import sys

def main():
    # Reading the number of elements
    n = int(input())
    # Creating an ArrayList to store the elements
    list = []
    # Reading the elements and adding them to the ArrayList
    for i in range(n):
        list.append(int(input()))
    # Sorting the ArrayList
    list.sort()
    # Initializing the counter variable
    c = 1
    # Iterating through the sorted list to find the smallest missing positive integer
    for i in range(n):
        if list[i] >= c:
            c += 1
    # Printing the result
    print(c)

if __name__ == "__main__":
    main()

