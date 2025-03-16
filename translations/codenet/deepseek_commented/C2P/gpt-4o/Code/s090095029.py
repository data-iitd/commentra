# Include standard input-output library
# Include library for boolean types
# Include library for string manipulation

def main():
    n, m = map(int, input().split())  # Read two integers n and m from standard input
    r0 = [False] * n  # Initialize array r0 with false values
    r1 = []  # Initialize array r1
    for _ in range(m):
        a, b = map(int, input().split())  # Read pairs of integers a and b
        if a > b:
            a, b = b, a  # Ensure a is less than or equal to b
        if a == 1:
            r0[b - 1] = True  # If a is 1, set r0[b-1] to true
        if b == n:
            r1.append(a - 1)  # If b is n, add a-1 to r1

    res = any(r0[i] for i in r1)  # Check if any element in r1 has a true in r0
    print("POSSIBLE" if res else "IMPOSSIBLE")  # Print "POSSIBLE" if res is true, otherwise print "IMPOSSIBLE"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
