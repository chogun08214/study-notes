# ch3 ex5
"""
x, y, z = eval(input("3개의 정수를 입력하시오: ")) # eval
mini = min(x, y, z)
print(f"제일 작은 정수는 {mini}입니다.")
"""

# ch3 ex8
"""
height, weight = map(int, input("체중과 키를 입력하시오: ").split()) # map(int, ...split())

standard = (height - 100) * 0.9

if weight < standard:
    print("정상 체중입니다.")
elif weight == standard:
    print("표준 체중입니다.")
else:
    print("과체중입니다.")
"""

# ch4 root.py 방정식의 해 구하기
"""
COUNT = 100
START = 1
END = 2

for i in range(COUNT):
    x = START + (i * ((END - START) / 100))
    f = x**2 -x -1

    if abs(f) < 0.01:
        print("방적시의 해는", x)
"""

# ch4 prime.py 1부터 100사이의 소수 찾기







