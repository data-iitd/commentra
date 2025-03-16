# Importing the necessary module for reading input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Reading the first integer input, which represents the number of elements in the array W
    L = int(data[1])  # Reading the first integer parameter, which represents the length of the first segment
    R = int(data[2])  # Reading the second integer parameter, which represents the length of the second segment
    QL = int(data[3])  # Reading the first integer query, which represents the length of the first query segment
    QR = int(data[4])  # Reading the second integer query, which represents the length of the second query segment

    W = [0] * N  # Creating an integer array W of size N
    sum = [0] * (N + 1)  # Creating an integer array sum of size N+1

    for n in range(N):  # Iterating through each element in the array W
        W[n] = int(data[n + 5])  # Reading the integer value of each element in the array W
        sum[n + 1] = sum[n] + W[n]  # Calculating the sum of all elements from 0 to n+1

    min_value = float('inf')  # Initializing the minimum value to be infinity

    for firstR in range(N + 1):  # Iterating through all possible starting indices for the right segment
        lCount = firstR  # The length of the left segment is equal to the index of the starting point of the right segment
        rCount = N - lCount  # The length of the right segment is equal to the total length of the array minus the length of the left segment

        cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R  # Calculating the candidate value for the current combination of left and right segments

        llCount = max(0, lCount - rCount - 1)  # Calculating the length of the overlapping part between the left and right segments, if any
        rrCount = max(0, rCount - lCount - 1)  # Calculating the length of the overlapping part between the right and left segments, if any

        cand += llCount * QL  # Adding the contribution of the left overlapping part to the candidate value
        cand += rrCount * QR  # Adding the contribution of the right overlapping part to the candidate value

        min_value = min(cand, min_value)  # Updating the minimum value if the current candidate value is smaller

    print(min_value)  # Printing the minimum value as the output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
