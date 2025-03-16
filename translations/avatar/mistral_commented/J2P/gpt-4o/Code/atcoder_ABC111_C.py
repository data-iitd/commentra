import sys
from collections import Counter

def main():
    n = int(input().strip())  # Reading the number of elements 'n' from the standard input stream
    v = list(map(int, input().strip().split()))  # Reading the elements of the array 'v'

    # Counting occurrences of each unique value in odd and even indexed elements
    vo = Counter(v[i] for i in range(0, n, 2))  # Odd indexed elements
    ve = Counter(v[i] for i in range(1, n, 2))  # Even indexed elements
    vt = Counter(v)  # Total occurrences

    # Getting the most common elements and their counts
    vo_counts = vo.most_common()
    ve_counts = ve.most_common()
    vt_counts = vt.most_common()

    # Initialize counts for the first and second most common elements
    vo_first_count = vo_counts[0][1] if vo_counts else 0
    ve_first_count = ve_counts[0][1] if ve_counts else 0
    vo_second_count = vo_counts[1][1] if len(vo_counts) > 1 else 0
    ve_second_count = ve_counts[1][1] if len(ve_counts) > 1 else 0
    vt_first_count = vt_counts[0][1] if vt_counts else 0

    ans = 0  # Declaring an integer variable 'ans' to store the answer

    # Checking if the sum of the first elements of the counts is equal to the first element of the total counts
    if vo_first_count + ve_first_count == vt_first_count:
        # Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts
        ans = min(n - vo_first_count - ve_second_count, n - vo_second_count - ve_first_count)
    else:
        # Calculating the answer as the difference between the counts of the first elements
        ans = n - vo_first_count - ve_first_count

    # Printing the answer to the standard output stream
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
