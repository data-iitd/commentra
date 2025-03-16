import java.util.Map;
import java.util.Scanner;

class Main:
    # A map to convert numbers to their English word representation for numbers 0-100 and multiples of ten
    BASE_NUMBERS_MAP = Map.ofEntries(
        Map.entry(0, ""), Map.entry(1, "One"), Map.entry(2, "Two"), Map.entry(3, "Three"), Map.entry(4, "Four"),
        Map.entry(5, "Five"), Map.entry(6, "Six"), Map.entry(7, "Seven"), Map.entry(8, "Eight"), Map.entry(9, "Nine"),
        Map.entry(10, "Ten"), Map.entry(11, "Eleven"), Map.entry(12, "Twelve"), Map.entry(13, "Thirteen"),
        Map.entry(14, "Fourteen"), Map.entry(15, "Fifteen"), Map.entry(16, "Sixteen"), Map.entry(17, "Seventeen"),
        Map.entry(18, "Eighteen"), Map.entry(19, "Nineteen"), Map.entry(20, "Twenty"), Map.entry(30, "Thirty"),
        Map.entry(40, "Forty"), Map.entry(50, "Fifty"), Map.entry(60, "Sixty"), Map.entry(70, "Seventy"),
        Map.entry(80, "Eighty"), Map.entry(90, "Ninety"), Map.entry(100, "Hundred")
    )

    # A map to represent the powers of thousand in English
    THOUSAND_POWER_MAP = Map.ofEntries(
        Map.entry(1, "Thousand"), Map.entry(2, "Million"), Map.entry(3, "Billion")
    )

    # Private constructor to prevent instantiation of the Main class
    def __init__(self):
        pass

    def main(self):
        # Create a scanner object to read input from the user
        scanner = Scanner(System.in)
        
        # Read an integer input from the user
        number = scanner.nextInt()
        
        # Close the scanner to prevent resource leaks
        scanner.close()
        
        try:
            # Convert the integer to its English word representation
            result = self.integerToEnglishWords(number)
            # Output the result
            print("English Word Representation: " + result)
        except Exception as e:
            # Handle invalid input by printing an error message
            print("Error: " + e.getMessage())

    # Convert a number less than 1000 to its English word representation
    def convertToWords(self, number):
        # Calculate the remainder when divided by 100
        remainder = number % 100
        result = ""
        
        # Handle numbers from 0 to 20 directly
        if remainder <= 20:
            result = self.BASE_NUMBERS_MAP.get(remainder)
        elif self.BASE_NUMBERS_MAP.containsKey(remainder):
            # Handle exact multiples of ten
            result = self.BASE_NUMBERS_MAP.get(remainder)
        else:
            # Handle numbers from 21 to 99
            tensDigit = remainder / 10
            onesDigit = remainder % 10
            tens = self.BASE_NUMBERS_MAP.getOrDefault(tensDigit * 10, "")
            ones = self.BASE_NUMBERS_MAP.getOrDefault(onesDigit, "")
            result = tens
            if not ones.isEmpty():
                result += " " + ones
        
        # Handle hundreds place
        hundredsDigit = number / 100
        if hundredsDigit > 0:
            if result.length() > 0:
                result = " " + result
            result = String.format("%s Hundred", self.BASE_NUMBERS_MAP.get(hundredsDigit)) + result
        
        # Return the constructed word representation
        return result.trim()

    # Convert an integer to its English word representation
    def integerToEnglishWords(self, number):
        # Validate that the number is non-negative
        if number < 0:
            raise Exception("Number must be non-negative.")
        # Handle the special case for zero
        if number == 0:
            return "Zero"
        
        result = ""
        index = 0 # To track the power of thousand
        
        # Process the number in chunks of 1000
        while number > 0:
            remainder = number % 1000 # Get the last three digits
            number /= 1000 # Reduce the number
            
            # Convert the chunk to words if it's greater than zero
            if remainder > 0:
                subResult = self.convertToWords(remainder)
                if not subResult.isEmpty():
                    # Append the appropriate thousand power if necessary
                    if index > 0:
                        subResult += " " + self.THOUSAND_POWER_MAP.get(index)
                    if result.length() > 0:
                        result = " " + result
                    result = subResult + result
            index += 1 # Move to the next thousand power
        
        # Return the final constructed word representation
        return result.trim()

# 