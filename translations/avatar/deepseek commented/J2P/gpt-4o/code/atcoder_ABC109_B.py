def main():
    N = int(input())  # Step 1: Read the input value N
    
    map = {}  # Step 2: Initialize a dictionary
    
    for i in range(N):  # Step 3: Read N strings and store them in the dictionary
        map[i] = input()
    
    ans = True  # Step 4: Initialize a boolean variable 'ans'
    past = {}  # Step 5: Initialize another dictionary
    next_char = ""  # Step 6: Initialize a variable 'next'
    
    for i in range(N):  # Step 7: Loop through the strings
        if map[i] in past.values():  # Step 8: Check if the current string has been seen before
            ans = False
            break
        past[i] = map[i]  # Step 9: Store the current string in the 'past' dictionary
        
        if i != 0:  # Step 10: Check if it's not the first string
            if next_char != map[i][0]:  # Check if the starting character matches
                ans = False
                break
        
        next_char = map[i][-1]  # Step 11: Update 'next'
    
    if ans:  # Step 12: Check the value of 'ans'
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
