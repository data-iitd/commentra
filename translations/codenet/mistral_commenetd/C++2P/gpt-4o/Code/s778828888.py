# We include the algorithm library to use min later

def main():  # The entry point of the program
    n, m, x = map(int, input().split())  # Read three integers from the standard input

    a = [0] * 105  # Declare and initialize a list a of size 105 with zeros

    for _ in range(m):  # Iterate through m times
        temp = int(input())  # Read an integer from the standard input and store it in temp
        a[temp] = 1  # Set the value of the list element at index temp to 1

    ansl = 0  # Declare and initialize ansl
    ansr = 0  # Declare and initialize ansr

    for i in range(x, n + 1):  # Iterate through the range from x to n
        ansr += a[i]  # Add the value of the list element at index i to ansr

    for i in range(x, -1, -1):  # Iterate through the range from x to 0
        ansl += a[i]  # Add the value of the list element at index i to ansl

    print(min(ansl, ansr))  # Print the minimum value between ansl and ansr

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
