
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args) throws Exception{
  // Main function declaration

  Scanner sc=new Scanner(System.in); // Create a new instance of Scanner class
  int h=sc.nextInt(); // Read height from standard input
  int w=sc.nextInt(); // Read width from standard input
  String s="snuke"; // Initialize string's'
  String t; // Initialize string 't'
  for(int i=0;i<h;i++){ // Iterate through each row of the grid
   for(int j=0;j<w;j++){ // Iterate through each column of the grid
    t=sc.next(); // Read a character from standard input
    if(s.equals(t)){ // Check if current character matches the pattern'snuke'
     char c=(char)(65+j); // Calculate the column index 'j' of the matching character and convert it to ASCII character
     System.out.println(c+""+i+1); // Print the character and its row number to standard output
     return; // Exit the program if a match is found
    }
   }
  }
 }
}

