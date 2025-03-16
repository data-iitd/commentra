import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Initialize an integer variable 'n' to store the number of elements in the vector 'a'

        // Allocate memory for the ArrayList 'a' of size 'n'
        ArrayList<Integer> a = new ArrayList<>();

        // Read 'n' integers from the standard input and store them in the ArrayList 'a'
        for(int i=0;i<n;i++){
            a.add(scanner.nextInt()); // Read an integer from the standard input and store it in the 'i'-th position of the ArrayList 'a'
        }

        int ans = 0; // Initialize an integer variable 'ans' to store the answer
        boolean ok = true; // Initialize a boolean variable 'ok' to keep track of the loop condition

        // Main logic of the program starts here
        while(ok){
            for(int i=0;i<n;i++){ // Iterate through all the elements in the ArrayList 'a'
                if(a.get(i) % 2 == 1){ // Check if the 'i'-th element of the ArrayList 'a' is odd
                    System.out.println(ans); // If yes, print the answer and exit the program
                    return;
                }
                else{ // If the 'i'-th element of the ArrayList 'a' is even, divide it by 2
                    a.set(i, a.get(i) / 2);
                }
            }
            ans++; // Increment the answer by 1 for each iteration of the outer loop
            ok = false; // Set the loop condition to false to exit the loop if all elements in the ArrayList 'a' become even
        }

        // Print the final answer if all elements in the ArrayList 'a' become even
        System.out.println(ans);
    }
}
