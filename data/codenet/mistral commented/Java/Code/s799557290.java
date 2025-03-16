import java.util.*; // Importing the utility class Scanner from the java.util package

public class Main {
    public static void main(String[] args) { // Main method where the execution of the program starts
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input

        int a = sc.nextInt(); // Reading the first integer value from the standard input and assigning it to the variable 'a'
        int b = sc.nextInt(); // Reading the second integer value from the standard input and assigning it to the variable 'b'

        boolean ju[] = new boolean[100001]; // Declaring and initializing a boolean array 'ju' of size 100001 with all elements set to false
        int pe[] = new int[100001]; // Declaring and initializing an integer array 'pe' of size 100001 with all elements set to zero
        int wa = 0; // Initializing an integer variable 'wa' with value 0
        int ac = 0; // Initializing an integer variable 'ac' with value 0

        for(int i=0; i<b; i++){ // Loop to read b test cases
            int n = sc.nextInt(); // Reading an integer value from the standard input and assigning it to the variable 'n'
            String res = sc.next(); // Reading a string value from the standard input and assigning it to the variable 'res'

            if(res.equals("WA") && ju[n-1] != true){ // Checking if the result is "WA" and the corresponding index in 'ju' array is not already marked as true
                pe[n-1]++; // If true, increment the value of the corresponding index in 'pe' array
            }

            if(res.equals("AC")){ // Checking if the result is "AC"
                ju[n-1] = true; // If true, mark the corresponding index in 'ju' array as true
            }
        }

        for(int i=0; i<a ; i++){ // Loop to calculate the total number of WA and AC for the first a test cases
            if(ju[i]){ // Checking if the index in 'ju' array is marked as true
                ac++; // If true, increment the value of 'ac'
                wa += pe[i]; // If true, add the number of WA for the corresponding test case to the 'wa' variable
            }
        }

        System.out.println(""+ac+" "+wa); // Printing the total number of AC and the total number of WA for the first a test cases
    }
}
