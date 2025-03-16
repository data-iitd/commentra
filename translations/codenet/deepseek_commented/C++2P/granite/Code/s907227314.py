
s = input()  # Read input from the user and store it in the string variable's'
a = s.find('A')  # Find the position of the first occurrence of 'A' in the string
z = s.rfind('Z')  # Find the position of the last occurrence of 'Z' in the string
length = z - a + 1  # Calculate the length of the substring between the first 'A' and the last 'Z'
print(length)  # Print the length of the substring
