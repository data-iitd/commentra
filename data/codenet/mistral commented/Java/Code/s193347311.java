
import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
	public static void main(String[] args) { // Starting point of the program
		Scanner scan = new Scanner(System.in); // Creating a new Scanner object for user input
		int intLoop = scan.nextInt(); // Reading the number of loops from the user input

		String strTaro = ""; // Initializing empty strings for storing names
		String strHana = "";
		int intTaro = 0; // Initializing integer variables for storing scores
		int intHana = 0;

		for(int i = 0; i < intLoop; i++){ // Starting a for loop that runs intLoop number of times
			strTaro = scan.next(); // Reading the name of Taro for this iteration
			strHana = scan.next(); // Reading the name of Hana for this iteration

			int intJudge = strTaro.compareTo(strHana); // Comparing the names of Taro and Hana

			if(intJudge < 0){ // If Taro's name comes before Hana's name in the alphabet
				intHana += 3; // Adding 3 to Hana's score
			}else if(intJudge == 0){ // If the names are the same
				intTaro++; // Adding 1 to Taro's score
				intHana++; // Adding 1 to Hana's score
			}else if(0 < intJudge){ // If Taro's name comes after Hana's name in the alphabet
				intTaro += 3; // Adding 3 to Taro's score
			}
		}
		System.out.println(intTaro + " " + intHana); // Printing the final scores of Taro and Hana
		scan.close(); // Closing the Scanner object to save system resources
	}
}

