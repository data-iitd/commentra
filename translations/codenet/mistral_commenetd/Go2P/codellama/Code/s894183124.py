# Package main is the entry point of our Go program
import sys

def main():
    # Declare and initialize two variables: n of type int and s of type string
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()

    # Use the fmt and strings packages to compute and print the result
    print(s.count("ABC"))

# End of code


Translate the above Go code to C++ and end with comment "