import sys

def main():
    A, B, C, D, E, F = map(int, sys.stdin.readline().split())

    max_density = -1
    water_amount = 0
    sugar_amount = 0

    for i in range(F // (100 * A) + 1):
        for j in range(F // (100 * B) + 1):
            for k in range(F // C + 1):
                for l in range(F // D + 1):
                    total_weight = (A * 100 * i + B * 100 * j) * k + (C * k + D * l)
                    if total_weight == 0 or total_weight > F:
                        continue
                    sugar_weight = C * k + D * l
                    if sugar_weight > (A * 100 * i + B * 100 * j) * E / 100:
                        continue
                    density = sugar_weight / total_weight
                    if density > max_density:
                        max_density = density
                        water_amount = total_weight
                        sugar_amount = sugar_weight

    if water_amount == 0:
        water_amount = 100 * A

    print(water_amount, sugar_amount)

if __name__ == "__main__":
    main()
