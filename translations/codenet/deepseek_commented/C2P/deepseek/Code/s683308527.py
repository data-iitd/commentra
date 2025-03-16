def main():
    import sys
    n = int(input().strip())  # Read the number of lines
    for _ in range(n):  # Loop through each line
        s = sys.stdin.readline().strip()  # Read the input line
        while "Hoshino" in s:  # Replace "Hoshino" with "Hoshina"
            s = s.replace("Hoshino", "Hoshina")
        print(s)  # Print the modified line


main()
