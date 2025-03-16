
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int i, a, b, s; // Declare variables i, a, b, s of integer type
    int count[] = new int[4]; // Declare an array count of size 4 to store the count of each number

    // Initialize the count array with zeros
    for(i = 0;i < 4;i++) count[i] = 0;

    // Read three pairs of numbers from the user and update the count array accordingly
    Scanner sc = new Scanner(System.in);
    for(i = 0;i < 3;i++){
      a = sc.nextInt(); // Read two numbers a and b from the user
      b = sc.nextInt();
      count[a-1]++; // Increment the count of number a in the count array
      count[b-1]++; // Increment the count of number b in the count array
    }

    // Calculate the product of all counts in the count array
    s = 1;
    for(i = 0;i < 4;i++) s *= count[i];

    // Check if the product of all counts is equal to 4
    if(s == 4) System.out.println("YES"); // If yes, print "YES" to the console
    else System.out.println("NO"); // Else, print "NO" to the console
  }
}

