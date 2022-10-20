import random
###########################
########### setup
###########################
# Ideja: https://www.youtube.com/watch?v=pKO9UjSeLew&ab_channel=JomaTech
n=7
s = set(range(1,n ))
l=[random.randint(1, n-1) for x in range(n)]
print(l)

# def findDuplicate(nums):
#     tortoise = nums[0]
#     hare = nums [0]
#     while True:
#         tortoise = nums[tortoise]
#         hare = nums[nums[hare]]
#         if tortoise == hare:
#             break
    
#     ptr1 = nums[0]
#     ptr2 = tortoise
#     while ptr1 != ptr2:
#         ptr1 = nums[ptr1]
#         ptr2 = nums[ptr2]
    
#     return ptr1


###########################
########### atrodi dubultos
###########################
# Atrodi visus dubultos skaitļus un ievieto tos doubles listē
# l ir 7 gara liste ar numuriem 1-6 => būs vienmēr situacija
# kad būs dubulti skaitļi
# s ir set ar numuriem 1-6
doubles=[]
# TODO

seen = set()
doubles = []

for x in l:
    if x in seen:
        doubles.append(x)
    else:
        seen.add(x)

print(doubles)


    