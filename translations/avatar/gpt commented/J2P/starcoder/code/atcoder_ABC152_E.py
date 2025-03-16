import java.math.*; 
import java.util.*; 
import java.util.function.*; 

def main():
    # Create a Scanner object to read input from the console
    sc = Scanner(System.in); 
    
    # Read the number of elements N
    N = sc.nextInt(); 
    
    # Initialize an array A to hold N integers
    A = [0] * N; 
    
    # Read N integers into the array A
    for i in range(N):
        A[i] = sc.nextInt(); 
    
    # Close the scanner as we no longer need it
    sc.close(); 
    
    # Initialize BigInteger to calculate the least common multiple (LCM)
    lcm = BigInteger.ONE; 
    
    # Calculate the LCM of all elements in the array A
    for ai in A:
        a = BigInteger.valueOf(ai); 
        lcm = lcm.divide(lcm.gcd(a)).multiply(a); 
    
    # Define the modulus value
    mod = 1000000007; 
    
    # Calculate the LCM modulo mod
    modLcm = lcm.remainder(BigInteger.valueOf(mod)).longValue(); 
    
    # Initialize the answer variable to accumulate results
    ans = 0; 
    
    # Calculate the sum of modDiv for each element in A
    for ai in A:
        ans = (ans + modDiv(modLcm, ai, mod)) % mod; 
    
    # Print the final result
    print(ans); 

# Method to perform modular division
def modDiv(a, b, mod):
    return (a % mod) * modInv(b, mod) % mod; 

# Method to compute modular inverse using Fermat's Little Theorem
def modInv(x, mod):
    return modPow(x, mod - 2, mod); 

# Method to perform modular exponentiation
def modPow(b, e, mod):
    ans = 1; 
    x = b % mod; 
    
    # Loop to calculate b^e % mod using exponentiation by squaring
    for y in range(e):
        if ((y & 1) == 1):
            ans = (ans * x) % mod; 
        x = (x * x) % mod; 
    
    # Return the final result of b^e % mod
    return ans; 

if __name__ == "__main__":
    main();

