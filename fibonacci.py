# Recursive approach
def fibonnaci(n):
    # Base case
    if n <= 1:
        return n
    # Recursive case
    else:
        return fibonnaci(n-1) + fibonnaci(n-2)


# Recursive approach with memoization
memo = {0: 0, 1: 1}
def fibonnaci_memo(n):
    # Base case
    if n <= 1:
        return n
    # Recursive case
    try:
        return memo[n]
    except:
        memo[n] = fibonnaci(n-1) + fibonnaci(n-2)
        return memo[n]


# Botton-up approach with a for loop (dynamic programming)
def fibonnaci_bu(n):
    if n <= 1:
        return n
    p1 = 1
    p2 = 0
    for i in range(2, n+1):
        p1 += p2
        p2 = p1 - p2
    return p1


print(fibonnaci(6)) # 8
print(fibonnaci(10)) # 55
print(fibonnaci_memo(6)) # 8
print(fibonnaci_memo(10)) # 55
print(fibonnaci_bu(6)) # 8
print(fibonnaci_bu(10)) # 55
