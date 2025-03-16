import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Read the number of rounds to be played
        int intLoop = scan.nextInt();
        
        // Initialize strings to hold the names of Taro and Hana
        String strTaro = "";
        String strHana = "";
        
        // Initialize scores for Taro and Hana
        int intTaro = 0;
        int intHana = 0;

        // Loop through the number of rounds
        for(int i = 0; i < intLoop; i++){
            // Read the names for this round
            strTaro = scan.next();
            strHana = scan.next();
            
            // Compare the two names
            int intJudge = strTaro.compareTo(strHana);
            
            // Update scores based on the comparison result
            if(intJudge < 0){
                // If Taro's name is lexicographically less than Hana's, Hana gets 3 points
                intHana += 3;
            } else if(intJudge == 0){
                // If the names are equal, both Taro and Hana get 1 point each
                intTaro++;
                intHana++;
            } else if(0 < intJudge){
                // If Taro's name is lexicographically greater than Hana's, Taro gets 3 points
                intTaro += 3;
            }
        }
        
        // Print the final scores of Taro and Hana
        System.out.println(intTaro + " " + intHana);
        
        // Close the scanner to prevent resource leaks
        scan.close();
    }
}
