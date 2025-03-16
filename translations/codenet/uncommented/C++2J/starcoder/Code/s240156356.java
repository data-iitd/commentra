
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();

    char[] ch1 = str1.toCharArray();
    char[] ch2 = str2.toCharArray();

    Arrays.sort(ch1);
    Arrays.sort(ch2);

    int loop = ch1.length > ch2.length? ch2.length : ch1.length;
    boolean flag = false;

    for(int i = 0; loop > i; i++){
      char ch1_ = ch1[i];
      char ch2_ = ch2[i];

      if(ch1_ == ch2_){
        if(loop == i + 1 && ch1.length < ch2.length){
          flag = true;
          break;
        }else{
          continue;
        }
      }else{
        if(ch2_ > ch1_){
          flag = true;
          break;
        }else{
          break;
        }
      }
    }

    if(flag){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}

