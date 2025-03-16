
l = [ ]
limit = 10000000000

# The gen function generates numbers containing only the digits 4 and 7 using recursion.
def gen(number, four, seven):
    # If the number exceeds the limit, return without adding it to the list.
    if number > limit:
        return
    # If the number is positive and the count of 4's equals the count of 7's, add it to the list.
    if number > 0 and four == seven:
        l.append(number)
    # Recursively generate numbers by adding 4 or 7 to the current number.
    gen(number * 10 + 4, four + 1, seven)
    gen(number * 10 + 7, four, seven + 1)

# The main function takes an input, finds the smallest number in the list l that is greater than or equal to n, and prints it.
def main():
    gen(0, 0, 0)  # Start generating numbers with 0, 0, 0 counts of 4's and 7's.
    l.sort()  # Sort the list l to easily find the smallest valid number.
    n = int(input())  # Read the input number n.
    ans = 0
    # Iterate through the sorted list to find the smallest number greater than or equal to n.
    for val in l:
        if val >= n:
            ans = val
            break
    print(ans)  # Print the smallest number found.

main()

