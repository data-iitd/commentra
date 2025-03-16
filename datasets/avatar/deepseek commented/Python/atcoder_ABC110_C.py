
import collections
# Import the collections module for specialized container datatypes

def run(s, t):
    # Define the run function that takes two arguments, s and t
    ss = sorted(list(collections.Counter(s).values()))
    # Create a Counter object for s, sort its values, and store them in ss
    tt = sorted(list(collections.Counter(t).values()))
    # Create a Counter object for t, sort its values, and store them in tt
    if ss == tt:
        # Check if the sorted values of s and t are equal
        return 'Yes'
    else:
        # If not equal, return 'No'
        return 'No'

def main():
    # Define the main function to get input and print the result
    s = input()
    # Get input for s from the user
    t = input()
    # Get input for t from the user
    print(run(s, t))
    # Call the run function with s and t as arguments and print the result

if __name__ == '__main__':
    # Ensure main is called only when the script is executed directly
    main()

