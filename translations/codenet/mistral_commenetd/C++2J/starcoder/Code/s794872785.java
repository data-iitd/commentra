
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws java.lang.Exception{
		// Initialize variables
		int maxsize = 0;
		int maxcnt = 0;
		int ans_num = -1;
		int ans_num2 = -1;
		Vector<String> str_v = new Vector<String>(); // Vector to store strings read from input

		// Read strings from input
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			// Push the string into the vector
			str_v.add(sc.next());
			// Update maxsize if the current string is larger
			if(maxsize < str_v.lastElement().length()){
				maxsize = str_v.lastElement().length();
				ans_num = str_v.size()-1;
			}
		}

		// Find the string with maximum occurrences in the vector
		for(int i=0;i<str_v.size();i++){
			int cnt = 0;
			// Count the occurrences of the current string in the vector
			for(int j=0;j<str_v.size();j++){
				if(str_v.get(i).equals(str_v.get(j))) cnt++;
			}
			// Update maxcnt and ans_num2 if the current string has more occurrences
			if(maxcnt < cnt){
				maxcnt = cnt;
				ans_num2 = i;
			}
		}

		// Print the answer
		System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));
	}
}

