# Chapter3 조건문

# 3-2 제어문
# 제어문: 문장들이 실행되는 순서를 제어하는 문장 (조건문, 반복문)
# 조건문: 어떤 조건에 따라서 문장의 실행 여부가 결정
# 반복문: 특정 조건에 따라서 문장을 반복하여 실행

# 순차 구조: 명령들이 순차적으로 실행
# 선택 구조: 둘 중의 하나의 명령을 선택하여 실행 (조건문으로 구현)
# 반복 구조: 동일한 명령이 반복되면서 실행 (반복문으로 구현)

# 3-3 if-else 문
# if-else 문: 조건에 따라서 서로 다른 처리를 하고 싶을 때

# if 조건식:
#       문장1
# else:
#       문장2

# 조건식: 조건을 수식으로 표현
# 조건식이 참: if 아래에 있는 문장 실행
# 조건식이 거짓:  else 아래에 엤는 문장 실행

# 콜론(:): 아직 전체 문장이 끝나지 않음을 알림
# 조건의 영향을 받는 문장들은 반드시 들여써야 함

# shipping.py  배송비 계산
"""
price = int(input("상품의 가격: "))

if  price > 20000:
    shipping_cost = 0
else:
    shipping_cost = 3000

print("배송비 =", shipping_cost)
"""

# 블록
# 동일한 개수의 공백
# 하나의 블록에 속하는 문장들은 같이 실행

# else 부분이 필요 없다면 생략 가능

# pass
# 나중에 채워넣음
# if price > 6000:
#       pass

# 3-4 관계 연산자
# 관계 연산자: 두 개의 피연산자를 비교
# 결과는 참(True) 아니면 거짓(False)
# ==: 같음, !=: 같지 않음, >: 큼, <: 작음, >= 크거나 같음, <=: 작거나 같음
# 조건식에는 변수를 사용할 수 있음

# 부울값: True or False
# 변수에 저장 가능
# 부울 변수: 붖울값을 저장하는 변수, True와 False 중 하나
# 변수에 True와 False를 직접 저장 가능
# if-else문에 사용 가능

# 비교 연산자는 문자열도 비교 가능
# s1 == s2: 두 개의 문자열이 완벽하게 일치하면 True
# s1 < s2: 사전에서 s1이 s2보다 앞에 있으면 True
# 모든 대문자는 소문자보다 앞, 스페이스 문자는 모든 알파벳 문자보다 앞, 숫자는 문자보다 앞

# from math import sqrt
# sqrt(number)

# 실수 2개가 같은 지를 판별: 2개의 숫자가 오차 이내로 아주 근접하면 같은 것으로 판정
# abs(): 절대값을 계산하여서 반환
# 관계 연산자의 우선 순위는 산술 연산자보다 낮음

# import random
# randint(1, 100): 1과 100을 포함하여서 두 숫자 사이의 난수를 반환

# mathprob.py 산술 문제 출제
"""
import random

x = random.randint(1, 100)
y = random.randint(1, 100)

answer = int(input(f"{x} + {y} = "))

ox = (answer == (x + y))

print(ox)
"""

# 3-5 조건 연산자
# max_value = (x if x > y else y)
# (x > y)가 참이면 x가 수식의 결과값, 거짓이면 y가 결과값
# 반드시 조건 연산자를 감싸는 괄호가 있어야 함
# 괄호가 없으면 할당 연산자가 먼저 계산

# 짝수와 홀수를 구분
"""
number = int(input("정수를 입력하시오: "))

if number % 2 == 0:
    print("짝수입니다.")
else:
    print("홀수입니다.")
"""

# 세일 가격 계산
"""
price = int(input("정가를 입력하시오: "))
total = 0

if price < 100:
    total = price - (price * 0.1)
    print("상품의 가격=", total)
else:
    total = price - (price * 0.15)
    print("10층에서 사은품을 받아가세요.")
    print("상품의 가격=", total)
"""

# 3-6 논리 연산자
# 복잡한 조건을 표현
# 여러 개의 조건을 조합하여 참인지 거짓인지를 따짐
# x and y: x와 y가 모두 참이면 참, 그렇지 않으면 거짓
# x or y: x나 y중에서 하나만 참이면 참, 모두 거짓이면 거짓
# not x: x가 참이면 거짓, x가 거짓이면 참
# 논리 연산자는 관계 연산자보다 우선순위가 낮음 -> 괄호를 사용하지 않고 논리 연산자의 양쪽에 관계식 작성 가능

# water_waste.py 물의 상태 출력
"""
temperate = int(input("온도를 입력하시오: "))

if temperate <= 0:
    print("물의 상태는 고체입니다.")
elif temperate > 0 and temperate < 100:
    print("물의 상태는 액체입니다.")
else:
    print("물의 상태는 기체입니다.")
"""

# random.randrange(2) -> 0이나 1을 랜덤하세 생성

# coin_tossing.py 동전 던지기 게임
"""
import random

print("동전 던지기 게임을 시작합니다.")

coin = random.randrange(2)

if coin == 0:
    print("앞면입니다.")
else:
    print("뒷면입니다.")

print("게임이 종료되었습니다.")
"""

# 3-7 중첩 if 문
# 증첩 if 문: if 문 안에 다른 if 문
# 조건식이 참이나 거짓인 경우에 다른 if 문 실행
# if 조건식1 :
#    if 조건식2 :
#       문장1
#    else :
#       문장2
# else :
#    if 조건식3 :
#       문장3
#    else :
#       문장4

# shipping.py 배송비
"""
dest = input("배송지(현재는 korea와 us만 가능): ")
price = int(input("상품의 가격: "))

if dest == 'korea':
    if price >= 20000:
        shipping_cost = 0
    else:
        shipping_cost = 3000
else:
    if price >= 100000:
        shipping_cost = 0
    else:
        shipping_cost = 8000

print("배송비 =", shipping_cost)
"""

# 3-8 연속 if 문
# 모든 교차로에서 조건을 검사하여 결정
# elif: else if를 줄인 키워드
# 연속 if 문에서는 순서가 아주 중요

# earthquake.py 리히터 구모 출력
"""
scale = float(input("리히터 규모를 입력하시오: "))

if scale >= 8.0:
    print("대부분의 구조물이 파괴됩니다.")
elif scale >= 7.0:
    print("지표면에 균열이 발생합니다.")
elif scale >= 4.0:
    print("빈약한 건물에 큰 피해가 있습니다.")
elif scale >= 2.0:
    print("물건들이 흔들리거나 떨어집니다.")
else:
    print("지진계에 의해서만 탐지 가능합니다.")
"""

# magic_ball.py 운세 출력
"""
import random

print("행운의 매직볼로 오늘의 운세를 출력합니다.")

ball = random.randint(1, 8)

if ball == 1:
    print("확실히 이루어집니다.")
elif ball == 2:
    print("좋아 보이네요.")
elif ball == 3:
    print("믿으셔도 됩니다.")
elif ball == 4:
    print("저의 생각에는 no입니다.")
else:
    print("다시 질문해주세요.")
"""

# user_input.py 사용자 입력 검증
"""
print("=========================")
print("메뉴 1번: 치즈 버거")
print("메뉴 2번: 치킨 버거")
print("메뉴 3번: 불고기 버거")
print("=========================")
print("")

menu = int(input("메뉴를 선택하세요:"))

if menu == 1:
    print("치즈 버거")
elif menu == 2:
    print("치킨 버거")
elif menu == 3:
    print("불고기 버거")
else:
    print("잘못 입력하셨습니다.")
"""

# soccer.py 축구 게임
"""
import random

choice = int(input("어디를 수비하시겠어요?(왼쪽: 1, 중앙: 2, 오른쪽: 3)"))
computer = random.randint(1, 3)

if choice == computer:
    print("수비에 성공하셨습니다.")
else:
    print("페날티킥이 성공하였습니다.")
"""

# triangle.py 삼각형
"""
a = int(input("삼각형의 한 변을 입력하시오: "))
b = int(input("삼각형의 한 변을 입력하시오: "))
c = int(input("삼각형의 한 변을 입력하시오: "))

print("")

if (a + b > c) and (a + c  > b) and (b + c > a):
    print("올바른 삼각형")
else:
    print("올바르지 않은 삼각형")
"""

# ex1
"""
num1 = int(input("정수를 입력하시오: "))
num2 = int(input("정수를 입력하시오: "))

if num1 % num2 == 0:
    print("약수입니다.")
else:
    print("약수가 아닙니다.")
"""

# ex2
"""
temp = int(input("현재 온도를 입력하시오: "))
if temp >= 25:
    print("반바지를 추천합니다.")
else:
    print("긴바지를 추천합니다.")
"""

# ex3
"""
word = input("문자를 입력하시오: ")

if word == ('R' or 'r'):
    print('Rectangle')
elif word == ('T' or 't'):
    print("Triangle")
elif word == ('C' or 'c'):
    print("Circle")
else:
    print("Unknown")
"""

# ex4
"""
radius = int(input("원의 반지름: "))

area = 3.14 * radius * radius

print("원의 면적: ", area)

if radius < 0:
    print("잘못된 값입니다.")
"""

# ex5
"""
num1, num2, num3 = eval(input("3개의 정수를 입력하시오: ")) # 3개의 문자를 동시에 입력받음

if num1 < num2:
    if num1 < num3:
        print(f"제일 작은 정수는 {num1}입니다.")
    else:
        print(f"제일 작은 정수는 {num3}입니다.")
else:
    if num2 < num3:
        print(f"제일 작은 정수는 {num2}입니다.")
    else:
        print(f"제일 작은 정수는 {num3}입니다.")
"""

# ex6
"""
import random

human = int(input("선택하시오(1: 가위 2: 바위 3: 보) "))
computer = random.randint(1, 3)
print("컴퓨터의 선택(1: 가위 2: 바위 3: 보)", computer)

if human == 1:
    if computer == 1:
        print("비겼음")
    elif computer == 2:
        print("컴퓨터가 이겼음")
    else:
        print("사용자가 이겼음")
elif human == 2:
    if computer == 1:
        print("사용자가 이겼음")
    elif computer == 2:
        print("비겼음")
    else:
        print("컴퓨터가 이겼음")
else:
    if computer == 1:
        print("컴퓨터가 이겼음")
    elif computer == 2:
        print("사용자가 이겼음")
    else:
        print("비겼음")
"""

# ex7
"""
height = int(input("키를 입력하시오(cm): "))
age = int(input("나이를 입력하시오: "))

if height >= 140 and age >= 10:
    print("타도 좋습니다.")
else:
    print("탑승 불가능합니다.")
"""

# ex8
"""
weight, height = map(int, input("체중과 키를 입력하시오: ").split())
# split: 입역을 공백 기준으로 쪼개서 리스트로 만듦
# map():  리스트 안의 원소 하나하나에 함수를 적용

std_weight = (height - 100) * 0.9

if std_weight > weight:
    print("저체중입니다.")
elif std_weight < weight:
    print("과체중입니다.")
else:
    print("표준입니다.")
"""

# ex9
"""
import random

num1 = random.randint(1, 10)
num2 = random.randint(1, 10)
calc = random.randint(1, 4)

result = 0

if calc == 1:
    result = num1 + num2
    a = '+'
elif calc == 2:
    result = num1 - num2
    a = '-'
elif calc == 3:
    result = num1 * num2
    a = '*'
else:
    result = round(num1 / num2, 1)
    a = '/'

answer = eval(input(f"{num1} {a} {num2}의 값은?"))

if answer == result:
    print("맞았습니다.")
else:
    print("틀렸습니다.")
"""

# ex10
"""
x = float(input("x의 값을 입력하시오: "))
result = 0

if  x <= 0:
    result = x*2 - 9 * x +2
else:
    result = 7 * x + 2

print(f"f(x)의 값은 {result}")
"""

# ex11
"""
weight = int(input("무게(킬로그램): "))
height = float(input("키(미터): "))

BMI = weight / height**2
print("당신의 BMI:", BMI)

if BMI >= 30:
    print("비만입니다.")
elif BMI >= 25:
    print("과체중입니다.")
else:
    print("정상입니다.")
"""

# ex12
"""
year = int(input("연도를 입력하시오: "))

if (year % 12) == 0:
    print("원숭이띠입니다.")
elif (year % 12) == 1:
    print("닭띠입니다.")
elif (year % 12) == 2:
    print("개띠입니다.")
elif (year % 12) == 3:
    print("돼지띠입니다.")
elif (year % 12) == 4:
    print("쥐띠입니다.")
elif (year % 12) == 5:
    print("소띠입니다.")
elif (year % 12) == 6:
    print("호랑이띠입니다.")
elif (year % 12) == 7:
    print("토끼띠입니다.")
elif (year % 12) == 8:
    print("용띠입니다.")
elif (year % 12) == 9:
    print("뱀띠입니다.")
elif (year % 12) == 10:
    print("말띠입니다.")
elif (year % 12) == 11:
    print("양띠입니다.")
"""

# ex13
"""
year = int(input("연도를 입력하시오: "))

if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
    print("윤년입니다.")
"""

# ex14
"""
from math import sqrt

a = int(input("a를 입력하시오: "))
b = int(input("b를 입력하시오: "))
c = int(input("c를 입력하시오: "))

result = b**2 - 4 * a * c

if result > 0:
    x1 = (-b - sqrt(b**2 - 4 * a * c)) / (2 * a)
    x2 = (-b + sqrt(b**2 - 4 * a * c)) / (2 * a)
    print(f"실근은 {x1}과 {x2}입니다.")
elif result == 0:
    x = (-b + sqrt(b**2 - 4 * a * c)) / (2 * a)
    print(f"실근은 {x}입니다.")
else:
    print("근이 없습니다.")
"""

# ex15
"""
num = int(input("정수를 입력하시오: "))

if num % 3 == 0:
    if num % 5 == 0:
        print("Python Express")
    else:
        print("Python")
elif num % 5 == 0:
    print("Express")
"""

# ex16
"""
ph = eval(input("pH를 입력하시오: "))
if ph >= 8:
    print("알칼리입니다.")
elif ph >= 7:
    print("중성입니다.")
else:
    print("산입니다.")
"""