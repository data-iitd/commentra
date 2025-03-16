

a = int(input()) # Reading integer value from the console and assigning it to 'a'
b = input() # Reading String value from the console and assigning it to 'b'

bStr = "" # Initializing empty String variable 'bStr'
for i in range(len(b)):
    # Loop to iterate through each character in String 'b'

    if b[i]!= '.':
        # If current character is not '.', add it to String 'bStr'
        bStr += b[i]

bInt = int(bStr) # Converting String 'bStr' to integer and assigning it to 'bInt'

result = (a * bInt) // 100 # Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to'result'

print(result) # Printing the value of'result' to the console

