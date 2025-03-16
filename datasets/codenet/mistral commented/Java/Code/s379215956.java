import java.util.*; // Importing the Utilities package for Scanner class

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input
    String s = sc.next(); // Reading a single string input from the user

    String s1 = s.substring(0,1); // Extracting the first character from the input string
    String s2 = s.substring(1,2); // Extracting the second character from the input string
    String s3 = s.substring(2,3); // Extracting the third character from the input string
    String s4 = s.substring(3,4); // Extracting the fourth character from the input string

    int a = 0; // Initializing an integer variable 'a' with a value of 0

    if(s1.equals(s2)) { // Checking if the first and second characters are equal
      a = 1;
    }

    if(s2.equals(s3)) { // Checking if the second and third characters are equal
      a = 1;
    }

    if(s3.equals(s4)) { // Checking if the third and fourth characters are equal
      a = 1;
    }

    if (a==1) { // Checking if the value of 'a' is equal to 1
      System.out.println("Bad"); // Printing "Bad" to the console if 'a' is equal to 1
    } else {
      System.out.println("Good"); // Printing "Good" to the console if 'a' is not equal to 1
    }
  }
}
