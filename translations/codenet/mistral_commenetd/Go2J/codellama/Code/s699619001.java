
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize variables D and G to read input from user
        Scanner scanner = new Scanner(System.in);
        int D = scanner.nextInt();
        int G = scanner.nextInt();

        // Create a slice of problem structs with size D
        Problem[] problems = new Problem[D];

        // Read number and bonus for each problem from user and store it in the slice
        for (int i = 0; i < D; i++) {
            problems[i] = new Problem();
            problems[i].number = scanner.nextInt();
            problems[i].bonus = scanner.nextInt();
        }

        // Initialize answer variable ans with a large value
        int ans = 10000;

        // Loop through all possible combinations of problems using binary numbers
        for (int bit = 0; bit < (1 << D); bit++) {
            // Initialize variables score and solved to calculate the score and number of problems solved
            int score = 0;
            int solved = 0;
            // Initialize variable ok to check if the current combination can form a valid solution
            boolean ok = false;

            // Loop through each problem in the slice
            for (int j = 0; j < D; j++) {
                // Check if the current bit is set for the problem j
                if ((bit & (1 << j)) != 0) {
                    // If set, add the score and solved count for the problem
                    score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                    solved += problems[j].number;
                }
            }

            // Check if the current combination can form a valid solution by checking if the score is greater than or equal to G
            if (score < G) {
                // If not, try to add more problems to the current combination to form a valid solution
                int j;
                for (j = D - 1; j >= 0; j--) {
                    // Find the last problem that is not included in the current combination
                    if ((bit & (1 << j)) == 0) {
                        // Loop through each number of the last problem and check if adding it to the current combination forms a valid solution
                        for (int k = 0; k < problems[j].number; k++) {
                            // Add the score and solved count for the problem
                            score += (j + 1) * 100;
                            solved++;
                            // Check if the current combination can form a valid solution
                            if (score >= G) {
                                // If yes, set ok to true and break the inner loop
                                ok = true;
                                break;
                            }
                        }
                        // If adding all numbers of the last problem does not form a valid solution, check if adding the bonus of the last problem forms a valid solution
                        if (problems[j].bonus > 0) {
                            // Add the bonus of the last problem to the score and solved count
                            score += problems[j].bonus;
                            solved++;
                            // Check if the current combination can form a valid solution
                            if (score >= G) {
                                // If yes, set ok to true and break the inner loop
                                ok = true;
                                break;
                            }
                        }
                    }
                    // If a valid solution is found, break the outer loop
                    if (ok) {
                        break;
                    }
                }
            } else {
                // If the current combination forms a valid solution, update the answer variable with the minimum solved count
                ok = true;
            }

            // If the current combination forms a valid solution, update the answer variable
            if (ok) {
                ans = Math.min(ans, solved);
            }
        }

        // Print the answer variable
        System.out.println(ans);
    }

    static class Problem {
        int number;
        int bonus;
    }
}

