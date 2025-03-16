# Importing the collections module to use Counter function
import collections

# Define a function named 'run' that takes two arguments 's' and 't'
def run(s, t):
    # Using Counter function to count the occurrences of each character in string 's'
    # and storing the result in a dictionary
    ss = sorted(list(collections.Counter(s).values()))

    # Using Counter function to count the occurrences of each character in string 't'
    # and storing the result in a dictionary
    tt = sorted(list(collections.Counter(t).values()))

    # Comparing the sorted lists of occurrences of characters in strings 's' and 't'
    # If they are equal, then the strings have the same frequency distribution of characters
    # and thus are identical, so return 'Yes'
    # Otherwise, return 'No'
    if ss == tt:
        return 'Yes'
    else:
        return 'No'

# Define a function named 'main' that takes no arguments
def main():
    # Taking input strings 's' and 't' from the user
    s = input()
    t = input()

    # Calling the 'run' function with strings 's' and 't' as arguments and printing the result
    print(run(s, t))

# If the script is run as the main program, then call the 'main' function
if __name__ == '__main__':
    main()
