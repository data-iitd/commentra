

number_processes = int(input())
number_machines = int(input())
run = []
for i in range(number_processes):
    run.append([int(x) for x in input().split()])
transfer = []
for i in range(number_machines):
    transfer.append([int(x) for x in input().split()])
cost = [[0 for j in range(number_machines)] for i in range(number_processes)]
for i in range(number_processes):
    for j in range(number_machines):
        if i == 0:
            cost[i][j] = run[i][j]
        else:
            running_costs = [cost[i - 1][k] + transfer[k][j] + run[i][j] for k in range(number_machines)]
            cost[i][j] = min(running_costs)
for i in range(number_processes):
    for j in range(number_machines):
        print(cost[i][j], end=" ")
    print()
