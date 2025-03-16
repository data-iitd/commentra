import java.util.Scanner;  // Step 1: Include the standard input/output library.
public class Main{  // Step 2: Define the main class.
  public static void main(String[] args){  // Step 3: Define the main function.
    Scanner input = new Scanner(System.in);  // Step 4: Create a Scanner object.
    int a,b,c,x,y;  // Step 5: Declare integer variables a, b, c, x, y.
    a = input.nextInt();  // Step 6: Read values for a, b, c, x, y from the user.
    b = input.nextInt();
    c = input.nextInt();
    x = input.nextInt();
    y = input.nextInt();
    c*=2;  // Step 7: Double the value of c.
    if(a+b<=c)  // Step 8: Check if the sum of a and b is less than or equal to c.
      System.out.println(a*x+b*y);  // Step 9: If true, print the product of a and x plus the product of b and y.
    else{  // Step 10: If false, start the else block.
      if(x<=y){  // Step 11: Check if x is less than or equal to y.
        if(b<=c)  // Step 12: Check if b is less than or equal to c.
          System.out.println(c*x+(y-x)*b);  // Step 13: If true, print the product of c and x plus the product of (y-x) and b.
        else  // Step 14: If false, start the else block.
          System.out.println(c*y);  // Step 15: Print the product of c and y.
      }
      else{  // Step 16: If x is greater than y, start the else block.
        if(a<=c)  // Step 17: Check if a is less than or equal to c.
          System.out.println(c*y+(x-y)*a);  // Step 18: If true, print the product of c and y plus the product of (x-y) and a.
        else  // Step 19: If false, start the else block.
          System.out.println(c*x);  // Step 20: Print the product of c and x.
      }
    }
  }
}
