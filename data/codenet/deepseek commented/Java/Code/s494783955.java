import java.util.*;  // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args){
    
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object to read input
        String C = sc.next();  // Reading a single string input from the user

        System.out.println((char)(C.charAt(0) + 1));  // Incrementing the ASCII value of the first character by 1 and printing the result
    }
}
