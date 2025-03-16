def main():
    n = int(input())
    levels = list(map(int, input().split()))
    levels_completed = set(levels)
    additional_levels = list(map(int, input().split()))
    levels_completed.update(additional_levels)
    
    if len(levels_completed) == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()
