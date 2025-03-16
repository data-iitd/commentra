
import sys

def main():
    # Reading the number of test cases from the input
    n = int(input())

    # Creating an empty list to store the first array elements
    ai = []

    # Creating an empty list to store the second array elements
    bi = []

    # Iterating through the test cases
    for i in range(n):
        # Creating a StringTokenizer object to parse the input line
        st = sys.stdin.readline().split()

        # Adding the first array element to the list
        ai.append(int(st[0]))

        # Adding the second array element to the list
        bi.append(int(st[1]))

    # Sorting the lists in ascending order
    ai.sort()
    bi.sort()

    # Checking if the number of test cases is odd
    if n % 2 == 1:
        # Calculating and printing the answer for odd number of test cases
        print(bi[len(bi) // 2] - ai[len(ai) // 2] + 1)
    else:
        # Calculating the average of the middle two elements of the first list
        b = (ai[len(ai) // 2] + ai[len(ai) // 2 - 1]) / 2

        # Calculating the average of the middle two elements of the second list
        c = (bi[len(bi) // 2] + bi[len(bi) // 2 - 1]) / 2

        # Calculating and printing the answer for even number of test cases
        print(2 * (c - b) + 1)

if __name__ == '__main__':
    main()

