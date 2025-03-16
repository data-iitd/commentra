
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Initialize variables for number of students and classes
		int n,m;

		// Read input from the standard input stream
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();

		// Initialize vectors 's' and 'c' for storing student numbers and classes respectively
		int[] s=new int[m];
		int[] c=new int[m];

		// Read student numbers and classes from the standard input stream
		for(int i=0;i<m;i++){
			s[i]=sc.nextInt();
			c[i]=sc.nextInt();
			// Decrement student numbers by 1 as they are 1-indexed
			s[i]--;
		}

		// Check all strings of length 'n' for a valid combination of student numbers and classes
		for(int i=0;i<1000;i++){
			// Convert the current number to a string
			String st=Integer.toString(i);

			// Check if the length of the string is equal to 'n'
			if(st.length()!=n){
				continue;
			}

			// Initialize a flag 'f' to check if the current combination is valid
			int f=1;

			// Check each combination of student number and class
			for(int j=0;j<m;j++){
				// Check if the current character in the string matches the expected class
				if(st.charAt(s[j])==(char)(c[j]+'0')){
					// If yes, continue to the next check
				}else{
					// If no, set the flag 'f' to 0 and break the loop
					f=0;
					break;
				}
			}

			// If all checks passed, print the current number and exit the program
			if(f){
				System.out.println(i);
				return;
			}

		}

		// If no valid combination was found, print -1
		System.out.println(-1);
	}
}

