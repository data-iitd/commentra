import java.util.*; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin

        int i, t, n; // Declare three integer variables: i for the loop counter, t for the user input, and n for the number of items

        // The for loop runs 4 times, each time reading user input and processing it accordingly
        for(i=0; i<4; i++){
            t = sc.nextInt(); // Read an integer from the user and store it in t
            n = sc.nextInt(); // Read an integer from the user and store it in n

            // Check the value of t and process the input accordingly
            if(t==1){
                System.out.println(6000*n); // If t is 1, print the result of multiplying n by 6000 and ending the line
            }
            else if(t==2){
                System.out.println(4000*n); // If t is 2, print the result of multiplying n by 4000 and ending the line
            }
            else if(t==3){
                System.out.println(3000*n); // If t is 3, print the result of multiplying n by 3000 and ending the line
            }
            else if(t==4){
                System.out.println(2000*n); // If t is 4, print the result of multiplying n by 2000 and ending the line
            }
        }
    }
}
