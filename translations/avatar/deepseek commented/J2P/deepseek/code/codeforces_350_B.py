import sys

def main():
    # Read the number of elements
    n = int(input().strip())
    
    # Initialize arrays to store the input values
    a = [0] * (n + 1)
    b = [0] * (n + 1)
    num = [0] * (n + 1)
    
    # Read the elements of array a
    a[1:] = list(map(int, input().strip().split()))
    
    # Read the elements of array b
    b[1:] = list(map(int, input().strip().split()))
    
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
            sss = [i]
            sb.append(str(i)[::-1])
            s = 1
            
            # Continue building the sequence until a visited element or mismatch is found
            while not st[x] and num[x] == 1 and x != 0 and a[x] != 1:
                sss = [x]
                sb.append(str(x)[::-1])
                st[x] = True
                x = b[x]
                s += 1
            
            # Update the result if a longer sequence is found
            if s > ans:
                ans = s
                ss = ' '.join(reversed(sb))
    
    # Print the result
    print(ans)
    print(ss)

if __name__ == "__main__":
    main()
