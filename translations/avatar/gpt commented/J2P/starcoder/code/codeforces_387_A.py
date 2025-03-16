import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.time.LocalTime; // Importing LocalTime class to work with time
import java.util.*; // Importing utility classes for using Scanner

def main():
    sc = Scanner(System.in); // Creating a Scanner object to read input from the console
    
    # Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
    s = sc.next().split(":"); 
    t = sc.next().split(":"); 
    
    # Creating LocalTime objects from the input strings for the first and second time
    x = LocalTime.of(int(s[0]), int(s[1])); 
    y = LocalTime.of(int(t[0]), int(t[1])); 
    
    # Calculating the difference between the two times and printing the result
    print(x.minusHours(y.getHour()).minusMinutes(y.getMinute())); 

if __name__ == "__main__":
    main()

