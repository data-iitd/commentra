def cout(str):
    print(str)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Reading the integer input n
    n = int(data[0])
    
    # Reading the string input str
    str = data[1]
    
    # Constructing the string a by taking the first n/2 characters of str
    a = str[:n//2]
    
    # Checking if str is equal to a + a and printing the result
    if str == a + a:
        cout("Yes")
    else:
        cout("No")

main()
