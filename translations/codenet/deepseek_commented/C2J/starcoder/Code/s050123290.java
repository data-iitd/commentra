import java.util.*;
public class Main{
	public static void main(String[] args){
		// 1. Define the array and variables
		char[] su=new char[N]; // Array to store the sequence of digits
		int susum=0; // Variable to store the sum of the digits
		int j=0; // Index to iterate through the array
		
		while(true){
			// 2. Read input and calculate sum
			for(j=0;j<=N;j++){
				su[j]=(char)System.in.read();
				if(su[j]=='\n')break; // Break if newline character is encountered
				susum=susum+(su[j]-'0'); // Convert character to integer and add to sum
			}	
			if(su[0]=='0')break; // Break if the sequence starts with '0'
			// 3. Print the sum
			System.out.println(susum); // Print the sum of the digits
			susum=0; // Reset the sum for the next sequence
		}
		// 4. Check for termination condition
	}
}
