import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] l = s.split("\\.");
        String[] p = l[1].split("");
        int i = Integer.parseInt(p[0]);
        if(s.charAt(s.length()-1) == '9'){
            System.out.println("GOTO Vasilisa.");
        }
        else if(s.charAt(s.length()-1)!= '9' && i < 5){
            System.out.println(s);
        }
        else{
            s = s.substring(0,s.length()-1);
            s = s + (Integer.parseInt(s) + 1);
            System.out.println(s);
        }
    }
}
