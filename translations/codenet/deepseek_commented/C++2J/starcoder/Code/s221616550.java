import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read the input string from the user
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    // Check if the entire string and its first half are palindromes
    if(isPalindrome(s)&&isPalindrome(s.substring(0,s.length()/2))){
      // Print "Yes" if both conditions are true
      System.out.println("Yes");
    }else{
      // Print "No" if either condition is false
      System.out.println("No");
    }
  }

  // Function to check if a string is a palindrome
  public static boolean isPalindrome(String s){
    // Loop through the first half of the string
    for(int i=0;i<s.length()/2;i++){
      // Compare characters from the start and end of the string
      if(s.charAt(i)==s.charAt(s.length()-1-i)) continue;
      // If any characters do not match, return false
      else return false;
    }
    // If all characters match, return true
    return true;
  }
}
