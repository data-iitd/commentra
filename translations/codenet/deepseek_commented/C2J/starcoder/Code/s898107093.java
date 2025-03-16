import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);  // Create a Scanner object
    int n, taro = 0, hanako = 0, i;  // Declare number of rounds, scores, and loop index
    n = in.nextInt();  // Read the number of rounds
    String[] t = new String[n];  // Allocate memory for Tarō's strings
    String[] h = new String[n];  // Allocate memory for Hanako's strings

    // Loop through each round
    for (i = 0; i < n; i++) {
      t[i] = in.next();  // Read Tarō's string
      h[i] = in.next();  // Read Hanako's string
      if (t[i].compareTo(h[i]) < 0) hanako += 3;  // Compare and update Hanako's score
      if (t[i].compareTo(h[i]) > 0) taro += 3;  // Compare and update Tarō's score
      if (t[i].compareTo(h[i]) == 0) {  // If strings are equal
        taro += 1;  // Increment Tarō's score by 1
        hanako += 1;  // Increment Hanako's score by 1
      }
    }

    System.out.println(taro + " " + hanako);  // Print the final scores
  }
}

