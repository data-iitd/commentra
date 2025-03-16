import sys
from collections import Counter

def main():
    # Read the number of elements
    n = int(input().strip())
    
    # Read n integers from input and store them in the list v
    v = list(map(int, input().strip().split()))
    
    # Initialize counters for odd and even indexed positions
    vo = Counter()  # Odd indexed counts
    ve = Counter()  # Even indexed counts
    vt = Counter()  # Total counts
    
    # Count occurrences of each number in odd and even indexed positions
    for i in range(n):
        vt[v[i]] += 1  # Increment total count for the value
        if i % 2 == 0:
            ve[v[i]] += 1  # Increment even indexed count
        else:
            vo[v[i]] += 1  # Increment odd indexed count
    
    # Get the most common elements
    most_common_vo = vo.most_common(2)
    most_common_ve = ve.most_common(2)
    most_common_vt = vt.most_common(1)
    
    # Initialize the answer variable
    ans = 0
    
    if len(most_common_vo) > 0 and len(most_common_ve) > 0:
        if most_common_vo[0][1] + most_common_ve[0][1] == most_common_vt[0][1]:
            # If the most frequent odd and even counts sum to the total count
            ans = min(n - most_common_vo[0][1] - most_common_ve[1][1] if len(most_common_ve) > 1 else 0,
                       n - most_common_vo[1][1] - most_common_ve[0][1] if len(most_common_vo) > 1 else 0)
        else:
            # Otherwise, calculate the answer based on the most frequent counts
            ans = n - most_common_vo[0][1] - most_common_ve[0][1]
    else:
        ans = n  # If there are no odd or even counts, all elements need to be removed
    
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
