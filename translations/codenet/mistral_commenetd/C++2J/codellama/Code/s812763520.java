import java.util.Scanner; // We import the Scanner class to read input from the user

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // We create a new Scanner object to read input from the user
    int n = sc.nextInt(); // We read the number of elements in the strings from the user input
    String a = sc.next(); // We read the first string from the user input
    String b = sc.next(); // We read the second string from the user input
    String c = sc.next(); // We read the third string from the user input
    int ans = 0; // We initialize an integer variable 'ans' to 0 to store the answer

    for(int i = 0; i < n; i++){ // We start a for loop that iterates from 0 to 'n'-1
      if(a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)){ // We check if all three characters at the current index are equal
      }else if(a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)){ // We check if any two of the three characters are equal
        ans++; // If so, we increment the answer by 1
      }else{ // If none of the above conditions are met, we increment the answer by 2
        ans += 2;
      }
    }
    System.out.println(ans); // We print the answer to the standard output
  }
}

