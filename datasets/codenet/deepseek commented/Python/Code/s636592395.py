
#!python3

# input
N = int(input())  # Read the number of elements
A = list(map(int, input().split()))  # Read the list of elements


def main():
    A.sort()  # Sort the list A in ascending order
    ans = A[-1] - A[0]  # Calculate the difference between the largest and smallest elements
    print(ans)  # Print the result


if __name__ == "__main__":
    main()


