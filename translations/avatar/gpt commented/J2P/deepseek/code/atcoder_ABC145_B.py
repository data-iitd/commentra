def cout(str):
    print(str)

def main():
    # Reading an integer input which represents the length of the string
    n = int(input())
    
    # Reading the actual string input
    str = input()

    # Constructing the first half of the string
    a = str[:n//2]

    # Checking if the string is made up of two identical halves
    if str == a + a:
        cout("Yes")  # If true, print "Yes"
    else:
        cout("No")  # If false, print "No"

if __name__ == "__main__":
    main()
