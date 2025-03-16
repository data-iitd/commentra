def main():
    while True:
        try:
            n = int(input())  # Read the size of the arrays
            a = list(map(int, input().split()))  # Initialize array a
            b = [0] * n  # Initialize array b to all zeros
            s = -1  # Initialize the counter s to -1
            
            tem = 1  # Initialize tem to 1
            q = 0  # Initialize q to 0
            
            # Enter a while loop that continues until q equals n
            while q != n:
                s += 1  # Increment the counter s
                
                # If tem is 1, process elements from the start of a to the end
                if tem == 1:
                    for i in range(n):
                        if a[i] <= q and b[i] == 0:
                            b[i] = 1  # Mark the element as processed
                            q += 1  # Increment the processed element counter
                    tem = 0  # Toggle tem to 0
                
                # If tem is 0, process elements from the end of a to the start
                else:
                    for i in range(n - 1, -1, -1):
                        if a[i] <= q and b[i] == 0:
                            b[i] = 1  # Mark the element as processed
                            q += 1  # Increment the processed element counter
                    tem = 1  # Toggle tem to 1
            
            # Print the value of s
            print(s)
        except EOFError:
            break

if __name__ == "__main__":
    main()

