def main():
    # Reading the first integer input, which represents the number of elements in the array W
    N = int(input())
    # Reading the first integer parameter, which represents the length of the first segment
    L = int(input())
    # Reading the second integer parameter, which represents the length of the second segment
    R = int(input())
    # Reading the first integer query, which represents the length of the first query segment
    QL = int(input())
    # Reading the second integer query, which represents the length of the second query segment
    QR = int(input())

    # Creating an integer array W of size N
    W = []
    # Creating an integer array sum of size N+1
    sum_array = [0] * (N + 1)

    # Reading the integer value of each element in the array W
    for n in range(N):
        W.append(int(input()))
        # Calculating the sum of all elements from 0 to n+1
        sum_array[n + 1] = sum_array[n] + W[n]

    # Initializing the minimum value to be the maximum long value
    min_val = float('inf')

    # Iterating through all possible starting indices for the right segment
    for firstR in range(N + 1):
        lCount = firstR
        # The length of the right segment is equal to the total length of the array minus the length of the left segment
        rCount = N - lCount

        # Calculating the candidate value for the current combination of left and right segments
        cand = sum_array[lCount] * L + (sum_array[N] - sum_array[lCount]) * R

        # Calculating the length of the overlapping part between the left and right segments, if any
        llCount = max(0, lCount - rCount - 1)
        # Calculating the length of the overlapping part between the right and left segments, if any
        rrCount = max(0, rCount - lCount - 1)

        # Adding the contribution of the left overlapping part to the candidate value
        cand += llCount * QL
        # Adding the contribution of the right overlapping part to the candidate value
        cand += rrCount * QR

        # Updating the minimum value if the current candidate value is smaller
        min_val = min(cand, min_val)

    # Printing the minimum value as the output
    print(min_val)


main()
