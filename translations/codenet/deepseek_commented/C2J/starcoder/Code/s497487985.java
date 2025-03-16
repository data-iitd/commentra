import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Read input values
    int n = sc.nextInt();
    long k = sc.nextLong();
    int q = sc.nextInt();

    // Process each query to update points
    int[] a = new int[q];
    long[] point = new long[n];
    for(int i = 0; i < q; i++){
      a[i] = sc.nextInt();
      point[a[i] - 1]++; // Update points for the player who answered the query
    }

    // Determine if each player can reach the required points
    for(int i = 0; i < n; i++){
      if(k - (q - point[i]) > 0){
        System.out.println("Yes"); // Player can reach the required points
      }else{
        System.out.println("No"); // Player cannot reach the required points
      }
    }
  }
}
