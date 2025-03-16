import sys
from collections import Counter

def main():
    n = int(input())  # Read the size of the array
    v = list(map(int, input().split()))  # Read the values into the array

    # Initialize counters for odd and even indexed numbers
    vo = Counter()  # Count for odd indexed numbers
    ve = Counter()  # Count for even indexed numbers
    vt = Counter()  # Count for all numbers

    for i in range(n):
        vt[v[i]] += 1  # Count all numbers
        if i % 2 == 0:
            ve[v[i]] += 1  # Count even indexed numbers
        else:
            vo[v[i]] += 1  # Count odd indexed numbers

    # Get the most common counts
    vo_counts = vo.most_common()
    ve_counts = ve.most_common()
    vt_counts = vt.most_common()

    # Sort counts in descending order
    vo_counts.sort(key=lambda x: x[1], reverse=True)
    ve_counts.sort(key=lambda x: x[1], reverse=True)
    vt_counts.sort(key=lambda x: x[1], reverse=True)

    ans = 0
    if len(vo_counts) > 0 and len(ve_counts) > 0 and vo_counts[0][1] + ve_counts[0][1] == vt_counts[0][1]:
        # Check if the maximum counts are consecutive
        ans = min(n - vo_counts[0][1] - ve_counts[1][1], n - vo_counts[1][1] - ve_counts[0][1]) if len(ve_counts) > 1 and len(vo_counts) > 1 else n - vo_counts[0][1] - ve_counts[0][1]
    else:
        ans = n - vo_counts[0][1] - ve_counts[0][1] if len(vo_counts) > 0 and len(ve_counts) > 0 else n

    print(ans)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
