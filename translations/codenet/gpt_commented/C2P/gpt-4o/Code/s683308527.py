def main():
    n = int(input().strip())  # Read the number of lines to process
    for _ in range(n):
        s = input()  # Read a line of input
        while "Hoshino" in s:
            index = s.index("Hoshino")  # Find the index of "Hoshino"
            if index + 6 < len(s):  # Check if there is a character after "Hoshino"
                s = s[:index + 6] + 'a' + s[index + 7:]  # Replace the character after "Hoshino" with 'a'
            else:
                break  # If there's no character after "Hoshino", break the loop
        print(s)  # Print the modified line

if __name__ == "__main__":
    main()

# <END-OF-CODE>
