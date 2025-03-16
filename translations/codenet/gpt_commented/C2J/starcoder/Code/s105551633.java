import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in); // Create a Scanner object
    int64 n=sc.nextLong(); // Read a long long integer from standard input
    int min=digit(n); // Initialize minimum digit count with the digit count of n
    int i;
    for(i=1;(int64)i*i<=n;i++){
      if(n%i!=0) continue;
      int64 a=i;
      int64 b=n/i;
      min=MIN(min,MAX(digit(a),digit(b)));
    }
    System.out.println(min); // Print the minimum digit count found
  }

  // Function to count the number of digits in a given integer
  public static int digit(int64 n){
    int res=0; // Initialize digit count to zero
    while(n>0){
      res++; // Increment digit count
      n/=10; // Remove the last digit
    }
    return res; // Return the total count of digits
  }

  // Function to execute the main logic of the program
  public static void run(void){
    int64 n; // Variable to store the input number
    // Read a long long integer from standard input
    scanf("%lld",&n);
    
    // Initialize minimum digit count with the digit count of n
    int min=digit(n);
    int i;

    // Loop through all possible divisors of n
    for(i=1;(int64)i*i<=n;i++){
      // Skip if i is not a divisor of n
      if(n%i!=0) continue;
      
      // Calculate the corresponding divisor
      int64 a=i;
      int64 b=n/i;

      // Update the minimum digit count based on the digits of the divisors
      min=MIN(min,MAX(digit(a),digit(b)));
    }
    
    // Print the minimum digit count found
    printf("%d\n",min);
  }
}

