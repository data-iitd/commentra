import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the console
    Scanner sc = new Scanner(System.in);
    
    // Read the number of integers to process
    int N = sc.nextInt();
    
    // Initialize counters for numbers divisible by 4 and specific even numbers
    int count1 = 0;
    int count2 = 0;
    
    // Loop through N integers to classify them
    for(int i = 0; i < N; i++) {
      // Read the next integer
      int a = sc.nextInt();
      
      // Check if the number is divisible by 4
      if(a % 4 == 0) {
        count1++; // Increment count1 for numbers divisible by 4
      } 
      // Check if the number is even and half of it is odd
      else if(a % 2 == 0 && (a / 2) % 2 == 1) {
        count2++; // Increment count2 for specific even numbers
      }
    }
    
    // Check if the count of numbers divisible by 4 is at least half of N
    if(count1 >= N / 2) {
      System.out.println("Yes"); // Output "Yes" if condition is met
    } 
    // Check if the remaining numbers can be satisfied by count2
    else if(((N / 2 - count1) * 2 + N % 2) == count2) {
      System.out.println("Yes"); // Output "Yes" if this condition is met
    } 
    // If neither condition is met, output "No"
    else {
      System.out.println("No");
    }
  }
}
