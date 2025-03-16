MOD = 1000000007  # Defining a constant value for modulus

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Reading the first integer input representing the length of the string
    q = int(data[1])  # Reading the second integer input representing the number of queries
    
    c = data[2]  # Reading the string
    
    range_queries = []  # List to store the range of each query
    index = 3
    for _ in range(q):  # Loop to read the range of each query
        left = int(data[index])  # Reading the starting index of the range
        right = int(data[index + 1])  # Reading the ending index of the range
        range_queries.append((left, right))
        index += 2

    frag = [0] * (n + 1)  # Declaring and initializing an array to store the frequency of 'AC' substring
    rui = [0] * (n + 1)  # Declaring and initializing an array to store the running sum of 'AC' substring frequency

    for i in range(2, n + 1):  # Loop to iterate through the string from index 2 to the end
        if c[i - 2] == 'A' and c[i - 1] == 'C':  # Checking if the current position is an 'AC' substring
            frag[i] += 1  # Incrementing the frequency of 'AC' substring at the current position
        rui[i] = rui[i - 1] + frag[i]  # Updating the running sum of 'AC' substring frequency

    for left, right in range_queries:  # Loop to iterate through each query
        print(rui[right] - rui[left])  # Printing the result of the current query

if __name__ == "__main__":
    main()

# <END-OF-CODE>
