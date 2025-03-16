import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] alpha = new int[26];
        char ch;

        for(int i = 0; i < 26; i++)alpha[i] = 0;

        while(true){
            ch = sc.next().charAt(0);
            if(ch == 'E')break;

            if(Character.isLetter(ch)){
                if(Character.isUpperCase(ch))alpha[ch - 65]++;
                else alpha[ch - 97]++;
            }
        }

        ch = 'a';
        for(int i = 0; i < 26; i++, ch++){
            System.out.println(ch + " : " + alpha[i]);
        }
    }
}
