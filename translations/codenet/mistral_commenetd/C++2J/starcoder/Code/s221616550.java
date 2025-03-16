import java.util.*;

public class Main{
  public static void main(String[] args){
    // Declare a string variable to store user input
    String s;
    // Take user input and store it in the string variable
    Scanner sc = new Scanner(System.in);
    s = sc.nextLine();
    // Check if the given string is a palindrome and its first half is also a palindrome
    if(isPalindrome(s) && isPalindrome(s.substring(0,s.length()/2))){
      // If yes, print "Yes"
      System.out.println("Yes");
    }else{
      // If no, print "No"
      System.out.println("No");
    }
  }

  // Function to check if a given string is a palindrome
  public static boolean isPalindrome(String s){
    // Iterate through the first half of the string
    for(int i=0; i<s.length()/2; i++){
      // Check if the character at current index is same as its mirror index
      if(s.charAt(i)==s.charAt(s.length()-1-i)){
        // If yes, continue to next character
        continue;
      }else{
        // If no, return false as the string is not a palindrome
        return false;
      }
    }
    // If we reach here, it means all characters in the first half are same as their mirror index
    // So, the string is a palindrome
    return true;
  }
}
