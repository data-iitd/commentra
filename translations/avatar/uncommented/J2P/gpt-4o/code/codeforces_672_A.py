def generate_string():
    sb = []
    for i in range(1, 1001):
        sb.append(str(i))
    return ''.join(sb)

def main():
    n = int(input())
    print(generate_string()[n - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
