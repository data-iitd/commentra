def is_palindrome(s):
    for i in range(len(s) // 2):
        if s[i] == s[len(s) - 1 - i]:
            continue
        else:
            return False
    return True

s = input()
if is_palindrome(s) and is_palindrome(s[:len(s) // 2]):
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
