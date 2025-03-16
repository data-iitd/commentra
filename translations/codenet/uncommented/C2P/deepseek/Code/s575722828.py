def main():
    S = int(input())
    hours = S // 3600
    minutes = (S % 3600) // 60
    seconds = S % 60
    print(f"{hours}:{minutes}:{seconds}")


main()
