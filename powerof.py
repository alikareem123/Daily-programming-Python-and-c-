def powerer(x: int, n: int) -> float:
    ans = 1.0
    number = n
    if number < 0:
        number = -1 * number
    while number > 0:
        if number % 2:
            ans = ans * x
            number -= 1
        else:
            x = x * x
            number = number // 2
    if n < 0:
        ans = 1.0 / ans
    return ans

if __name__ == "__main__":
    print("The power is : ", powerer(2, 5))
