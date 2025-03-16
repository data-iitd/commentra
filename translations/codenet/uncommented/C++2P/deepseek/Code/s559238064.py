def main():
    z = input()
    for i in range(len(z) - 1):
        if z[i] == z[i + 1]:
            print("Bad")
            return
    print("Good")

main()
