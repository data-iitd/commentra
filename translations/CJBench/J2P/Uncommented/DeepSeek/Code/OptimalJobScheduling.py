def find_min(cost_arr):
    min_index = 0
    for i in range(1, len(cost_arr)):
        if cost_arr[i] < cost_arr[min_index]:
            min_index = i
    return cost_arr[min_index]

def calculate_cost(number_processes, number_machines, run, transfer):
    cost = [[0] * number_machines for _ in range(number_processes)]
    for i in range(number_processes):
        for j in range(number_machines):
            cost[i][j] = running_cost(i, j, number_processes, number_machines, run, transfer, cost)
    return cost

def running_cost(process, machine, number_processes, number_machines, run, transfer, cost):
    if process == 0:
        return run[process][machine]
    else:
        running_costs = [0] * number_machines
        for k in range(number_machines):
            running_costs[k] = cost[process - 1][k] + transfer[k][machine] + run[process][machine]
        return find_min(running_costs)

def show_results(cost):
    for row in cost:
        print(" ".join(map(str, row)))
    print()

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    number_processes = int(data[index])
    index += 1
    number_machines = int(data[index])
    index += 1
    
    run = []
    for i in range(number_processes):
        row = []
        for j in range(number_machines):
            row.append(int(data[index]))
            index += 1
        run.append(row)
    
    transfer = []
    for i in range(number_machines):
        row = []
        for j in range(number_machines):
            row.append(int(data[index]))
            index += 1
        transfer.append(row)
    
    cost = calculate_cost(number_processes, number_machines, run, transfer)
    show_results(cost)

if __name__ == "__main__":
    main()
