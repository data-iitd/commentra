import java.util.Scanner; // Importing Scanner class for user input

public class Main {
    public static void main(String[] args) { // Main method to start the program
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
        String S = scanner.nextLine(); // Reading the first line from user input and storing it in variable S
        String T = scanner.nextLine(); // Reading the second line from user input and storing it in variable T

        // Initializing minimum value with the maximum possible integer value
        int min = Integer.MAX_VALUE;

        // Iterating through all possible substrings of string S that can form a match with string T
        for(int i = 0; i<=S.length()-T.length(); i++){
            // Finding the minimum difference between strings S and T starting from index i
            min = Math.min(min, find(S.substring(i, i+T.length()), T));
        }

        // Checking if the minimum difference is found or not
        if(min!=Integer.MAX_VALUE){
            // Printing the minimum difference if found
            System.out.println(min);
        }else{
            // Printing the length of string T if no match is found
            System.out.println(T.length());
        }
    }

    // Method to calculate the difference between two strings
    public static int find(String a, String b){
        int calc = 0; // Initializing difference counter as 0

        // Iterating through each character of strings a and b
        for(int x = 0; x<a.length(); x++){
            // Incrementing difference counter if corresponding characters are not same
            if(a.charAt(x) != b.charAt(x)){
                calc++;
            }
        }

        // Returning the difference calculated
        return calc;
    }
}
