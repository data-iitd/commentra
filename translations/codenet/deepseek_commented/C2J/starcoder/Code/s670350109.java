import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str1,str2,temp;
        int i,j=0,t;
        // Read the first string from the user input
        str1=sc.next();
        // Read the second string from the user input
        str2=sc.next();
        // Calculate the length of the first string
        i=str1.length();
        // Initialize the index for reversing the first string
        t=i-1;
        // Check if the lengths of the two strings are not equal
        if(str1.length()!=str2.length())
        {
            // Print "NO" if the lengths are not equal
            System.out.println("NO");
        }
        else
        {
            // Reverse the first string and store it in temp
            while(str1.charAt(j)!='\0')
            {
                temp=temp+str1.charAt(t);
                j++;
                t--;
            }
            // Reset the index for comparing the strings
            t=0;
            i=0;
            // Compare each character of the reversed string and the second string
            while(temp.charAt(i)!='\0')
            {
                if(temp.charAt(i)==str2.charAt(i))
                {
                    t++;
                }
                i++;
            }
            // Check if the number of matching characters is equal to the length of the second string
            if(str2.length()==t)
            {
                // Print "YES" if all characters match
                System.out.println("YES");
            }
            else
            {
                // Print "NO" if not all characters match
                System.out.println("NO");
            }
        }
    }
}
