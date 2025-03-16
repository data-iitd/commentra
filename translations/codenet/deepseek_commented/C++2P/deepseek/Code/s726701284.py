def main():
    # Step 1: Read a string from the user
    s = input()
    
    # Step 2: Iterate through each letter from 'a' to 'z'
    for i in range(ord('a'), ord('z') + 1):
        # Step 3: Count how many times the current letter appears in the input string
        a = 0
        for j in s:
            if chr(i) == j:
                a += 1
        
        # Step 4: If the letter does not appear in the input string, print it and break out of the loop
        if a == 0:
            print(chr(i))
            break
        
        # Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
        if chr(i) == 'z':
            print("None")
            break

main()
