<<<<<<< HEAD
/*
                                                                                                     
                                             `-:://:::-                                             
                                           `//:-------:/:`                                          
                                          .+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .o:--...```..---+/`                                        
                                       `/y+o/---....---:+o.                                         
                                   `...````-os+/:---:/+o/--.`                                       
              `-/+++++/:.      `...`       :h+d+oooo+/+-`   ...                                     
            `/++//:::://++-`....`         -.`//````````:`     `..`                                  
           `o+/::------://o/`           `-` -.          -`       `..`                               
 `---.-o/:./o/::-..``..-ЗАПУСКАЕМ      ..  ..            -`        `...       ``..``                
  `....o+:-++/:--.```..-://s.        `-`  .-              -`          `-o: .-//::::/:-`             
          `:s+/:--....-::/+s-`      .-   `-                -`           -///:--------:/:`           
           ./s+//:::::://oo-``..НЕЙРОННУЮ: СЕТЬ:::::::-`РАБОТЯГИ        `+:--........--:/`          
            .:ooo+++++osso-`    `.:-...`/` ./::-------:/:`   -`         :+--..``````.--:+:...-+:-`  
             `.-/+++++/+-.-`    -.   ``:so:/:--.......--:+`  `-```````o+/+--..`````..--:o/-..:s+:.  
                 ```````:``.. `-`     -` `+:--..`````..--/+-.../.`````..-o:--.......---/o.    `     
                        `:  `:-      -.  .o:--..`` ``..--:o`   `-`      `:o+:--------:+o-`          
                         `-`-...    ..   .o/--...```..--:+/`    `-`     `oy/so/////++o/.`           
                          -/`  `-` `- ``+s/o/:---...---:++.      `-`   .-../d://///:-.`             
                `.---..``-..-    .-/..`````-oo+/:::::/+o+-        `-``-`  `-.  ````                 
             `:++++/+++++-  ..``.-/:`      /y-:/++o++/:.`..`       ./.   `-                         
            -++/::::::://+/..:-``:` ..   `-.`  ```.```    `..`   `..`-` `-                          
       ``  -o//:--....-::/++` -.-`   `-`.-`                 `..`..`  `-.-                           
  -----ss+:++/:--.```..-://s.  /.     `::                    `-:.     ./`                           
  `````/:..+o/::-..``.--:/+s. ..-`   `-``-`                 ..` `-`  `-`-`                          
          `-s+/::-----::/+oo---``-` ..    .:-    ```      .-`     .-.-  `-`                         
           `:oo+//::://+os/..:`..-/:`      :y.-:::::::.`.-`        ./-`  `-`                        
            `./+oooooooo+/.`-    .-:...`.. .//:-------://`        `- `..` `:.                       
              ``.-::::-.``-/`  `-` `-  `oo:+:--.......--:/`      `-    `.:--h.``..```               
                          -.-`.-    .-   `+:--..`````..--//`    `-       /s-//::::::::.             
                         -` `/-      ..  .o:--..`` ``..--:o.```.-        `//:--------://`           
                        -` .-`.-`     -.`-o/--...```..--:+/.``-:....``:-.+:--....`...--:+`          
                       ..`-.   `-.   ``:os:o/:---...---:++.  `-     ``///+:-..``````.--:+-````-.`   
              `.:///////.-`      .:-..` -``-+o+/:::::/+o/.  `-         `:+:-..`````..--:o/:--/ys+-  
            `-++///////+o/. ``....`-.    :` `.:++++++/:.`  .-           -o/---......---/o.   `.`    
           `++//:-----::/+o:..`     .-`   :    ```````    .-           `+so+:--------:++-`          
  `````:-``:o/::-..`..--:/+o`         -.  `-             .-          `../../+o+////+o+:.`           
  -----syo/o+/:--.```..-://s.          .-` `-           .-        `...     ``-:////:-``             
       .` `/s//:--....-::/+s.            -. `-`        .-       `..`                                
           .+o+/:::--:://+s/-..`          .::+y  ```  .-     `..`                                   
            ./oo++////+oso-`   `....       :y-+:::::::/`   ...                                      
             `.:+oooooo/-`         `....-. .//:-------:/:-.`                                        
                ``...``                 /+:+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .+/--...```..--:+/`                                        
                                         `-o/:---...---:++.                                         
                                          `-+o+/:---:/+o/.                                          
                                            `.:+oooo+/-.`                                           
                                               ``````                                               
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

#define MOD 1000000007 // Modulus for operations

// Function to optimize input/output
void fast_io() {
    // No specific optimizations needed for C
}

// Main logic to solve the problem
void solve() {
    long long n; // Number of elements
    scanf("%lld", &n); // Input number of elements
    long long *nums = (long long *)malloc(n * sizeof(long long)); // Array to store the elements
    long long last = 0; // Variable to track the last index
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &nums[i]); // Input each element
    }
    
    // Dynamic programming array to store results
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    dp[0] = 1; // Base case: one way to select zero elements
<<<<<<< HEAD
    long long *kek = (long long *)calloc(n + 1, sizeof(long long)); // Array to store the last occurrence of each number
    long long *prev = (long long *)calloc(n + 1, sizeof(long long)); // Array to store the previous index of each number
    
=======

    // Maps to store the last occurrence and previous index of each number
    long long *kek = (long long *)calloc(n + 1, sizeof(long long)); // Last occurrence
    long long *prev = (long long *)calloc(n + 1, sizeof(long long)); // Previous index

>>>>>>> 98c87cb78a (data updated)
    // Fill the dynamic programming array
    for (long long i = 1; i <= n; i++) {
        // Update dp[i] based on previous values and occurrences
        dp[i] = dp[i - 1] + (prev[nums[i - 1]] != i - 1 ? kek[nums[i - 1]] : 0);
        dp[i] %= MOD; // Apply modulus to avoid overflow
        kek[nums[i - 1]] = dp[i]; // Update the last occurrence
        prev[nums[i - 1]] = i; // Update the previous index
    }
    
    printf("%lld\n", dp[n]); // Output the result

    // Free allocated memory
    free(nums);
    free(dp);
    free(kek);
    free(prev);
}

// Main function
int main() {
    fast_io(); // Optimize input/output
<<<<<<< HEAD
=======
    srand(time(NULL)); // Seed the random number generator
    printf("%.12f\n", 0.0); // Set output precision (not directly applicable in C)
>>>>>>> 98c87cb78a (data updated)
    long long q = 1; // Number of queries
    // Uncomment the following line to read the number of queries
    // scanf("%lld", &q);
    while (q--)
        solve(); // Solve the problem for each query

    return 0;
}
