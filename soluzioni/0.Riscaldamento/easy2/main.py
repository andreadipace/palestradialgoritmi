elementi = []
with open("input.txt") as fi:
    N = int(fi.readline())
    for _ in range(N):
        a, b = list(map(lambda x: int(x), fi.readline().split()))
        if (a + b) % 2 == 0:
            elementi.append(a + b)

coppie_somma_pari = max(elementi)
with open("output.txt", "w") as fo:
    fo.write(coppie_somma_pari)