
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    while(n-- > 0){
      String s = sc.nextLine();
      while(s.contains("Hoshino")){
        s = s.replace("Hoshino","aana");
      }
      System.out.println(s);
    }
  }
}

