c = [0] * 26

while True:
    try:
        str_input = input()
    except EOFError:
        break

    for p in str_input:
        if 'a' <= p <= 'z':
            c[ord(p) - ord('a')] += 1
        elif 'A' <= p <= 'Z':
            c[ord(p) - ord('A')] += 1

for i in range(26):
    print(f"{chr(ord('a') + i)} : {c[i]}")

# <END-OF-CODE>
