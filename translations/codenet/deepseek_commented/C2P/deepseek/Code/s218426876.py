def main():
    while True:
        x = input()
        if x[0] == '0':
            break
        sum_digits = sum(int(char) for char in x)
        print(sum_digits)

if __name__ == "__main__":
    main()
