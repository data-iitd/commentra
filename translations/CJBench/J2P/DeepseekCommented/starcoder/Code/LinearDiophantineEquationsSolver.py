# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)
# Read the coefficients a, b, and c from the user
a = sc.nextInt()
b = sc.nextInt()
c = sc.nextInt()
# Create an Equation object with the read coefficients
toSolve = Equation(a, b, c)

