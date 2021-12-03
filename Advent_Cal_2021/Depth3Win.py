depthInputs = []

with open ('1inputs.txt') as Depths:
    for input in Depths:
        depthInputs.append(input)

def comparator(input, prev):
    if input > prev:
        return 1
    else:
        return 0

valAfterFor = []
increases = 0

for i in range(0, len(depthInputs)):
    depthInputs[i] = depthInputs[i].strip()

Loners = [0,0,0]
depthInputs.extend(Loners)
#For loop to sum values
#Use a three sliding window to find relivent info

j = 0

while j < (len(depthInputs) - 3):
    sum = int(depthInputs[j]) + int(depthInputs[j+1]) + int(depthInputs[j+2])
    valAfterFor.append(sum)
    j += 1

for k in range(1, len(valAfterFor)):
    prev = valAfterFor[k - 1]
    if comparator(valAfterFor[k], prev) == 1:
        increases += 1

stringInt = str(increases)

print("The Depth increased " + stringInt + " times")