import sys

def main():
    N = int(input())  # Step 1: Reading the number of elements (N)
    v = [0] * N  # Step 3: Initializing the array

    for _ in range(N):  # Step 4: Reading and counting elements
        a = int(input())
        v[a - 1] += 1

    for e in v:  # Step 5: Writing the results
        print(e)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
