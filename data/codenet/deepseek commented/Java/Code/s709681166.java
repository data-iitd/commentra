import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        String s = sc.nextLine(); // Reading a line of input from the user
        
        for(int i = 0;i<s.length();i++){ // Looping through each character in the input string
            char c = s.charAt(i); // Getting the character at the current index
            if(Character.isUpperCase(c)){ // Checking if the character is uppercase
                c += 32; // Converting to lowercase by adding 32 to its ASCII value
                System.out.print(c); // Printing the modified character
            }else if(Character.isLowerCase(c)){ // Checking if the character is lowercase
                c -= 32; // Converting to uppercase by subtracting 32 from its ASCII value
                System.out.print(c); // Printing the modified character
            }else{
                System.out.print(c); // Printing the character as it is if it's neither uppercase nor lowercase
            }
        }
        System.out.println(); // Printing a newline character at the end
        sc.close(); // Closing the Scanner object to free up resources
    }
}
