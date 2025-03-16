
import java.util.Scanner;

public class s044095882{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] a = new int[n];
    int[] count = new int[n];

    for (int i = 1; i < n; i++)
      a[i] = scanner.nextInt();

    for (int i = 0; i < n; i++)
      count[i] = 0;

    for (int i = 1; i < n; i++)
      count[a[i]-1]++;

    for (int i = 0; i < n; i++)
      System.out.println(count[i]);

    scanner.close();
  }
}
