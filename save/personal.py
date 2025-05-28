N     = 200
shape = [
    [0 , 1 , 0] ,
    [0 , 1 , 1] ,
    [1 , 1 , 0]
]
print(f"{N} 0 0")

iter = N-len(shape)

for _ in range(iter//2):
    for i in range(200):
        print("0" , end = ' ')
    print()

for row in shape:
    free = N - len(row)

    for _ in range(free//2):
        print("0" , end = ' ')

    for x in row:
        print(x , end = ' ')

    for _ in range(free//2):
        print("0" , end = ' ')

    print("0"*(free%2))

for _ in range(iter//2 + iter%2):
    for i in range(200):
        print("0" , end = ' ')
    print()

print("\n\t>> Size ; Number of generation ; T0")
print("\t>> Initial lactice")