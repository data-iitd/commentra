def time2min(month, day, hour, minute):
    # Array containing the total days in each month
    total_day_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total = 0

    # Calculate total minutes for the months before the given month
    for i in range(1, month):
        total += total_day_of_month[i - 1] * 24 * 60
    
    # Add total minutes for the days before the given day
    for i in range(1, day):
        total += 24 * 60
    
    # Add minutes for the given hour and minute
    total += hour * 60 + minute

    return total  # Return total minutes

def main():
    while True:
        N = int(input())
        if N == 0:
            break  # Exit if N is zero

        # Dictionary to store the log entries for each ID
        log = {}
        for _ in range(N):
            entry = input().strip().split()
            month, day = map(int, entry[0].split('/'))
            hour, minute = map(int, entry[1].split(':'))
            action = entry[2]
            id = int(entry[3])
            
            # Convert the date and time to total minutes and store in the log
            t = time2min(month, day, hour, minute)
            if id not in log:
                log[id] = []
            log[id].append(t)

        # Array to keep track of total overlap time for each ID
        total = [0] * 1000  # Initialize total array to zero
        
        # Calculate overlap time for the "god" (ID 0) and other IDs
        if 0 in log:
            for i in range(0, len(log[0]), 2):
                god_start = log[0][i]  # Start time for god
                god_end = log[0][i + 1]  # End time for god

                # Iterate through each log entry
                for id, schedule in log.items():
                    if id == 0:
                        continue  # Skip the god's own log

                    # Calculate overlap time for each pair of start and end times
                    for j in range(0, len(schedule), 2):
                        ppl_start = schedule[j]  # Start time for the person
                        ppl_end = schedule[j + 1]  # End time for the person
                        start = max(god_start, ppl_start)  # Calculate the maximum start time
                        end = min(god_end, ppl_end)  # Calculate the minimum end time
                        total[id] += max(0, end - start)  # Add the overlap time to the total

        # Find the maximum overlap time among all IDs
        max_v = max(total)

        # Output the maximum overlap time
        print(max_v)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
