
import math
import decimal

try:
    input = float(input())
    countOdd = round(input / 2)
    result = decimal.Decimal(countOdd / input)
    result = result.quantize(decimal.Decimal('1.000000000'))
    print(result)
except:
    print("Error")

