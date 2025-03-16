def main():
    c = []
    while True:
        user_input = input().strip()
        if user_input == '?':
            break
        a, m, b = user_input.split()
        a = int(a)
        b = int(b)
        
        if m == '+':
            c.append(a + b)
        elif m == '-':
            c.append(a - b)
        elif m == '*':
            c.append(a * b)
        elif m == '/':
            c.append(a // b)  # Use integer division

    for result in c:
        print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
