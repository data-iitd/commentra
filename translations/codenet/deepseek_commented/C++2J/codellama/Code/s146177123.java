import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		// Initialize the state array to represent the current display state
		boolean st[]=new boolean[7];
		for(int i=0;i<7;i++)st[i]=false;
		
		// Read the number of digits and check if it's not zero
		int n=Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
		while(n!=0){
			// Initialize the state array to represent the current display state
			for(int i=0;i<7;i++)st[i]=false;
			
			// Read the next digit
			int t=Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
			
			// Array to store the current display state
			char ans[]=new char[8];
			for(int i=0;i<7;i++){
				// Calculate the current segment state and store it in the answer array
				ans[i]=st[i]^seg[t][i]?'1':'0';
				// Update the state array with the current segment state
				st[i]=seg[t][i];
			}
			// Output the current display state
			System.out.println(ans);
		}
	}
	
	// Array to represent the segments of the digits 0-9
	static boolean seg[][]=new boolean[][]{
		{false,true,true,true,true,true,true}, // 0
		{false,false,false,false,true,true,false}, // 1
		{true,false,true,true,false,true,true}, // 2
		{true,false,false,true,true,true,true}, // 3
		{true,true,false,false,true,true,false}, // 4
		
		{true,true,false,true,true,false,true}, // 5
		{true,true,true,true,true,false,true}, // 6
		{false,true,false,false,true,true,true}, // 7
		{true,true,true,true,true,true,true}, // 8
		{true,true,false,true,true,true,true}  // 9
	};
}

