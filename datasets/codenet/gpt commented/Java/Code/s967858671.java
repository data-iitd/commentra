import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an array to hold 11 integers
        int[] Num;
        Num = new int[11];

        // Create a Scanner object to read input from the user
        Scanner n = new Scanner(System.in);
        
        // Loop to read 10 integers from user input and store them in the array
        for (int i = 0; i < 10; i++) {
            Num[i] = n.nextInt();
        }
        
        // Sort the array in descending order using a bubble sort algorithm
        for (int a = 9; a >= 0; a--) {
            for (int b = 0; b < a; b++) {
                // Compare adjacent elements and swap if they are in the wrong order
                if (Num[b] < Num[b + 1]) {
                    // Temporarily store the value to swap
                    Num[10] = Num[b];
                    Num[b] = Num[b + 1];
                    Num[b + 1] = Num[10];
                }
            }
        }
        
        // Print the top three largest numbers from the sorted array
        System.out.println(Num[0]);
        System.out.println(Num[1]);
        System.out.println(Num[2]);
    }    
}
