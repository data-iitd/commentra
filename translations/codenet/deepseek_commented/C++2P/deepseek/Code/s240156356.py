def main():
    str1, str2 = input().split()

    # Sort the first string in ascending order
    str1 = sorted(str1)

    # Sort the second string in descending order
    str2 = sorted(str2, reverse=True)

    # Determine the loop limit based on the length of the shorter string
    loop = min(len(str1), len(str2))
    flag = False

    # Compare characters of the two sorted strings
    for i in range(loop):
        ch1 = str1[i]
        ch2 = str2[i]

        # If characters match, continue to the next character
        if ch1 == ch2:
            if i == loop - 1 and len(str1) < len(str2):
                flag = True
                break
            else:
                continue
        else:
            # If characters do not match, check if the character from the second string is greater
            if ch2 > ch1:
                flag = True
                break
            else:
                break

    # Check the flag and print the result
    if flag:
        print("Yes")
    else:
        print("No")

main()
