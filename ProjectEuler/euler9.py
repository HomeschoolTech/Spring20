def triplet():
    summ = 0
    summ_sq = 0
    for c in range(1000):
        for b in range(1000):
#            for a in range(1000):
            a = 1000 - b - c
            if a*a + b*b == c*c and a+b+c==1000:
                return a*b*c
            

x = triplet()
print(x)
