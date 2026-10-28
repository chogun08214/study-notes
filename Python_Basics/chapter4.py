# Chapter4 반복문

# 4-2 왜 반복이 중요?
# 반복: 같은 처리 과정을 되풀이
# 반복 구조: 어떤 조건이 만족될 때까지 루프를 돔

# 횟수 반복(for 문): 정해진 횟수만큼 반복
# 반복을 시작하기 전에 반복의 횟수를 미리 아는 경우
# 항목들을 모아 놓은 시퀀스라는 객체, 항목을 하나씩 가져와서 반복, 시퀀스에 항복이 더 이상 없으면 반복이 종료

# 조건 반복(while 문): 특정한 조건이 성립되는 동안 반복
# 특정한 조건이 만족되는 동안 계속 반복

# 4-3 리스트?
# 리스트: 여러 개의 자료들을 모아서 하나의 묶음으로 저장
# 리스트를 생성하려면 항목(item)들을 쉼표로 분리하여 대괄호 안에 넣으면 됨 (문자열, 숫자 가능)
# 공백 리스트를 생성한 후에 코드로 리스트에 값을 추가할 수도 있음
# 공백 리스트 생성 -> list = []
# append() 함수를 이용하여 리스트에 값들을 추가 -> list.append()

# 리스트의 요소에 접근
# 리스트에 저장된 값을 삭제하거나 교체 가능
# 리스트 안에 저장된 항목들은 번호를 가지고 있음, 번호 - 인덱스(index)
# 0 부터 시작하고 각 항목에 하나씩 할당
# 리스트 안의 특정한 항목 출력 가능
# 인덱스는 0부터 시작
# 음의 인덱스: 리스트의 끝에서부터 -1, -2, -3, ...

# 4-4 횟수 제어 반복
# for 루트: 횟수 제어 반복
# for 변수 in 리스트:
#       문장1
#       문장2

# for i in [1, 2, 3, 4, 5]:
#       print("방문을 환영합니다.")

# 반복되는 명령문은 반드시 들여쓰기

# range() 함수
# range() 함수로 반복 횟수를 전달하면 range() 함수가 자동으로 순차적인 정수들을 생성
# for 변수 in range(종료삾):
#       문장1
#       문장2

# for i in range(5):
#       print("방문을 환영합니다.")

# range() 함수에 list() 함수를 적용시키면 range() 함수가 생성하는 정수들을 볼 수 있음
# lsit(): 리스트를 생성하는 함수  -> list(range(5)) - [0, 1, 2, 3, 4]

# range(start, stop, step): start 에서 시작하여 (stop-1)까지 step 간격으로 정수들이 생성
# start와 step가 생략되면 start는 0으로 간주, step은 1로 간주
# range(start=0, stop, step=1) - stop: 졸요값이지만 stop은 포함x

# for i in range(5):

# end=" " - 줄이 바뀌지 않고 한 줄에 전부 출력 -> print(i, end=" ")
# for i in range(10, 0, -1): -> 10 9 8 7 6 5 4 3 2 1

# factorial.py 팩토리얼 계산
"""
number = int(input("정수를 입력하시오: "))
factorial = 1

for i in range(1, number + 1):
    factorial = factorial * i

print(f"{number}!은 {factorial}이다.")
"""

# root.py 방적식의 해 계산
"""
COUNT = 100
START = 1.0
END = 2.0

for i in range(COUNT):
    x = START + i * ((END - START) / COUNT)
    f = (x**2 -x -1)
    if abs(f - 0.0) < 0.01:
        print("방정식의 해는 ", x)
"""

# 4-5 조건 제어 반복
# 어떤 조건이 만족 되는 동안 반복
# while 문: 조건에 따라서 반복을 계속하는 구조

# while 조건식:
#       문장1
#       문장2

# while money < TARGET:
#       money = money + money * rate
#       year = year + 1

# while 뒤에 반복 여부를 결정하는 조건식
# 조건식이 True 이면 반복이 계속
# 조건식이 False면 반복은 종료

# money.py 투자금이 2배가 되는데 걸리는 시간
"""
TARGET = 2000
money = 1000
year = 0
rate = 0.07

while money < TARGET:
    money = money + money * rate
    year = year + 1

print(year, "년")
"""

# while 문은 조건 반복 구조
# while 문은 어떤 조건이 만족된느 동안 반복을 계속

# 횟수를 알고 있는 경우에도 while 루프를 사용

# sum.py 1과 10까지의 합 계산
"""
i = 1
sum = 0

while i <= 10:
    sum = sum + i
    i = i + 1

print("합계는", sum)
"""

# 변수 i: 반복 횟수를 저장하는 변수, 반복 제어 변수

# else가 있는 while 루프
# else는 조건식이 False로 평가되면 실행
# while 루프가 break 문으로 종료되면 else는 무시

# else.py else가 있는 while 루프
"""
i = 0

while i < 3:
    print("루프 안쪽")
    i = i + 1 
else:
    print("else 부분")
"""

# 무한 루프: 조건식을 잘못 작성하면 무한히 반복

# inf_loop1.py 무한루프
"""
i = 0

while i < 10:
    print("Hello!")
"""

# gugu.py 구구단 출력
"""
number = int(input("원하는 단은: "))
i = 1

while i <= 9:
    print("%d*%d=%d" % (number, i, number * i))
    i = i + 1
"""

# print() 함수를 이용하여 특정 형식의 값을 출력할 때 %d와 같은 형식
# % 이후의 변수의 값이 %d 자리에 출력

# guess.py 숫자 퀴즈
"""
import random

print("1부터 100 사이의 숫자를 맞추시오")
print("")

number = 0
answer = random.randint(1, 100)
count = 0

while number != answer:
    number = int(input("숫자를 입력하시오: "))
    if number > answer:
        print("너무 높음!")
        count = count + 1
        print("")
    elif number < answer:
        print("너무 낮음!")
        count = count + 1
        print("")
else:
    print("축하합니다. 시도횟수=", count)
"""

# math.py 산수 문제
"""
import random

answer = 0

flag = True # flag 활용 

while flag:
    num1 = random.randint(1, 100)
    num2 = random.randint(1, 100)
    sum = num1 + num2

    answer = int(input(f"{num1} + {num2} = "))

    if answer == sum:
        print("잘했어요!!")
    else:
        print("틀렸어요. 하지만 다음번에는 잘할 수 있죠?")
        flag = False
"""

# password.py 암호
"""
password = ""

while password != "pythonisfun":
    password = input("암호를 입력하시오: ") # password에 저장x

print("로그인 성공")
"""

# 4-6 중첩 반복문
# 반목문은 중첩하여 사용 가능, 반복문 안에 다른 반복문: 중첩 반복문
# 외부 반복문: 외부에 위치하는 반복문
# 내부 반복문: 안쪽의 반복문, 외부 반복문이 한번 반복할 때마다 새롭게 실행
# 각각의 반복문을 제어하는 변수가 달라야 함

# nested1.py 중첩 반복문
"""
for y in range(5):
    for x in range(10):
        print('*', end="")
    print("")
"""

# nested2.py 중첩 반복문
"""
for y in range(1, 6): #(5)로 하면 ****에서 끊김, 0~5
    for x in range(y): # y-1까지 
        print("*", end="")
    print("")
"""

# nested3.py 중첩 반복문
"""
adj = ["small", "medium", "large"]
nouns = ["apple", "banana", "grape"]

for y in adj:
    for x in nouns:
        print(y, x)
"""

# dice.py 중첩 반복문
"""
for a in range(1, 7):
    for b in range(1, 7):
        if a + b == 6:
            print(f"첫 번째 주사위={a} 두 번째 주사위={b}")
"""

# res.py 중첩 반목문
"""
persons = ["Kim", "Park", "Lee"]
restaurants = ["Korean", "American", "French"]

for y in persons:
    for x in restaurants:
        print(y + "이 " + x, "식당을 방문")
"""

# 4-7 무한 루프와 break, continue
# 무한 루프: 프로그램이 무한히 반복

# while True:
#    if 조건:
#       break
#    if 조건:
#       continue

# while 루프의 조건에 True, 조건이 항상 참이므로 무한히 반복
# break: 루프를 강제적으로 빠져 나올 때 사용하는 문장

# break.py 무한 루프와 break
"""
while True:
    color = input("신호등 색상을 입력하시오 ")
    if color == 'green':
        break
print("전진!!")
"""

# continue: 다음 반복을 강제적으로 시작

# continue.py continue 프로그램
"""
for i in range(1, 11):
    if i % 3 == 0:
        continue
    print(i, end=" ")
"""

# prime.py 1부터 100 사이의 소수 찾기
"""
count = 0
prime_count = 50
number = 2

while count < prime_count:
    divisor = 2
    flag = True # 중요!

    while divisor < number:
        if number % divisor == 0:
            flag = False
            break
        divisor += 1

    if flag: # if flag == True오 같은 의미
        print(number, end=" ")
        count = count + 1

    number += 1
"""

# cal_pi.py 파이 값 계산
"""
up = 4.0
down = 1.0
pi = 0

repeat = int(input("반복휫수:"))

while repeat > 0:
    pi = pi + (up / down)
    down = down + 2
    up = -1 * up
    repeat -= 1

print("Pi = %f" % pi) # %f는 소수점 이하 6자리까지만 반올림 
"""

# gambler.py 도박사
"""
import random

initial_money = 50
target_money = 250
count = 0

print(f"초기 금액 ${initial_money}")
print(f"목표 금액 ${target_money}")

for i in range(100):
    cash = initial_money

    while cash > 0 and cash < 250:
        prob = random.randrange(2)

        if prob == 0:
            cash = cash - 1
        else:
            cash = cash + 1

    if cash == target_money:
        count += 1

print(f"100번 중에서 {count}번 성공 ")
"""

# ex1
"""
for i in range(2, 51):
    if i % 2 == 0:
        print(i, end=" ")
"""

# ex2
"""
myList = [11, 22, 23, 99, 81, 93, 35]

sum = 0

for i in myList:
    sum = sum + i

print("정수들의 합은", sum)
"""

# ex3
"""
sum = 0

for i in range(1, 101):
    if i % 3 == 0:
        sum = sum + i

print(f"1 부터 100 사이의 모든 3의 배수의 합은 {sum}입니다.")
"""

# ex4
"""
number = int(input("정수를 입력하시오: "))

for i in range(1, number + 1):
    if number % i == 0:
        print(i, end=" ")
"""

# ex5
"""
number = int(input("정수를 입력하시오: "))

for y in range(1, 6):
    for x in range(1, y + 1):
        print(x, end=" ")

    print("")
"""

# ex6
"""
import math

print("각도  sin값    cos값")

for i in range(0, 100, 10):
    radian = 3.14 * i / 180.0

    print("%d  %8.3f %8.3f" % (i, math.sin(radian), math.cos(radian)))
    print("")
"""

# ex8
"""
n = 0

while n**2 < 500:
    n = n + 1

print(n)
"""

# ex9
"""
for y in range(1, 10):
    for x in range(1, 10):
        print(y * x, end = " ")
    print("")
"""

# ex10
"""
result = 0

n = int(input("n의 값을 입력하시오: "))

for i in range(1, n + 1):
    result = result + i**2

print(f"계산값은 {result}입니다.")
"""

# ex11
"""
num1 = int(input("첫 번째 정수를 입력하시오: "))
num2 = int(input("첫 번째 정수를 입력하시오: "))

number = 0

k = 1

for i in range(1, min(num1, num2) + 1):
    if num1 % k == 0 and num2 % k == 0:
        number = k
    k += 1
print(f"{num1}과 {num2}의 최대 공약수는 {number}입니다.")
"""

# ex12
"""
import random

point = 10000000
correct = 0
pi = 0

for i in range(point):
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)

    if x**2 + y**2 <= 1:
        correct += 1

pi = 4 * (correct / point)

print(f"파이의 값은 {pi}입니다.")
"""

# ex13
"""
a = 0
b = 1

count = int(input("몇 번째 항까지 구할까요? "))

for i in range(count + 1):
    if i < 2:
        b = a
        a = i
        f = b + a
        print(f, end=", ")
    elif i < 10:
        a = b
        b = f
        f = b + a
        print(f, end=", ")
    else:
        a = b
        b = f
        f = b + a
        print(f, end=" ")
"""

# ex14
"""
start = 2
end = 20

while start <= end:
    divisor = 2
    flag = True

    while divisor < start:
        if start % divisor == 0:
            flag = False
            break
        divisor += 1

    if flag == True:
        print(start, end = " ")

    start += 1
"""

# ex15
"""
sum = 0

for i in range(1, 100, 2):
    sum = sum + (i / (i + 2))

print(sum)
"""

# ex16
"""
size = int(input("게임판의 크기: "))

for i in range(size):
    print(" ---" * size)
    print("|   " * (size + 1))

print(" ---" * size)3
"""

# ex17
"""
for i in range(10):
    if i % 3 == 0 and i % 5 == 0:
        print("fizzbuzz")
    elif i % 3 == 0:
        print("fizz")
    elif i % 5== 0:
        print("buzz")
    else:
        print("*")
"""
