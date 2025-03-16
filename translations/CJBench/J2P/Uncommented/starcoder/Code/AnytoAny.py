
import sys

def convertBase(sourceNumber, sourceBase, destBase):
    if sourceBase < 2 or sourceBase > 10 or destBase < 2 or destBase > 10:
        raise Exception("Bases must be between 2 and 10.")
    decimalValue = toDecimal(sourceNumber, sourceBase)
    return fromDecimal(decimalValue, destBase)

def toDecimal(number, base):
    decimalValue = 0
    multiplier = 1
    while number!= 0:
        decimalValue += (number % 10) * multiplier
        multiplier *= base
        number /= 10
    return decimalValue

def fromDecimal(decimal, base):
    result = 0
    multiplier = 1
    while decimal!= 0:
        result += (decimal % base) * multiplier
        multiplier *= 10
        decimal /= base
    return result

if __name__ == "__main__":
    try:
        sourceNumber = int(sys.argv[1])
        sourceBase = int(sys.argv[2])
        destBase = int(sys.argv[3])
        result = convertBase(sourceNumber, sourceBase, destBase)
        print("Converted number: " + str(result))
    except Exception as e:
        print("Error: " + str(e))

