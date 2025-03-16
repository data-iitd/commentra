# Define a function to handle the time difference calculation
def main():
    # Input the values of hours and minutes for the first and second time
    h1, m1 = map(int, input("Enter hours and minutes for the first time: ").split())
    h2, m2 = map(int, input("Enter hours and minutes for the second time: ").split())
    
    # Calculate the total minutes of the second time
    ans = h2 * 60 + m2
    print("The total minutes of the second time are:", ans)

    # Subtract the total minutes of the first time from the total minutes of the second time
    ans -= (h1 * 60 + m1)
    print("The difference in minutes is:", ans)

    # Input the difference 'k'
    k = int(input("Enter the value of k: "))
    
    # Subtract the given difference 'k' from the difference in minutes
    ans -= k
    print("The difference in minutes after subtracting", k, "is:", ans)

    # Convert the difference in minutes to hours and minutes
    hours = ans // 60
    minutes = ans % 60

    print(hours, "hours and", minutes, "minutes")  # Output the result

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
