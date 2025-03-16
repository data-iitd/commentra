
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    // Constants for minimum and maximum base values
    static final int MINIMUM_BASE = 2;
    static final int MAXIMUM_BASE = 36;

    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner in = new Scanner(System.in);
        
        // Read the number to be converted
        String n = in.next();
        
        // Read the source base and validate it
        int b1 = in.nextInt();
        while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b1 = in.nextInt()
        
        # Validate the number for the specified source base
        if not validForBase(n, b1):
            print("The number is invalid for this base!")
            return # Exit if the number is invalid
        
        # Read the target base and validate it
        int b2 = in.nextInt();
        while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b2 = in.nextInt()
        
        # Convert the number from base b1 to base b2
        result = base2base(n, b1, b2)
        
        # Output the converted number
        print("Converted number: " + result)
        
        # Close the scanner to prevent resource leaks
        in.close()
    
    # Method to validate if the number is valid for the given base
    def validForBase(n, base):
        # Define valid digits for bases up to 36
        validDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        
        # Use a set for quick lookup of valid digits
        validDigitsSet = set(validDigits[:base])
        
        # Check if each character in the number is valid for the base
        for char in n.upper():
            if char not in validDigitsSet:
                return False # Return false if an invalid character is found
        
        return True # Return true if all characters are valid
    
    # Method to convert a number from base b1 to base b2
    def base2base(n, b1, b2):
        decimalValue = 0 # Variable to hold the decimal value
        output = "" # String to build the output
        
        # Convert the number from base b1 to decimal
        for charB1 in n.upper():
            # Convert character to its integer value based on the base
            charB2 = ord(charB1) - 48 if charB1.isdigit() else ord(charB1) - 55
            decimalValue = decimalValue * b1 + charB2 # Update decimal value
        
        # Handle the case where the number is zero
        if decimalValue == 0:
            return "0" # Return "0" if the decimal value is zero
        
        # Convert the decimal value to the target base b2
        while decimalValue!= 0:
            remainder = decimalValue % b2 # Get the remainder
            # Convert remainder to the appropriate character and insert at the beginning
            output = chr(remainder + 48 if remainder < 10 else remainder + 55) + output
            decimalValue //= b2 # Update decimal value for the next iteration
        
        return output # Return the final converted number
}

