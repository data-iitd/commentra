import sys

def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize lists to store the input values
    a = [0] * (n + 1)
    b = [0] * (n + 1)
    num = [0] * (n + 1)
    
    # Read the elements of array a
    for i in range(1, n + 1):
        a[i] = int(sys.stdin.readline().strip())
    
    # Read the elements of array b
    for i in range(1, n + 1):
        b[i] = int(sys.stdin.readline().strip())
    
    # Count the occurrences of each element in array b
    for i in range(1, n + 1):
        num[b[i]] += 1
    
    # Initialize variables to store the result
    ss = ""
    ans = 0
    st = [False] * (n + 1)
    
    # Iterate through the elements of array a
    for i in range(1, n + 1):
        if a[i] == 1:
            # Mark the current element as visited
            st[i] = True
            
            # Build the sequence of indices
            sb = []
            x = b[i]
            sss = str(i)
            sb.append(sss[::-1])  # Reverse the index
            s = 1
            
            # Continue building the sequence until a visited element or mismatch is found
            while not st[x] and num[x] == 1 and x != 0 and a[x] != 1:
                sss = str(x)
                sb.append(sss[::-1])  # Reverse the index
                st[x] = True
                x = b[x]
                s += 1
            
            # Update the result if a longer sequence is found
            if s > ans:
                ans = s
                ss = ''.join(reversed(sb))  # Reverse the list to get the correct order
    
    # Print the result
    print(ans)
    print(ss)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
