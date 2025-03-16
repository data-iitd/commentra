import java.util.*; // Importing the Scanner class for input operations.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input.
        
        int sec = sc.nextInt(); // Reading the first integer input which seems to be a time interval.
        int per_num = sc.nextInt(); // Reading the second integer input which is a number to be added per iteration.
        double max_sec = sc.nextInt() + 0.5; // Reading the third integer input and adding 0.5 to it. This might be a misunderstanding.
        
        int ans_num = 0; // Initializing the variable to store the result of additions.
        
        // Loop to iterate from 'sec' to 'max_sec' in steps of 'sec' and add 'per_num' to 'ans_num' each time.
        for (int i = sec; i < max_sec; i += sec) {
            ans_num += per_num;
        }
        
        System.out.println(ans_num); // Printing the final result after the loop completes.
    }
}
