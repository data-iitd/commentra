
import java.util.*;
import java.io.*;

public class Main
{
  public static void main(String[] args)
  {
    // Read the input word from the standard input stream using cin
    Scanner cin = new Scanner(System.in);
    String W = cin.next();

    // Sort the characters in the string W in ascending order using the sort function from the Collections library
    Collections.sort(W);

    // Initialize a string iterator named itr to point to the first character in the sorted string W
    Iterator itr = W.iterator();

    // Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
    for (; itr.hasNext(); )
    {
      // Check if the current character and the next character in the string are the same
      if(!itr.next().equals(itr.next()))
      {
        // If they are not the same, print "No" to the standard output stream and return from the main function
        System.out.println("No");
        return;
      }
    }

    // If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
    System.out.println("Yes");
  }
}

