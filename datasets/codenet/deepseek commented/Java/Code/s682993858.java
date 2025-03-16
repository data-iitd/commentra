import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); // Initializing a Scanner object to read input
        while(true){ // Starting an infinite loop
            int sum = 0; // Initializing sum to accumulate the sum of digits
            String s = sc.next(); // Reading a string input from the user
            if(s.equals("0")) break; // Breaking the loop if the input is "0"
            for(int i=0;i<s.length();i++){ // Iterating over each character in the string
                char a = s.charAt(i); // Getting the character at position i
                sum += a - '0'; // Converting the character to its integer value and adding it to sum
            }
            System.out.printf("%d\n", sum); // Printing the sum of the digits
        }
    }
}
