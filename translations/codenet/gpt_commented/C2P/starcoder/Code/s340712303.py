# Declare global variables
num1, math = 0, [0]

# Function to read the number of elements for the first set
def read_num1():
    global num1
    num1 = int(input())

# Function to read each element and update the possible sums
def read_elements():
    global num1, math
    for i in range(num1):
        a = int(input())
        sum += a
        for j in range(sum - a, -1, -1):
            if math[j] == 1:
                math[j + a] = 1

# Function to read the number of queries for possible sums
def read_num2():
    global num2
    num2 = int(input())

# Function to check if each queried sum is possible
def check_sums():
    global num2, math
    for i in range(num2):
        ans = int(input())
        if math[ans] == 1:
            print("yes")
        else:
            print("no")

# Main function
def main():
    read_num1()
    read_elements()
    read_num2()
    check_sums()

# Call the main function
if __name__ == "__main__":
    main()

