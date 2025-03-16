import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the user
        Scanner s = new Scanner(System.in);
        
        // Read the era (E) and year (Y) from the input
        int E = s.nextInt();   
        int Y = s.nextInt();

        // Check if the era is 0 (indicating the first era)
        if (E == 0) {
            // Determine the corresponding year and print the era label and year difference
            if (Y <= 1911) {
                System.out.print("M"); // M for Meiji
                System.out.println(Y - 1867); // Calculate the year difference from 1867
            } else if (Y <= 1925) {
                System.out.print("T"); // T for Taisho
                System.out.println(Y - 1911); // Calculate the year difference from 1911
            } else if (Y <= 1988) {
                System.out.print("S"); // S for Showa
                System.out.println(Y - 1925); // Calculate the year difference from 1925
            } else {
                System.out.print("H"); // H for Heisei
                System.out.println(Y - 1988); // Calculate the year difference from 1988
            }
        } 
        // Check if the era is 1 (indicating the Meiji era)
        else if (E == 1) {
            System.out.println(1867 + Y); // Calculate and print the year in the Gregorian calendar
        } 
        // Check if the era is 2 (indicating the Taisho era)
        else if (E == 2) {
            System.out.println(1911 + Y); // Calculate and print the year in the Gregorian calendar
        } 
        // Check if the era is 3 (indicating the Showa era)
        else if (E == 3) {
            System.out.println(1925 + Y); // Calculate and print the year in the Gregorian calendar
        } 
        // If the era is not recognized, assume it is the Heisei era
        else {
            System.out.println(1988 + Y); // Calculate and print the year in the Gregorian calendar
        }
    }
}
