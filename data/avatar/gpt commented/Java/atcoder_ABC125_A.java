import java.util.*; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Reading the number of seconds from user input
        int sec = sc.nextInt();
        
        // Reading the number of items per interval from user input
        int per_num = sc.nextInt();
        
        // Reading the maximum time limit, adding 0.5 to ensure proper rounding
        double max_sec = (double) sc.nextInt() + 0.5;
        
        // Initializing a variable to hold the total count of items
        int ans_num = 0;
        
        // Looping from 'sec' to 'max_sec' in increments of 'sec'
        for (int i = sec; i < max_sec; i += sec) {
            // Accumulating the total number of items produced
            ans_num += per_num;
        }
        
        // Outputting the total number of items produced
        System.out.println(ans_num);
    }
}
