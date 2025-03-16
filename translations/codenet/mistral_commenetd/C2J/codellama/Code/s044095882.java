
import java.util.Scanner;

public class CountOccurrences {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of elements: ");
    int n = sc.nextInt();

    int[] a = new int[n];
    int[] count = new int[n];

    System.out.println("Enter " + n + " numbers:");
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    for (int i = 0; i < n; i++) {
      count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      count[a[i] - 1]++;
    }

    for (int i = 0; i < n; i++) {
      System.out.println(count[i]);
    }

    System.out.println("Program completed successfully.");
  }
}

