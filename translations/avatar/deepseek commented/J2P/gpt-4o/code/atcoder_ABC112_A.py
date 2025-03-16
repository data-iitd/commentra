import sys

def main():
    # Reading the number of inputs
    n = int(read(1)[0])

    # Processing the input based on the value of n
    if n == 1:
        # Outputting "Hello World" if n is 1
        print("Hello World")
    else:
        # Reading two strings and calculating their sum if n is not 1
        strs = read(2)
        print(int(strs[0]) + int(strs[1]))

# Method to read input from the standard input stream
def read(length):
    str_list = []
    for _ in range(length):
        str_list.append(sys.stdin.readline().strip())
    return str_list

if __name__ == "__main__":
    main()

# <END-OF-CODE>
