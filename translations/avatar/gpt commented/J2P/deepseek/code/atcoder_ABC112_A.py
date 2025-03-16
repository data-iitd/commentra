import sys

def read(len):
    str_list = []
    for _ in range(len):
        str_list.append(sys.stdin.readline().strip())
    return str_list

def main():
    # Read the first input as an integer
    n = int(read(1)[0])
    
    # Check if the input is 1
    if n == 1:
        # If the input is 1, print "Hello World"
        print("Hello World")
    else:
        # If the input is not 1, read two more strings
        strs = read(2)
        # Parse the two strings as integers and print their sum
        print(int(strs[0]) + int(strs[1]))

if __name__ == "__main__":
    main()
