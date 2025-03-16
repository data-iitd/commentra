#include <stdio.h>
#include <string.h>

public class Main {
	public static void main(String[] args) {
		String str = new String();
		String tmp = new String();
		String p = new String();
		int slen, plen;
		int i, j, flag;
		
		str = args[0];
		p = args[1];
		
		tmp = str;
		str += tmp;
		
		slen = str.length();
		plen = p.length();
		
		flag = 0;
		for (i = 0; i < slen - plen; i++) {
			if (str.substring(i, i + plen).equals(p)) flag = 1;
		}
		
		if (flag) System.out.println("Yes");
		else System.out.println("No");
	}
}

