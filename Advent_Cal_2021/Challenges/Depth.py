#count the number of times a depth measurement increases 

def comparator(input, prev):
    if input > prev:
        return 1
    else:
        return 0

depthInputs = []
increases = 0

with open ('../Inputs/1inputs.txt') as Depths:
    for input in Depths:
        depthInputs.append(input)

#for loop with function of if statment for increase and decrease
for i in range(0, len(depthInputs)):
    prev = depthInputs[i - 1]
    if comparator(depthInputs[i], prev) == 1:
        increases += 1

stringInt = str(increases)

print("The Depth increased " + stringInt + " times")