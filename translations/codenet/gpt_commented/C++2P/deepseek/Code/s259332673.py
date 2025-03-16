def main():
    # Read input values: start time (h1:m1), end time (h2:m2), and a duration k
    h1, m1, h2, m2, k = map(int, input().split())

    # Calculate the total minutes from the start time to the end time
    total_minutes = (h2 * 60 + m2) - (h1 * 60 + m1)
    
    # Output the result after subtracting the duration k from the total minutes
    print(total_minutes - k)

if __name__ == "__main__":
    main()

