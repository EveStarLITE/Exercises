def binaryToDecimal(binary):
     
    binary1 = binary
    decimal, i, n = 0, 0, 0
    while(binary != 0):
        dec = binary % 10
        decimal = decimal + dec * pow(2, i)
        binary = binary//10
        i += 1
    
    return decimal

binaryIN = []

with open ('../Inputs/3inputs.txt') as Nums:
    for Bi in Nums:
        binaryIN.append(int(Bi))

Length = len(binaryIN)

#Set every Byte to a string
for i in range(0, Length):
    binaryIN[i] = str(binaryIN[i])

#goes through the first idex of the String I 
#counts each one and zero
ones = []
zeros = []

for j in range(0, Length):
    oneCount = 0
    zeroCount = 0
    for k in range(0, len(binaryIN[j])):
        if binaryIN[j][k] == '1':
            oneCount += 1 
        else: 
            zeroCount += 1
    ones.insert(j, oneCount)
    zeros.insert(j, zeroCount)

print(zeros)
