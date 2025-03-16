def min(a, b):
    return a if a <= b else b

def chain(b, n):
    a = b[:]  # Copy the original array to a temporary array
    i = 0
    
    while i < n - 4:
        if a[i] != 0 and a[i] == a[i + 1] == a[i + 2] == a[i + 3]:
            count = 0
            color = a[i]
            
            # Remove the chain by setting all elements to 0
            for j in range(i, n):
                if a[j] == color:
                    a[j] = 0
                    count += 1
                else:
                    break
            
            # Shift the remaining elements to fill the gap left by the removed chain
            for j in range(i, n - count):
                a[j] = a[j + count]
            for j in range(n - count, n):
                a[j] = 0
            
            # Reset the index to start checking from the beginning
            i = 0
        else:
            i += 1
    
    count = 0
    while count < n and a[count] != 0:
        count += 1
    
    # Check if the remaining sequence is a chain of four or more elements
    if count == 4 and a[0] == a[1] == a[2] == a[3]:
        return 0
    
    return count

def main():
    while True:
        a = [0] * 10000  # Initialize the array with zeros
        n = int(input())
        if n == 0:
            break
        
        ans = n
        
        # Read the elements themselves
        for i in range(n):
            a[i] = int(input())
        
        # Iterate over possible starting points for chains of four or more elements
        for i in range(n - 4):
            count = [0, 0, 0]  # To count occurrences of each color
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1
            
            color = 0
            for j in range(3):
                if count[j] >= 3:
                    color = j + 1
                    break
            
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j]
                    a[j] = color
                    ans = min(ans, chain(a, n))
                    a[j] = buf
        
        # Print the minimum length after processing
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
