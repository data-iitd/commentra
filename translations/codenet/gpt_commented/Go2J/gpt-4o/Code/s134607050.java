import java.util.Scanner;

public class Main {

    // searchRange finds the range of indices in the text where 'R' and 'L' are located.
    // It returns an array containing the start index, the middle index (first non-'R' character),
    // and the end index (first non-'L' character).
    public static int[] searchRange(String text, int start, int limit) {
        int middle = -1;

        // Find the first index where the character is not 'R'
        for (int i = start; i < limit; i++) {
            if (text.charAt(i) != 'R') {
                middle = i;
                break;
            }
        }

        int end = limit;

        // Find the first index after 'middle' where the character is not 'L'
        for (int i = middle; i < limit; i++) {
            if (text.charAt(i) != 'L') {
                end = i;
                break;
            }
        }

        // Return the start, middle, and end indices
        return new int[]{start, middle, end};
    }

    // answer processes the input text and prints the results based on the 'R' and 'L' characters.
    public static void answer() {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.next();
        int limit = text.length();

        int start = 0;
        int middle = 0;
        int end = 0;
        boolean firstPrinted = false;

        // Loop until the end of the text is reached
        while (end < limit) {
            // Get the range of indices for the current segment of 'R's and 'L's
            int[] range = searchRange(text, start, limit);
            start = range[0];
            middle = range[1];
            end = range[2];

            int len1 = middle - start;
            int len2 = end - middle;

            // Print '0's for the 'R' segment
            for (int i = start; i < middle; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }

            // Calculate counts based on the lengths of the segments
            int count1 = (len1 + 1) / 2 + len2 / 2;
            int count2 = len1 / 2 + (len2 + 1) / 2;

            // Print the counts for the current segment
            if (firstPrinted) {
                System.out.print(" ");
            }
            System.out.printf("%d %d", count1, count2);
            firstPrinted = true;

            // Print '0's for the 'L' segment
            for (int i = middle; i < end; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }
            // Move to the next segment
            start = end;
        }
        // Print a newline at the end of the output
        System.out.println();
    }

    // main function serves as the entry point of the program
    public static void main(String[] args) {
        answer();
    }
}

// <END-OF-CODE>
