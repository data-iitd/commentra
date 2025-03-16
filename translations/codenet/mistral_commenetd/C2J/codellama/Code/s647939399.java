
public class ArithmeticOperations {
  public static void main(String[] args) {
    // Declare variables
    int a, b, c[256]; // Declare integer variables a, b and array c of size 256
    int i, j; // Declare integer variables i and j
    char m; // Declare character variable m

    // Initialize array c with zeros
    for(i=0; i<256; i++){
      c[i] = 0;
    }

    // Read input values of a, m, and b from the user
    for(i=0; i>=0; i++){
      Scanner sc = new Scanner(System.in);
      a = sc.nextInt();
      m = sc.next().charAt(0);
      b = sc.nextInt();

      // Check if the user has entered '?' to terminate the loop
      if(m=='?'){
        break;
      }

      // Perform arithmetic operations based on the operator m
      if(m=='+'){
        c[i] = a + b; // Store the result of addition in the array c
      }
      if(m=='-'){
        c[i] = a - b; // Store the result of subtraction in the array c
      }
      if(m=='*'){
        c[i] = a * b; // Store the result of multiplication in the array c
      }
      if(m=='/'){
        c[i] = a / b; // Store the result of division in the array c
      }
    }

    // Print the results of the arithmetic operations
    for(j=0; j<i; j++){
      System.out.println(c[j]);
    }
  }
}

