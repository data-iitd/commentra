import sys

def main():
    N = int(input().strip())  # read the number of elements from the standard input
    a = list(map(int, input().strip().split()))  # read the elements of array a from the standard input

    b = a.copy()  # create a copy of array a and assign it to array b
    b.sort()  # sort the elements in array b in ascending order

    frontHalf = b[N//2 - 1]  # assign the middle value of the first half of the sorted array b to frontHalf
    backHalf = b[N//2]  # assign the middle value of the second half of the sorted array b to backHalf

    for value in a:  # iterate through the array a and print the appropriate middle value based on the condition
        if value < backHalf:
            print(backHalf)  # print the middle value of the second half of the sorted array b
        else:
            print(frontHalf)  # print the middle value of the first half of the sorted array b

if __name__ == "__main__":
    main()
