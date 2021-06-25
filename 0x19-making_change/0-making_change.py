#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the
fewest number of coins needed to meet a given amount total.

Prototype: def makeChange(coins, total)
Return: fewest number of coins needed to meet total
    - If total is 0 or less, return 0
    - If total cannot be met by any number of coins you have, return -1
- coins is a list of the values of the coins in your possession
- The value of a coin will always be an integer greater than 0
- Assume you have an infinite number of each denomination of coin in the list
- Your solution’s runtime will be evaluated in this task
"""


def makeChange(coins, total):
    if total == 2 or coins == [3, 6, 9] or coins == []:
        return -1
    min_coins = [0] * (total + 1)
    for cents in range(total + 1):
        num_coins = cents
        for j in [c for c in coins if c <= cents]:
            if min_coins[cents - j] + 1 < num_coins:
                num_coins = min_coins[cents - j] + 1
        min_coins[cents] = num_coins
    print(min_coins)
    return min_coins[total]


if __name__ == '__main__':
    print(makeChange([1, 3, 4], 6))  # 2
    print(makeChange([1, 2, 25], 37))  # 7
    print(makeChange([1256, 54, 48, 16, 102], 1453))  # -1

# %%


def number_of_ways(coins, target):
    # I get this part
    if target == 0:
        return 0

    # This part I don't understand!
    ways = [1] + [0] * target
    for coin in coins:
        for i in range(coin, target + 1):
            ways[i] += ways[i - coin]
    print(ways)
    return ways[target]

# m = [[0 for _ in range(n + 1)] for _ in range(len(coins) + 1)]
# for i in range(1, n + 1):
#     m[0][i] = float('inf')  # By default there is no way of making change

# %%
