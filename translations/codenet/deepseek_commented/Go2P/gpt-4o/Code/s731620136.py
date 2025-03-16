import sys
from collections import Counter

def run(input_stream, output_stream):
    # Read the number of elements N and the string S.
    N = int(input_stream.readline().strip())
    S = input_stream.readline().strip()

    if N < 4:
        print(0, file=output_stream)
        return 0

    # Counts the number of 'R', 'B', and 'G' characters in S.
    count = Counter(S)
    nr = count['R']
    nb = count['B']
    ng = count['G']

    # Calculates the number of triplets where the characters are all different.
    same = 0
    for a in range(1, N):
        i = 0
        j = 1 * a
        k = 2 * a
        if k >= N:
            break
        while k < N:
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    # Calculates the total number of possible triplets.
    tot = nr * nb * ng

    # Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
    print(tot - same, file=output_stream)

    return 0

def main():
    run(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
