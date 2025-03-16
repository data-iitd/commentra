import sys

def main():
    n = int(input().strip())  # Read the size of the array
    a = list(map(int, input().strip().split()))  # Read the array elements
    a.sort()  # Sort the array
    for i in range(n - 1):
        if a[i + 1] < a[i] * 2 and a[i] != a[i + 1]:  # Check if any element is less than twice the previous element
            print("YES")
            return  # Exit the program after printing "YES"
    print("NO")  # Print "NO" if no such condition is found

if __name__ == "__main__":
    main()
