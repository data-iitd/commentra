
import java.util.*;

public class Main {
  // Initialize Scanner to read input from the console
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Read the number of test cases (N) from the input
    int N = sc.nextInt();

    // Initialize two counters for counting the number of even numbers with specific conditions
    int count1 = 0;
    int count2 = 0;

    // Iterate through the input numbers and update the counters accordingly
    for(int i=0;i<N;i++){
      // Read the next integer from the input
      int a = sc.nextInt();

      // If the number is divisible by 4, increment count1
      if(a%4==0){
        count1++;
        // Add a comment explaining the condition for incrementing count1
      }

      // If the number is even and its half is odd, increment count2
      else if(a%2==0 && (a/2)%2==1){
        count2++;
        // Add a comment explaining the condition for incrementing count2
      }
    }

    // Check the conditions for printing "Yes" or "No" based on the counters' values
    if(count1>=N/2){
      // Print "Yes" if count1 is greater than or equal to half of the total numbers (N)
      System.out.println("Yes");
      // Add a comment explaining the condition for printing "Yes"
    }else if(((N/2-count1)*2+N%2)==count2){
      // Print "Yes" if the difference between N/2 and count1 is equal to count2 and N is odd
      System.out.println("Yes");
      // Add a comment explaining the condition for printing "Yes"
    }else{
      // Print "No" if neither of the conditions for printing "Yes" are met
      System.out.println("No");
      // Add a comment explaining the condition for printing "No"
    }
  }
}

