#######
# Code
#######

// Define input variables
var D, G int

// Initialize list of problems with their respective capacities
var PC [][]int

// Initialize variables for current iteration
var ans int = 1000000000

// Loop through all possible combinations of problems
for i := 0; i < 1 << D; i++ {
    // Initialize variables for current combination
    var score int = 0
    var problem int = 0

    // Calculate score for current combination
    for j := 0; j < D; j++ {
        // If problem j is included in current combination
        if (i >> j) & 1 == 1 {
            // Add score for problem j to the total score
            score += 100 * (j + 1) * PC[j][0] + PC[j][1]
            // Add capacity of problem j to the total problem
            problem += PC[j][0]
        }
    }

    // If score for current combination is greater than goal G, skip to next combination
    if score > G {
        continue
    }

    // Calculate remaining capacity to be covered
    left := G - score

    // Loop through all problems and check if they can be included in the solution
    for j := 0; j < D; j++ {
        // If problem j is already included in current combination, skip it
        if (i >> j) & 1 == 1 {
            continue
        }

        // Check if including problem j can cover the remaining capacity
        if left > 100*(j+1)*PC[j][0]+PC[j][1] {
            pass
        } else {
            // Calculate the number of instances of problem j that can be included
            tmp := (left + (100 * (j + 1) - 1) / (100 * (j + 1)))
            // Update the answer if including more instances of problem j results in a better solution
            ans = min(ans, problem + min(tmp, PC[j][0]))
        }
    }
}

// Print the answer
fmt.Println(ans)


