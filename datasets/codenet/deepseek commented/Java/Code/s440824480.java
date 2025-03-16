import java.util.*;
class Main {
  public static void main(String[] args) {
    // Importing Scanner class to read input from the user
    Scanner sc = new Scanner(System.in);
    // Reading the number of pairs of integers
    int n = sc.nextInt();
    // Initializing counters to 0
    int c = 0;
    int flg = 0;
    // While loop to read pairs of integers
    while (n-- > 0) {
      // Reading two integers x and y
      int x = sc.nextInt();
      int y = sc.nextInt();
      // Checking if x and y are equal
      if (x == y) {
        // Incrementing the counter if they are equal
        c++;
        // Checking if there are 3 or more consecutive equal pairs
        if (c >= 3) {
          flg = 1;
        }
      } else {
        // Resetting the counter if x and y are not equal
        c = 0;
      }
    }
    // Checking the flag and printing the result
    if (flg == 0) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
    }
  }
}
