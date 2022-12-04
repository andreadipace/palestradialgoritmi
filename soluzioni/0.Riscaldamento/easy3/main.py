with open("input.txt") as fi:
    fi.readline()
    N = list(map(lambda x: int(x), fi.readline().split()))

P = list(filter(lambda x: x % 2 == 0, N))
D = list(filter(lambda x: x % 2 == 1, N))

sumP, sumD = -1, -1    
if len(P) >= 2:
    sumP = P[-1] + P[-2]
if len(D) >= 2:
    sumD = D[-1] + D[-2]

maxx = max(sumP, sumD)

with open("output.txt", "w") as fo:
    fo.write(str(maxx))