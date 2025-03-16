#include <stdio.h>
#include <string.h>
public class Main {
    public static void main(String[] args) {
        char c[] = new char[11];
        char ans[] = new char[11];
        scanf("%s",c);
        for(int i=0;c[i]!='\0';i++){
            if(c[i]!='B')
                ans[strlen(ans)] = c[i];
            else
                ans[strlen(ans)-1]='\0';
        }
        printf("%s\n",ans);
    }
}
