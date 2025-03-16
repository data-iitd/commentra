#include <stdio.h>
#include <stdlib.h>

public class Main {
	public static void main(String[] args) {
		int i;
		char S[6];
		scanf("%s", S);
		for(i = 0; S[i] != '\0'; i++){
			if(S[i] == 'A' && S[i + 1] == 'C'){
				printf("Yes\n");
				return 0;
			}
		}
		printf("No\n");
		return 0;
	}
}

