
n = input()  # Taking an input from the user and storing it in the variable `n`.
a = ["10", "100", "1000", "10000", "100000"]  # Defining a list `a` containing string representations of numbers.
new = sum(list(map(int, n)))  # Converting the input `n` to a list of its digits, summing them up, and storing the result in `new`.
if n in a:  # Checking if the input `n` is in the list `a`.
    print(10)  # If `n` is in `a`, print the number 10.
else:  # Otherwise...
    print(new)  # Print the value of `new`.

