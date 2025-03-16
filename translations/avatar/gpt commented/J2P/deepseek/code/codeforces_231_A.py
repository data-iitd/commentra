def main():
    t = int(input())  # Reading the number of test cases
    count = 0  # Initializing a counter to keep track of valid cases
    
    # Looping through each test case
    for _ in range(t):
        a, b, c = map(int, input().split())  # Reading the three integers
        
        # Checking if at least one of the integers is equal to 1
        if a == 1 and b == 1 or a == 1 and c == 1 or b == 1 and c == 1 or a == 1 and b == 1 and c == 1:
            count += 1  # Incrementing the count if the condition is met
    
    # Outputting the total count of valid cases
    print(count)

if __name__ == "__main__":
    main()
