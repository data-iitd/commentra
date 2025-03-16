import sys

def main():
    n = int(input())  # Read the size of the array
    a = list(map(int, input().split()))  # Populate the array with n integers
    a.sort()  # Sort the array
    for i in range(len(a) - 1):
        if a[i + 1] < a[i] * 2 and a[i] != a[i + 1]:  # Check if any element is less than twice the previous element
            print("YES")
            return  # Exit the program after printing "YES"
    print("NO")  # Print "NO" if no such condition is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
