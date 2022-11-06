cont = 0

with open("input.txt") as fi:
    N, M = list(map(lambda x: int(x), fi.readline().split()))
    V = list(map(lambda x: int(x), fi.readline().split()))
    for i in range(M):
        a, b = list(map(lambda x: int(x), fi.readline().split()))
        if V[a] and V[b]:
            cont += 1

with open("output.txt", "w") as fo:
    fo.write(str(cont))