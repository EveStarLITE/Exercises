#Use a three sliding window to find relivent info

depthInputs = []

with open ('1inputs.txt') as Depths:
    for input in Depths:
        depthInputs.append(input)

def comparator(input, prev):
    if input > prev:
        return 1
    else:
        return 0

valAfterFor = [len(depthInputs)+2]
increases = 0


#For loop to sum values

i = len(depthInputs)

while i > 4:
    for j in range(0, len(depthInputs)-1):
        valAfterFor[j] = depthInputs[j] + depthInputs[j+1] + depthInputs[j+2]
        prev = depthInputs[j - 1]
    i -= i 


