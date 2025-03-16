s = input()  # Read the input string from standard input

for i in range(len(s)):  # Iterate over each character in the string
    if s[i] in s[i + 1:]:  # Check if the character appears again in the substring
        print("no")  # If it does, print "no" and exit
        exit()

print("yes")  # If no character appears again, print "yes"
# <END-OF-CODE>
