import java.util.Scanner; // Importing the Scanner class for input

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in); // Initialize Scanner object to read input
		int intLoop = scan.nextInt(); // Read the number of rounds
		String strTaro = ""; // Declare a variable to store Taro's name
		String strHana = ""; // Declare a variable to store Hana's name
		int intTaro = 0; // Declare a variable to store Taro's score
		int intHana = 0; // Declare a variable to store Hana's score

		for(int i = 0; i < intLoop; i++){ // Loop for the number of rounds
			strTaro = scan.next(); // Read Taro's name
			strHana = scan.next(); // Read Hana's name
			int intJudge = strTaro.compareTo(strHana); // Compare Taro's and Hana's names
			if(intJudge < 0){ // If Taro's name is lexicographically before Hana's
				intHana += 3; // Increment Hana's score by 3
			}else if(intJudge == 0){ // If Taro's name is the same as Hana's
				intTaro++; // Increment Taro's score by 1
				intHana++; // Increment Hana's score by 1
			}else if(0 < intJudge){ // If Taro's name is lexicographically after Hana's
				intTaro += 3; // Increment Taro's score by 3
			}
		}
		System.out.println(intTaro + " " + intHana); // Print the final scores
		scan.close(); // Close the Scanner to free up resources
	}
}
