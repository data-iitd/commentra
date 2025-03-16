import sys

# Define the available input methods
input_methods = ['clipboard', 'file', 'key']
using_method = 0  # Index to select the input method
input_method = input_methods[using_method]  # Select the input method based on the index

# Define a lambda function for reading multiple integers from input
IN = lambda: map(int, input().split())
mod = 1000000007  # Define a modulus value for calculations

def main_b():
    # Read input string
    s = input()
    pp = 0  # Initialize the total score
    na = 0  # Initialize carry-over value

    # Process the string in reverse order
    for i, c in enumerate(s[::-1]):
        cc = na + int(c)  # Calculate the current value with carry-over
        na = 0  # Reset carry-over for the next iteration

        # Determine how to update the total score based on the current value
        if cc <= 4:
            pp += cc  # If the value is 4 or less, add it directly to the score
        else:
            na = 1  # Set carry-over if the value exceeds 4
            if i == len(s) - 1:
                pp += 1  # If it's the last digit, add 1 to the score
            pp += 10 - cc  # Add the difference to the score

    print(pp)  # Output the final score

def main():
    # Read input string
    s = input()
    pmin = 1000  # Initialize minimum score for positive values
    mmin = 0  # Initialize minimum score for negative values
    s = '0' + s  # Prepend '0' to the input string for easier processing

    # Process the string in reverse order
    for c in s[::-1]:
        v = int(c)  # Convert character to integer
        # Calculate new minimum scores based on current digit
        npmin = min(pmin + 10 - (v + 1), mmin + 10 - v)
        nmmin = min(pmin + v + 1, mmin + v)
        pmin = npmin  # Update positive minimum score
        mmin = nmmin  # Update negative minimum score

    return min(pmin, mmin)  # Return the minimum score between positive and negative

isTest = False  # Flag to indicate if the program is in test mode

def pa(v):
    # Print value if in test mode
    if isTest:
        print(v)

def input_clipboard():
    import clipboard  # Import clipboard module for clipboard access
    input_text = clipboard.get()  # Get text from clipboard
    input_l = input_text.splitlines()  # Split the text into lines
    for l in input_l:
        yield l  # Yield each line as an input

if __name__ == "__main__":
    # Check the platform and set input method accordingly
    if sys.platform == 'ios':
        if input_method == input_methods[0]:  # Clipboard input
            ic = input_clipboard()  # Initialize clipboard input
            input = lambda: ic.__next__()  # Override input function
        elif input_method == input_methods[1]:  # File input
            sys.stdin = open('inputFile.txt')  # Redirect stdin to input file
        else:
            pass  # No action for key input
        isTest = True  # Set test mode to true
    else:
        pass  # No specific action for non-iOS platforms

    ret = main()  # Call the main function
    if ret is not None:
        print(ret)  # Print the result if it's not None
