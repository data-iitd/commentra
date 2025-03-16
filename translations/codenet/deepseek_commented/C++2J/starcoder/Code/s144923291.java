import java.util.*;
import java.io.*;
public class Main{
 public static void main(String[] args) throws IOException{
  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
  String s="snuke";
  String[] t=br.readLine().split(" ");
  if(s.equals(t[0])){
   System.out.println((char)(65+Integer.parseInt(t[1]))+t[2]);
  }
 }
}
