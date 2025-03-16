

import sys # Input and output streams
import io # Input and output streams
import atexit # Function for registering cleanup actions
import re # Regular expressions for string manipulation

range = xrange # Compatibility with Python 3

filter = itertools.ifilter # Compatibility with Python 3
map = itertools.imap # Compatibility with Python 3
zip = itertools.izip # Compatibility with Python 3

sys.stdout = io.BytesIO() # Redirect the output stream to a BytesIO object

try: # Register a cleanup action to flush the output buffer
    sys.stdout.flush() # Flush the output buffer
    sys.stdout = sys.__stdout__ # Restore the original output stream
except IOError:
    pass

atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue())) # Register a cleanup action to write the output buffer to the console

def main():
    s = input() # Read the input string
    d = [] # Initialize an empty list for the output

    for c in s: # Iterate through each character in the input string
        if c == '0':
            d.append('0') # Append "0" to the output list
        elif c == '1':
            d.append('1') # Append "1" to the output list
        elif c == 'B':
            if len(d) > 0: # If there is a character in the output list
                d.pop() # Remove the last character from the output list

    print(''.join(d)) # Print the output list to the console

if __name__ == '__main__':
    main() # Call the main function

