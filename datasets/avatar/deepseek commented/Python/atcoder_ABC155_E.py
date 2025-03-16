
import sys
# Define possible input methods: clipboard, file, key
input_methods = ['clipboard', 'file', 'key']
# Indicate which input method to use, starting with 'clipboard'
using_method = 0
input_method = input_methods[using_method]
# Define a lambda function to take integer inputs in space-separated format
IN = lambda: map(int, input().split())
# Define a modulo value
mod = 1000000007

# Main function for base case
def main_b():
    # Take input string
    s = input()
    # Initialize pp and na to 0
    pp = 0
    na = 0
    # Iterate over the string in reverse order
    for i, c in enumerate(s[::-1]):
        cc = na + int(c)
        na = 0
        # If the sum is less than or equal to 4, add to pp
        if cc <= 4:
            pp += cc
        else:
            na = 1
            # If it's the last digit, add 1 to pp
            if i == len(s) - 1:
                pp += 1
            pp += 10 - cc
    # Print the result
    print(pp)

# Main function for general case
def main():
    s = input()
    pmin = 1000
    mmin = 0
    s = '0' + s
    # Iterate over the string in reverse order
    for c in s[::-1]:
        v = int(c)
        npmin = min(pmin + 10 - (v + 1), mmin + 10 - v)
        nmmin = min(pmin + v + 1, mmin + v)
        pmin = npmin
        mmin = nmmin
    # Return the minimum of pmin and mmin
    return min(pmin, mmin)

# Check if the script is running in test mode
isTest = False
# Function to print values if in test mode
def pa(v):
    if isTest:
        print(v)

# Function to read input from clipboard if running on iOS
def input_clipboard():
    import clipboard
    input_text = clipboard.get()
    input_l = input_text.splitlines()
    for l in input_l:
        yield l

# Main execution block
if __name__ == "__main__":
    if sys.platform == 'ios':
        if input_method == input_methods[0]:
            ic = input_clipboard()
            input = lambda: ic.__next__()
        elif input_method == input_methods[1]:
            sys.stdin = open('inputFile.txt')
        else:
            pass
        isTest = True
    else:
        pass
    ret = main()
    if ret is not None:
        print(ret)
