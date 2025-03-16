#include <stdio.h>
#include <string.h>

public class Main {
	public static void main(String[] args) {
		String str = new String();
		String tmp = new String();
		String p = new String();
		int slen, plen;
		int i, j, flag;
		
		// Read two strings from the user
		str = scan.nextLine();
		p = scan.nextLine();
		
		// Duplicate and concatenate the string
		tmp = str;
		str = str + tmp;
		
		// Calculate the lengths of the strings
		slen = str.length();
		plen = p.length();
		
		// Initialize flag to 0 (not found)
		flag = 0;
		
		// Check if the pattern exists in the concatenated string
		for (i = 0; i < slen - plen; i++) {
			if (str.substring(i, i + plen).equals(p)) flag = 1;
		}
		
		// Output the result
		if (flag) System.out.println("Yes");
		else System.out.println("No");
	}
}

