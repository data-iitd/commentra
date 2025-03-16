
N, L = map(int, input().split())  # User inputs N and L as integers
aji = []                          # Initialize an empty list called 'aji'

for i in range(1, N+1):           # Iterate through the range from 1 to N+1
    aji.append(L+i-1)            # Append each index to the 'aji' list

if min(aji) >= 0:                # Check if the minimum value in 'aji' is non-negative
    index_min = aji.index(min(aji))  # Find the index of the minimum value
    aji.pop(index_min)           # Remove the minimum value from the list

elif max(aji) <= 0:              # Check if the maximum value in 'aji' is non-positive
    index_max = aji.index(max(aji))  # Find the index of the maximum value
    aji.pop(index_max)           # Remove the maximum value from the list

else:                            # If neither the minimum nor the maximum is non-negative or non-positive
    index_min_abs = aji.index(min(aji, key=abs))  # Find the index of the minimum absolute value
    aji.pop(index_min_abs)       # Remove the minimum absolute value from the list

print(sum(aji))                  # Print the sum of the remaining elements in the 'aji' list