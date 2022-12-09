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
# def prime_list(n):
#     g = n
#     ans = []
#     nub_list = [19,17,13,11,7,5,3,2]
#     while n != 1:
#         for k in nub_list:
#             if n%k==0:
#                 ans.append(k)
#                 n = int(n/k)
#             else:
#                 nub_list.remove(k)
#     ans = sorted(ans,reverse=True)
#     nub_time = 1
#     if ans:
#         for i in range(0,len(ans)-1):
#             if ans[i+1] != ans[i]:
#                 break
#             nub_time += 1
#         print(g,ans[0],nub_time)
#         return ans[0],nub_time
#     else:
#         return 1,1
# res = 1
# print("from 1 to 20")
# for j in [20,19,18,17,16,15,14,13,11]:
#     res *= pow(*prime_list(j))
# print(res)