
import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // create a Scanner object to read input from the console
    int numberOfTestCases = scanner.nextInt(); // read the number of test cases from the console

    int count = 0; // initialize a counter to count the number of equal elements
    int flag = 0; // initialize a flag to check if we have found at least three equal elements

    while (numberOfTestCases-- > 0) { // decrement the number of test cases and loop until all test cases are processed
      int x = scanner.nextInt(); // read the first integer from the console
      int y = scanner.nextInt(); // read the second integer from the console

      if (x == y) { // check if the two integers are equal
        count++; // increment the counter if they are equal

        if (count >= 3) { // check if we have found at least three equal elements
          flag = 1; // set the flag to 1 if we have found three or more equal elements
        }
      } else {
        count = 0; // reset the counter if the integers are not equal
      }
    }

    if (flag == 0) { // print "No" if we have not found at least three equal elements
      System.out.println("No");
    } else { // print "Yes" if we have found at least three equal elements
      System.out.println("Yes");
    }
  }
}