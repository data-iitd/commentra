def cout(str):
    print(str)

def main():
    # Reading the integer input n
    n = int(input())
    
    # Reading the string input str
    str_input = input()
    
    # Constructing the string a by taking the first n/2 characters of str
    a = ""
    for i in range(n // 2):
        a += str_input[i]
    
    # Checking if str is equal to a + a and printing the result
    if str_input == a + a:
        cout("Yes")
    else:
        cout("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
