def main():
    n, m, x = map(int, input().split())  # Step 1: Read the values of n, m, and x
    a = [0] * 105  # Step 2: Initialize array to keep track of positions

    for _ in range(m):
        temp = int(input())  # Read the positions to be marked
        a[temp] = 1  # Step 3: Mark the positions in array a

    ansl = 0  # Initialize variables to store distances
    ansr = 0

    for i in range(x, n + 1):  # Step 4: Calculate the number of marked positions to the right of x
        ansr += a[i]

    for i in range(x, -1, -1):  # Calculate the number of marked positions to the left of x
        ansl += a[i]

    print(min(ansl, ansr))  # Step 5: Print the minimum of the left and right distances

if __name__ == "__main__":
    main()

# <END-OF-CODE>
