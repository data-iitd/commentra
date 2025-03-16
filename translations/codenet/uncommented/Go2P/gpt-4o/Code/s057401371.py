def main():
    s = input()

    d = ord('a') - ord('A')
    result = []
    for r in s:
        rr = r
        if 'A' <= r <= 'Z':
            rr = chr(ord(r) + d)
        elif 'a' <= r <= 'z':
            rr = chr(ord(r) - d)
        result.append(rr)

    print(''.join(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
