def main():
    in_values = list(map(int, input().split()))
    in_values.sort()

    result = in_values[2] * 10 + in_values[1] + in_values[0]
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
