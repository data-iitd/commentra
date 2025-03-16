
import copy
def solve():
    # Read the input strings S_d and T
    S_d = list(input())
    T = list(input())

    # Calculate the range of indices where T can be placed in S_d
    end = len(S_d) - 1
    first = end - len(T) + 1
    
    # Check if T can be placed in S_d at any position within the calculated range
    while first >= 0:
        t_i = 0 
        for s_i in range(first, end+1):
            if T[t_i] != S_d[s_i] and S_d[s_i] != '?':
                break
            t_i += 1
        else:
            break

        first -= 1
        end -= 1

    else:
        # If T cannot be placed in S_d, print 'UNRESTORABLE' and exit
        print('UNRESTORABLE')
        exit(0)
    
    # Create a deep copy of S_d to work on the answer
    ans = copy.deepcopy(S_d)
    t_i = 0
    for i in range(first, end+1):
        ans[i] = T[t_i]
        t_i += 1
    
    # Replace '?' with 'a' in the final answer and print it
    ans = ''.join(ans).replace('?','a')
    print(ans)

if __name__ == '__main__':
    solve()

