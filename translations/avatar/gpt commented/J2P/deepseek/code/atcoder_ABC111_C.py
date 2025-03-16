import sys
from collections import Counter

def main():
    # Read the number of elements
    n = int(input().strip())
    
    # Read the integers and store them in a list
    v = list(map(int, input().strip().split()))
    
    # Count occurrences of each number in odd and even indexed positions
    odd_counts = Counter()
    even_counts = Counter()
    total_counts = Counter()
    
    # Count occurrences of each number in odd and even indexed positions
    for i in range(n):
        total_counts[v[i]] += 1
        if i % 2 == 0:
            even_counts[v[i]] += 1
        else:
            odd_counts[v[i]] += 1
    
    # Find the most common elements in odd and even indexed positions
    most_common_odd = odd_counts.most_common(1)[0]
    most_common_even = even_counts.most_common(1)[0]
    most_common_total = total_counts.most_common(1)[0]
    
    # Determine the answer based on the counts of the most frequent elements
    if most_common_odd[1] + most_common_even[1] == most_common_total[1]:
        # If the most frequent odd and even counts sum to the total count
        ans = min(n - most_common_odd[1] - even_counts[most_common_even[0]], 
                  n - most_common_even[1] - odd_counts[most_common_odd[0]])
    else:
        # Otherwise, calculate the answer based on the most frequent counts
        ans = n - most_common_odd[1] - most_common_even[1]
    
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()
