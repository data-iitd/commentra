import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a,b; // Declare two integer variables to store user input
    a = sc.nextInt(); // Read an integer value from the user and store it in variable a
    b = sc.nextInt(); // Read another integer value from the user and store it in variable b
    if((a*b)%2 == 0){ // Check if the product of a and b is even or odd
      System.out.println("Even"); // Print "Even" if the product is even
    }else{
      System.out.println("Odd"); // Print "Odd" if the product is odd
    }
  }
}
