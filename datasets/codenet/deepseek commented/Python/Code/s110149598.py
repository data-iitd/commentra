
a,b = input().split()  # Taking input from the user and splitting it into two variables `a` and `b`.

if a < b:  # Comparing `a` and `b` to determine if `a` is less than `b`.
    print("<")  # If `a` is less than `b`, print `<`.
elif a > b:  # Checking if `a` is greater than `b`.
    print(">")  # If `a` is greater than `b`, print `>`.
else:  # If neither of the above conditions are true, then `a` must be equal to `b`.
    print("=")  # Print `=` to indicate that `a` is equal to `b`.

