import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);  // Create a Scanner object to read from the standard input
    int N=sc.nextInt();  // Read the number of movements from the standard input
    for(int i=0;i<N;i++){  // Start a loop that runs N times
      int t=sc.nextInt();  // Read the time for each movement
      int x=sc.nextInt();  // Read the x-coordinate for each movement
      int y=sc.nextInt();  // Read the y-coordinate for each movement
      int tmp=t-(x+y);  // Calculate the difference between the required time and the actual time needed to reach the coordinates
      if(tmp<0 || tmp%2!=0){  // Check if the difference is less than 0 or if it is odd
        System.out.println("No");  // Output "No" and terminate the program
        return;
      }
    }
    System.out.println("Yes");  // If the loop completes without issues, output "Yes"
  }
}
