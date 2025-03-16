c = input()
ans = ''
for char in c:
    if char != 'B':
        ans += char
    else:
        ans = ans[:-1]  # Remove the last character
print(ans)
# <END-OF-CODE>
