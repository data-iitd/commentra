def main():
    # Read a long integer from the user
    x = int(input())
    
    # Initialize a list to store the digits after transformation
    list_ = []
    
    # Process each digit of the number until there are no digits left
    while x > 0:
        # Extract the last digit of the number
        r = x % 10
        
        # Determine whether to keep the digit or replace it with its complement to 9
        if 9 - r < r:
            # If the digit is the last one and its complement is 0, keep the digit
            if x // 10 == 0 and 9 - r == 0:
                list_.append(r)
            else:
                # Otherwise, add the complement to the list
                list_.append(9 - r)
        else:
            # If the digit is less than or equal to its complement, keep the digit
            list_.append(r)
        
        # Remove the last digit from the number
        x = x // 10
    
    # Initialize variables to construct the new number
    pow = 0
    new_number = 0
    
    # Reconstruct the new number from the transformed digits
    for i in range(len(list_)):
        new_number += list_[i] * (10 ** pow)
        pow += 1
    
    # Output the newly constructed number
    print(new_number)

if __name__ == "__main__":
    main()
