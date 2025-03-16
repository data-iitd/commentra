
// +build ignore

import java.io.*;
import java.util.*;

public class s731620136{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        //... (empty block for N == 0 case)

        if (N < 4) { // Check if N is less than 4
            System.out.println(0); // Print 0 if N is less than 4
            return; // Return from the main method
        }

        //... (variable initialization block)

        int nr = 0, nb = 0, ng = 0; // Initialize variables for red, blue, and green balls

        for (int i = 0; i < N; i++) { // Iterate through each index i from 0 to N-1
            char c = sc.next().charAt(0); // Read the character at index i from input

            if (c == 'R') { // If the character is 'R'
                nr++; // Increment the nr counter
            }

            if (c == 'B') { // If the character is 'B'
                nb++; // Increment the nb counter
            }

            if (c == 'G') { // If the character is 'G'
                ng++; // Increment the ng counter
            }
        }

        int same = 0; // Initialize a counter for the number of same-colored groups of three balls

        //... (outer loop block)

        for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
            int i = 0, j = a, k = 2 * a; // Initialize indices i, j, and k

            //... (inner loop block)

            while (k < N) { // Iterate through each index k from a*2 to N-1
                //... (check condition block)

                if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) { // Check if the balls at indices i, j, and k have different colors
                    same++; // If so, increment the same counter
                }

                //... (update indices block)

                i++; // Increment index i
                j++; // Increment index j
                k++; // Increment index k
            }
        }

        int tot = nr * nb * ng; // Calculate the total number of balls

        //... (comment out or remove the following lines as they are not used in the final solution)

        // int tot = 0; // Initialize a variable for the total number of balls
        // int sum = 0; // Initialize a variable for the number of distinct triples
        // int sum2 = 0; // Initialize a variable for the number of distinct triples with the same middle index

        //... (calculate the final result)

        System.out.println(tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls
    }
}



