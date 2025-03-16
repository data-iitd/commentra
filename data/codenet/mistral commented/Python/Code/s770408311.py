# Ask the user for the number of strings they want to input
n = int(input("Enter the number of strings: "))

# Initialize an empty list called res to store the strings
res = []

# Use a for loop to iterate through the range of numbers from 0 to n (inclusive)
for i in range(n):
    # Ask the user for a string input and append it to our list res
    string = input("Enter string number {}: ".format(i+1))
    res.append(string)

# After the for loop finishes, print the length of the set of unique strings in our list res
print("The number of unique strings is: ", len(set(res)))
