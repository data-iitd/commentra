import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Fast I/O setup
    Scanner in = new Scanner(System.in);
    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    // Declare variables to store input values
    long A,B,C,K;
    A = in.nextLong();
    B = in.nextLong();
    C = in.nextLong();
    K = in.nextLong();

    // Check if the sum of A and B is greater than or equal to K
    if(A+B>=K){
      // Output the minimum of A and K
      out.write(Math.min(A,K)+"\n");
    }else{
      // Calculate the result by subtracting the excess amount from A
      out.write(A-(K-(A+B))+"\n");
    }

    // Close the input and output streams
    in.close();
    try {
      out.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}

