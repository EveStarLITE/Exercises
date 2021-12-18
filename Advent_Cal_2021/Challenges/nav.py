navy = []

with open ('../Inputs/2inputs.txt') as Instrucs:
    for input in Instrucs:
        navy.append(input)

for i in range(0, len(navy)):
    navy[i] = navy[i].strip()
    navy[i] = navy[i].split(" ")

forwardCord = 0
depth = 0

sub1 = "forward"
sub2 = "down"
sub3 = "up"

for j in range(0, len(navy)):
    if sub1 in navy[j]:
        forwardCord += int(navy[j][1])
    elif sub2 in navy[j]:
        depth += int(navy[j][1])
    elif sub3 in navy[j]: 
        depth -= int(navy[j][1])

print("The Forward Coord is ")
print(forwardCord)
print("The depth is ")
print(depth)

print("Your answer is ")
print(forwardCord * depth)