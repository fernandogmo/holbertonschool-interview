#!/usr/bin/python3
"""
Two players (Maria and Ben) take turns choosing a prime number 𝑝 from ℕ
such that 𝑝 <= 𝑛, then removing 𝕡 and its multiples from the set.
The player that cannot make a move loses the game.

They play 𝒙 rounds of the game, where 𝑛 may be different for each round.
Assuming Maria always goes first and both players play optimally,
determine who the winner of each game is.
"""


def isWinner(x, nums):
    """
    Finds the winner of a prime sieve game.
    Assumes that playing optimally implies picking the
    lowest available prime number.
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    sieve = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not sieve[i]:
            continue
        for j in range(i*i, n + 1, i):
            sieve[j] = False

    sieve[0] = sieve[1] = False
    c = 0
    for i in range(len(sieve)):
        if sieve[i]:
            c += 1
        sieve[i] = c

    player1 = 0
    for n in nums:
        player1 += sieve[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return "Maria"
    return "Ben"


if __name__ == '__main__':
    assert isWinner(3, [4, 5, 1]) == "Ben"
    assert isWinner(6, [5, 4, 3, 6]) == "Maria"
    assert isWinner(5, [2, 5, 1, 4, 3]) == "Ben"
