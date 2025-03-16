def str2list(s):
    # Splitting the string into a list of integers
    return list(map(int, s.split()))

def main():
    n = int(input())  # Reading the first line of input which is an integer
    v_list = str2list(input())  # Reading the second line of input and converting it to a list of integers
    c_list = str2list(input())  # Reading the third line of input and converting it to a list of integers

    max_profit = 0  # Initializing the variable max_profit to 0

    for i in range(n):  # Iterating through each element in the arrays
        profit = v_list[i] - c_list[i]  # Calculating the profit for the current element
        if profit > 0:  # Checking if the profit is positive
            max_profit += profit  # If the profit is positive, adding it to max_profit

    print(max_profit)  # Printing the maximum profit

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
