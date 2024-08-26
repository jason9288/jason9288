import sys
def count_f(list):
    cnt = 0
    for i in range(1, 10):
        if i in list:
            cnt += 1
    return cnt

n = int(input())
fruit = list(map(int, sys.stdin.readline().split()))

#two-pointer
left = 0
right = 0
cnt = {}
max_len = 0

while right < len(fruit):
    if fruit[right] in cnt:
        cnt[fruit[right]] += 1
    else:
        cnt[fruit[right]] = 1
    
    while len(cnt) > 2:
        cnt[fruit[left]] -= 1
        if cnt[fruit[left]] == 0:
            del cnt[fruit[left]]
        left += 1
    
    max_len = max(max_len, right-left+1)
    right += 1

print(max_len)