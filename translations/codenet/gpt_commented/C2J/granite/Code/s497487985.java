
import java.util.*;

public class s497487985{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(); // Number of participants
    long k = sc.nextLong(); // Points required to win
    int q = sc.nextInt(); // Number of questions
    int[] a = new int[q]; // Array to store the questions
    long[] point = new long[n]; // Array to track points of each participant

    // Read input values for n, k, and q
    for(int i = 0; i < q; i++){
      a[i] = sc.nextInt(); // Read the participant number for the question
      point[a[i] - 1]++; // Increment the point for the participant who answered
    }

    // Determine if each participant has enough points to win
    for(int i = 0; i < n; i++){
      if(k - (q - point[i]) > 0){ // Check if the participant has enough points
        System.out.println("Yes"); // Participant can win
      }else{
        System.out.println("No"); // Participant cannot win
      }
    }
  }
}
