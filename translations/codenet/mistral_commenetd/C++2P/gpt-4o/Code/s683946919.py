from collections import defaultdict

# Function to convert date, hour and minute to total minutes
def time2min(month, day, hour, minute):
    total_day_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]  # Total days in each month
    total = 0
    for i in range(1, month):  # Calculate total minutes for each month before the current one
        total += total_day_of_month[i - 1] * 24 * 60
    for i in range(1, day):  # Calculate total minutes for each day before the current one
        total += 24 * 60
    total += hour * 60 + minute  # Calculate total minutes for the current hour and minute
    return total

def main():
    while True:
        N = int(input())  # Read the number of logs from the standard input
        if N == 0:
            break  # If the number of logs is zero, break the loop

        log = defaultdict(list)  # Create a map to store logs for each id
        for _ in range(N):  # Iterate through each log
            month, day, hour, minute, action, id = input().split()  # Read the log entry
            month, day, hour, minute, id = map(int, [month, day, hour, minute, id])  # Convert to integers
            t = time2min(month, day, hour, minute)  # Calculate the total minutes for the log
            log[id].append(t)  # Add the total minutes to the list of logs for the id

        total = [0] * 1000  # Create an array to store the total time spent for each id

        for i in range(0, len(log[0]), 2):  # Iterate through each pair of logs for the id 0
            god_start = log[0][i]  # Get the start time of the first log
            god_end = log[0][i + 1]  # Get the end time of the first log

            for id, schedule in log.items():  # Iterate through each id and its logs
                if id == 0:
                    continue  # If the id is 0, skip the iteration
                for j in range(0, len(schedule), 2):  # Iterate through each pair of logs for the current id
                    ppl_start = schedule[j]  # Get the start time of the first log
                    ppl_end = schedule[j + 1]  # Get the end time of the first log
                    start = max(god_start, ppl_start)  # Get the maximum start time between the logs of god and people
                    end = min(god_end, ppl_end)  # Get the minimum end time between the logs of god and people
                    total[id] += max(0, end - start)  # Calculate and add the total time spent for the current id

        max_v = max(total)  # Find the maximum total time spent
        print(max_v)  # Print the maximum total time spent

if __name__ == "__main__":
    main()

# <END-OF-CODE>
