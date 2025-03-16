#######
# Code
#######

# Input the string of numbers separated by spaces and split it into a list
xxs = input().split(" ")

# Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
x, t, a, b, da, db = map(int, xxs[:6])

# Define the main function to perform the logic of the program
void main()
{
    // Check if x is equal to zero
    if (x == 0)
    {
        // If yes, print "YES" and return
        printf("YES");
        return;
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++)
    {
        for (int j = 0; j <= b_time; j++)
        {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x)
            {
                // If yes, print "YES" and return
                printf("YES");
                return;
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if (a - da * i) + (b - db * j) == x)
            {
                // If yes, print "YES" and return
                printf("YES");
                return;
            }
        }
    }

    // If the result is "Result Not Found", print "NO"
    printf("NO");
}

// Call the main function and assign the result to a variable ff
int ff = main();

// If the result is "Result Not Found", print "NO"
if (ff == "Result Not Found")
{
    printf("NO");
}

