
import java.util.*;
import java.io.*;

class s247537353 {
  public static void main(String[] args) {
    // Fast I/O setup
    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    // Declare variables to store input values
    long A = sc.nextLong();
    long B = sc.nextLong();
    long C = sc.nextLong();
    long K = sc.nextLong();

    // Check if the sum of A and B is greater than or equal to K
    if(A+B>=K){
      // Output the minimum of A and K
      out.println(Math.min(A,K));
    }else{
      // Calculate the result by subtracting the excess amount from A
      out.println(A-(K-(A+B)));
    }

    // Close the output stream
    out.close();
  }
}

Translate the above Java code to Python and end with comment "