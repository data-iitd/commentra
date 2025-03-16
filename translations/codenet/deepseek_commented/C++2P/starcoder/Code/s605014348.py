# Function to find the smallest divisor of a number
def div(n):
	if n%2 == 0: return 2  # Check if the number is even and return 2
	s=math.sqrt(n)
	for i in range(3,int(s)+1,2):  # Check for divisors starting from 3 up to the square root
		if n%i == 0: return i  # Return the first divisor found
	return n  # If no divisor is found, return the number itself

# Read an integer from the user
num = int(input())
print(num,":",end="")

while num!=1:
	print(" ",div(num),end="")  # Print the smallest divisor and update the number
	num = num // div(num)  # Divide the number by its smallest divisor
print()

