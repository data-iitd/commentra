
import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a, b, c[] = new int[256];
    char m;
    int i, j;

    // Initialize array c with zeros
    for(i=0; i<256; i++){
      c[i] = 0;
    }

    // Read input values of a, m, and b from the user
    for(i=0; i>=0; i++){
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
