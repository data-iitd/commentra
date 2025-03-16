import java.util.*;
import java.io.*;
public class Main{
 public static void main(String[] args) throws Exception{
  Scanner sc=new Scanner(System.in);
  int h=sc.nextInt();
  int w=sc.nextInt();
  char s[]="snuke";
  char t[]=new char[10];
  for(int i=0;i<h;i++){
   for(int j=0;j<w;j++){
    sc.next();
    t=sc.next().toCharArray();
    if(s[0]==t[0]&&s[1]==t[1]&&s[2]==t[2]&&s[3]==t[3]){
     char c=(char)(j+'A');
     System.out.println(c+""+(i+1));
     return;
    }
   }
  }
 }
}
