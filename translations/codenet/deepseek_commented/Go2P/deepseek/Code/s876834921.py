def main():
    s = input()  # Step 1: Reading Input - The program starts by declaring a string variable `s` and using `input()` to read input from the user.

    s = s.replace("dream", "D")  # Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    s = s.replace("erase", "E")

    s = s.replace("Der", "")  # Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    s = s.replace("Er", "")
    s = s.replace("D", "")
    s = s.replace("E", "")

    s = s.strip()  # Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.

    if s == "":  # Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        print("YES")
    else:
        print("NO")

main()
