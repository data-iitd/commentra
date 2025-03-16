def main():
    # Read the number of currency entries
    N = int(input())
    
    # Initialize lists to hold the amounts and their corresponding currency units
    x = []
    u = []
    
    # Loop to read each amount and its currency unit
    for _ in range(N):
        amount = float(input())
        currency_unit = input()
        x.append(amount)  # Add the amount to the list
        u.append(currency_unit)  # Add the currency unit to the list
    
    # Calculate the total value in a standard currency and print the result
    print(solve(x, u))

def solve(x, u):
    # Convert each amount to a standard currency and sum them up
    total = sum(amount * (1 if currency == "JPY" else 380000) for amount, currency in zip(x, u))
    return total  # Return the total sum

if __name__ == "__main__":
    main()

# <END-OF-CODE>
