from collections import defaultdict

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        
        v = [(0, "") for _ in range(n)]  # List to store n pairs
        d = defaultdict(list)  # Dictionary to store indices

        for i in range(n):  # Read m for each element
            v[i] = (0, input().strip())  # Initialize the first element of v to 0 and read the string
            m = int(input())
            for _ in range(m):  # For each m, read an integer and update v and d
                a = int(input())
                v[i] = (v[i][0] + n - len(d[a]), v[i][1])  # Update the first element of v
                for k in d[a]:  # Update the first elements of other v elements
                    v[k] = (v[k][0] - 1, v[k][1])
                d[a].append(i)  # Store the index of the current element in d

        v.sort()  # Sort the list v based on the first element of the tuple
        print(v[0][0], v[0][1])  # Output the first element of v

if __name__ == "__main__":
    main()

# <END-OF-CODE>
