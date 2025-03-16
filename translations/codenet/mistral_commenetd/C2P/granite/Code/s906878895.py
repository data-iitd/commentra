
# This line includes the standard input/output library

def main(): 
    while True: 
        try: 
            a, b = map(int, input().split()) 
            # Read two integers from the user and assign them to a and b

            x = a + b 
            # Calculate the sum of a and b and assign it to x

            w = 0 
            # Initialize w to zero

            while x > 0: 
                w += 1 
                # Increment w each time through the loop
                x //= 10 
                # Divide x by 10 to get the next digit

            print(w) 
            # Print the value of w, which represents the number of digits in the sum of a and b

        except EOFError: 
            break 
        # This try-except block catches the end of the file and breaks out of the loop

main() 
# Call the main function to start the program

"