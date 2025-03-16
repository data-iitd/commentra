
import sys;

def convertOctalDigitToBinary(octalDigit):
    binaryDigit = 0; # Initialize binaryDigit to 0
    binaryMultiplier = 1; # Initialize binaryMultiplier to 1

    # Convert an octal digit to its binary equivalent
    while octalDigit!= 0:
        octalDigitRemainder = octalDigit % 2; # Get the last bit of the octal digit
        binaryDigit += octalDigitRemainder * binaryMultiplier; # Add the bit to the binary digit with its weight
        octalDigit /= 2; # Remove the last bit from the octal digit
        binaryMultiplier *= 10; # Multiply the weight of the next bit by 10

    return binaryDigit; # Return the binary digit

def convertMain(octalNumber):
    binaryNumber = 0; # Initialize binaryNumber to 0
    digitPosition = 1; # Initialize digitPosition to 1

    # Convert octal number to binary number
    while octalNumber!= 0:
        octalDigit = octalNumber % 10; # Get the last digit of the octal number
        binaryDigit = convertOctalDigitToBinary(octalDigit); # Convert the octal digit to binary digit
        binaryNumber += binaryDigit * digitPosition; # Add the binary digit to the binary number with its weight
        octalNumber /= 10; # Remove the last digit from the octal number
        digitPosition *= 1000; # Multiply the weight of the next digit by 1000

    return binaryNumber; # Return the binary number

def main():
    # Read an octal number from the console and convert it to binary number
    octalNumber = int(sys.stdin.readline().rstrip("\r\n"));
    binaryNumber = convertMain(octalNumber);

    # Print the binary number to the console
    print("Binary equivalent: " + str(binaryNumber));

if __name__ == "__main__":
    main();

