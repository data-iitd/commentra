import copy

def solve():
    # Read input strings S_d and T
    S_d = list(input())
    T = list(input())

    # Determine the initial indices for the substring search
    end = len(S_d) - 1
    first = end - len(T) + 1

    # Iterate backwards through S_d to find a matching position for T
    while first >= 0:
        t_i = 0  # Index for T
        # Check if T can fit into S_d starting from the current 'first' index
        for s_i in range(first, end + 1):
            # If characters do not match and S_d[s_i] is not a wildcard '?', break
            if T[t_i] != S_d[s_i] and S_d[s_i] != '?':
                break
            t_i += 1
        else:
            # If we completed the loop without breaking, a match was found
            break

        # Move the search window one position to the left
        first -= 1
        end -= 1

    else:
        # If no valid position was found, output 'UNRESTORABLE' and exit
        print('UNRESTORABLE')
        exit(0)
    
    # Create a deep copy of S_d to modify it for the answer
    ans = copy.deepcopy(S_d)
    t_i = 0  # Reset index for T
    # Replace the matched positions in ans with characters from T
    for i in range(first, end + 1):
        ans[i] = T[t_i]
        t_i += 1
    
    # Replace any remaining wildcards '?' in ans with 'a' and join to form the final string
    ans = ''.join(ans).replace('?', 'a')
    # Print the final restored string
    print(ans)

if __name__ == '__main__':
    solve()
