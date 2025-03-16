def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    A = int(data[0])  # Read A
    B = int(data[1])  # Read B
    C = int(data[2])  # Read C (not used in the logic)
    K = int(data[3])  # Read K

    # Check if the sum of A and B is greater than or equal to K
    if A + B >= K:
        # If true, output the minimum of A and K
        print(min(A, K))
    else:
        # If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
        print(A - (K - (A + B)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
