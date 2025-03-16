import sys  # Importing necessary modules

def main():
    num = 998244353  # Initializing a variable 'num' with a value
    input = sys.stdin.read  # Reading input from the standard input stream
    data = input().splitlines()  # Splitting the input into lines

    n = int(data[0])  # Reading the number of test cases from the input
    ai = []  # Creating an empty list to store the first array elements
    bi = []  # Creating an empty list to store the second array elements

    for i in range(1, n + 1):  # Iterating through the test cases
        a, b = map(int, data[i].split())  # Parsing the input line
        ai.append(a)  # Adding the first array element to the list
        bi.append(b)  # Adding the second array element to the list

    # Sorting the lists in ascending order
    ai.sort()
    bi.sort()

    if n % 2 == 1:  # Checking if the number of test cases is odd
        print(bi[len(bi) // 2] - ai[len(ai) // 2] + 1)  # Calculating and printing the answer for odd number of test cases
    else:
        b = (ai[len(ai) // 2] + ai[len(ai) // 2 - 1]) / 2  # Calculating the average of the middle two elements of the first list
        c = (bi[len(bi) // 2] + bi[len(bi) // 2 - 1]) / 2  # Calculating the average of the middle two elements of the second list
        print(int(2 * (c - b) + 1))  # Calculating and printing the answer for even number of test cases

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
