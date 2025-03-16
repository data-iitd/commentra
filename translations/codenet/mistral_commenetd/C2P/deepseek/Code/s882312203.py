def has_unique_chars(s):
    for i in range(len(s)):
        for j in range(len(s)):
            if i != j and s[i] == s[j]:
                return "no"
    return "yes"

# Read input from the user
s = input()

# Print the result
print(has_unique_chars(s))
