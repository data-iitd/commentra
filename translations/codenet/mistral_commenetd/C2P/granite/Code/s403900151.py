
# The main function is the entry point of the program
def main():
  n,r,p,c = 0,0,0,0 # Declare variables n, r, p, c of type int
  i,j,k,l = 0,0,0,0 # Declare variables i, j, k, l of type int
  a = [0]*51 # Declare arrays a and b of size 51
  b = [0]*51 # Declare arrays a and b of size 51

  # An infinite loop until the user inputs 0 for both n and r
  while( 1 ):
    n,r = map(int,input().split()) # Read the values of n and r from the standard input
    if( n==0 and r==0 ) # Check if both n and r are 0
      break # If yes, break out of the loop

    # Initialize array a with values from 1 to n
    for i in range(n):
      a[i]=i+1

    # Iterate r times
    for i in range(r):
      p,c = map(int,input().split()) # Read the values of p and c from the standard input

      # Initialize array b with elements from array a
      for j in range(c):
	b[j] = a[n-p-c+1+j]

      # Shift elements of array a to the left by p-1 positions
      for j in range(p-1):
	a[n-p+j+1] = a[n-p+j]

      # Copy elements from array b to the end of array a
      for j in range(n-p-c+1,n-p-c+1+c):
	a[j] = b[j-n+p+c-1]

      # Print the last element of array a
      print(a[n-1])

  return 0

# Call the main function
if __name__ == "__main__":
  main()

