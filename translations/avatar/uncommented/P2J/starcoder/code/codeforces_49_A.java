import java.util.*;
public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String vowels = "aeiouAEIOU";
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)==''|| s.charAt(i)=='?'){
                continue;
            }
            else{
                if(vowels.contains(s.charAt(i)+"")){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
                break;
            }
        }
    }
}
