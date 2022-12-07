# def isOK(n):
#     for n in [1,2,3,4,5,6,7,8,9,10]:

# for i in range(2520,10000):
#     if i    
# print(1*2*3*4*5*6*7*8*9*10)# 3628800

# 11,12,13,14,15,16,17,18,19,20
# no need consider 1~10
# print(11*12*13*14*15*16*17*18*19*20)# 670442572800

# 2.4 GHz 8-Core Intel Core i9 37s 232792560
# for i in range(2520,670442572800):
#     flag = False
#     for j in [11,12,13,14,15,16,17,18,19,20]:
#         if i % j != 0: 
#             break
#         if j == 20:
#             flag = True
#     if flag:
#         print(i)
#         break
def prime_list_max(n):
    max = 2
    for k in [3,5,7,11,13,17,19]:
        max = k if n%k==0 else max
    print(max)
    return max
res = 1

for i in range(1,20+1):
    res *=prime_list_max(i)
print(res)