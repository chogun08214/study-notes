# Chapter 5 함수

# 5-1
# 함수: 특정한 기능을 수행하는 코드의 묶음

# 5-2 함수?
# 함수(function): 반복적으로 사용하는 코드를 묶은 것
# 객체(object): 서로 관련 있는 변수와 함수를 묶는 것
# 모듈(module): 함수나 객체들을 소스 파일 안에 모은 것

# 함수
# 작업에 필요한 데이터를 전달 받을 수 있으며, 작업이 완료된 후에는 작업의 결과를 호출자에게 반환 가능
# 호출: 함수를 사용
# 코드를 재활용, 동일한 작업을 하기 위해 코드를 복사할 필요x
# 코드를 간결하게 유지 가능
# 복잡한 프로그램을 ㅁ나누어서 작성할 수 있ㄲ어서 구조화된 프로그래밍이 가능

# 함수의 필요성
# 동일한 처리를 반복

# 5-3 함수 작성하고 호출
# def 함수이름(매개변수1, 매개변수2, ...):
#       명령문1
#       명령문2

# def get_area(radius):
#   area = 3.14 * radius**2
#   return area

# 헤더: def 키워드로 시작, 함수의 이름과 매개 변수를 적고 클론(:, 인터프리터가 성급하게 해석x, 함수는 몸체까지 입력되어야 해석 가능)을 찍음
# 매개 변수(parameter): 외부에서 전달되는 데이터를 함수로 전달
# 몸체: 함수가 수행하는 작업을 위한 명령어, return 키워드를 이용하여 계산 결과를 반환
# 함수 안의 문장들은 똑같은 간격으로 들여쓰기 해야 함

# 함수 호출
# 함수의 이름을 써 줌
# 함수 안의 문장들은 호출되기 전까지 실행x
# 함수가 호출되면 함수 안에 있는 문장들이 실행되며 실행이 끝나면 호출한 위치로 되돌아감
# 함수는 일단 작성되면 몇 번이아도 호출 가능

# 함수에 값 전달
# 인수: 함수에 값을 전달
# 인수 or 인자(argument): 전달되는 값
# 매개 변수: 인수를 전달받는 변수

# 값 반환
# 반환 값: 함수로부터 되돌아오는 값
# return 키워드 사용

# 서로 다른 인수로 호출 가능

# 함수가 여러 개의 값 반환 가능
# def get_input():
#   return 2, 3

# x, y = get_input()

# 함수의 헤더만 결정하고 몸체는 나중에 작성: pass

# 5-4 여러 개의 함수
# 함수를 호출하기 전에 반드시 함수를 정의
# 함수 내에서는 아직 정의 되지 않은 함수 호출 가능

# pizza.py 피자의 면적 비교
"""
def get_area(radius):
    area = 3.14 * radius * radius
    return area

print("20cm 피자 2개의 면적:", get_area(20) * 2)
print("30cm 피자 1개의 면적:", get_area(30))
"""

# 5-5  매개 변수 전달
# 인수: 호출 프로그램에 의하여 함수에 실제로 전달되는 값
# 매개 변수: 이 값을 전달받는 변수
# 함수가 호출될 때마다 인수는 함수의 매개 변수로 전달
# 함수는 호출될 때마다 인수는 달라질 수 있음, 매개 변수의 개수는 정확히 일치해야 함
# 리스트가 전달되면 리스트는 원본이 직접 전달

# 디폴트 인수
# 디폴트 인수: 함수의 매개 변수가 기본값을 가질 수 있음
# 인수가 부족한 경우-기본값을 넣어주는 메커니즘

# 키워드 인수
# 대부분의 인수들은 함수 호출 시에 위치에 의하여 구분
# 키워드 인수: 인수들 앞에 키워드를 두어서 인수들을 구분, 인수의 이름을 명시적으로 지정하여 값을 매개 변수로 전달
# = 위치 인수
# 매개 변수의 이름에 값을 직접 대입, 인수의 위치가 매개ㅐ 변수의 위치와 달라도 됨
# 위치 인수와 키워드 인수는 섞일 수 있지만 반드시 위치 인수가 키워드 인수 앞에 나와야 함
#sub(10, y=20, z=30)

# 가변 인수
# 함수는 전달하는 값이 몇 개인지 모름
# 함수 안에서 전달되는 값의 개수를 파악 가능
# def varfunc(*args):
#   print(args)
# print("하나의 값으로 호출")
# varfunc(10)
# print("여러 개의 값으로 호출")
# varfunc(10, 20, 30)

# ->
# 하나의 값으로 호출
# (10,)
# 여러 개의 값으로 호출
# (10, 20, 30)

# *args르 사용하여 가변 길이 인수를 함수에 전달 but 키워드 인수를 전달하는 데 사용할 수는 없음
# **kwargs: 가변 길이의 키워드 인수를 함수에 전달
# **: 가변 길이 키워드 인수를 나타냄, 키워드 인수인데 가변 길이라는 의미
# 인수는 딕셔너리 형태로 전달

# def myfunc(**kwargs):
#   result = ""
#   for arg in kwargs.values():
#       result += arg
#   retun result
# print(myfunc(a="Hi!", b="Mr.", c="Kim")

# * 연산자로 언패킹
# *, **를 이용하여 포장을 푸는 연산자
# 언패킹 연산자: 반복 가능한 객체의 ㄱ밧을 포장 해제
# 단일 별표 연산자(*): 파이썬이 제공하는 모든 반복 가능한 객체(iterable)에서 사용 가능
# 이중 별표 연산자(**): 딕셔너리 객체에서만 사용 가능

# alist = [1, 2, 3]
# print(*alist)
# -> 1 2 3

# welcome.py 메세지를 반복하여 출력
"""
def display(msg, count=1):
    for i in range(count):
        print(msg)

display("환영합니다.", 5)
"""

# bisection.py 이분법으로 근을 계산
"""
def f(x):
    return x**2-x-1

def bisection(a, b, error):
    if f(a) * f(b) > 0:
        print("근이 없습니다")
    else:
        while (b-a)/2.0 > error:
            m = (a +  b) / 2.0
            if f(m) == 0:
                return (m)
            elif f(a) * f(m) < 0:
                b = m
            else:
                a = m

            return m

answer = bisection(1, 2, 0.0001)

print("x**2-x-1의 근:", answer)
"""

# cal_pay.py 주급 계산
"""
def weeklyPay(rate, hour):
    money = 0

    if hour > 30:
        money = (rate * 1.5) * (hour - 30) + rate * 30
    else:
        money = rate * hour
    return money


rate = int(input("시급을 입력하시오: "))
hour = int(input("근무 시간을 입력하시오: "))

week_pay = weeklyPay(rate, hour)

print(f"주급은 {week_pay}")
"""

# 5-6 값 반환
# return 문을 사용하여 함수 결과를 반환
# return 문은 모든 수식값을 반환
# return 문이 처리되면 함수가 즉시 종료
# 하나의 경우에서만 값을 반환하면 안 됨

# 여러 개의 값 반환
# 함수가 하나 이상의 값도 반환 가능
# def sub():
#   return 1, 2, 3
#
# a, b, c = sub()
# print(a, b, c)

# return 1, 2, 3 == return (1, 2, 3)
# 튜플을 받아서 변수 a, b, c에 값을 풀어서 저장

# 값을 반환하지 않는 함수

# return.py 여러 개의 값을 반환
"""
def get_info():
    name = input("이름:")
    age = int(input("나이:"))

    return name, age

name, age = get_info()

print(f"이름은 {name} 이고 나이는 {age} 살입니다")
"""

# 5-7 함수를 사용하는 이유
# 소스 코드의 중복성 없애줌 -> 소스 코드의 양 적어짐
# 다른 프로그램에서도 재사용 가능
# 개발 과정이 쉬워지고, 체계적으로 되면서 유지보수도 쉬워짐
# 구조화 프로그램: 큰 작업을 계속 나누어서 설계
# 각 함수들은 특징적인 한 가지 작업만을 맡아야 함

# conv_temp.py 온도를 변환
"""
def menu():
    print("1. 섭씨 온도->화씨 온도")
    print("2. 화씨 온도->섭씨 온도")
    print("3. 종료")

    print("")

    menu_select = int(input("메뉴를 선택하세요: "))

    return menu_select

def C_input():
    c = eval(input("섭씨 온도를 입력하시오: "))
    return c

def F_input():
    f = eval(input("화씨 온도를 입력하시오: "))
    return f

def change_F(c):
    f = c * 9.0 / 5.0 + 32
    return f

def change_C(f):
    c = (f - 32.0) * 5.0 / 9/0
    return c

def main():
    while True:
        selection = menu()

        print("")

        if selection == 1:
            c_temp = C_input()
            F_temp = change_F(c_temp)
            print(f"화씨 온도 = {F_temp}", "\n")
        elif selection == 2:
            f_temp = F_input()
            C_temp = change_C(f_temp)
            print(f"섭씨 온도 = {C_temp}", "\n")
        elif selection == 3:
            break


main()
"""

# 5-8 순환 호출
# 순환: 알고리즘이나 험수가 자기 자신을 호출하여 문제를 해결

# def factorial(n):
#   if n == 1:
#       return 1
#   else:
#       return n * factorial(n-1)

# 5-9 변수의 범위
# 지역 변수: 함수 안에서 생성되는 변수, 함수가 종료되면 사라짐
# def myfunc():
#   x = 100
#   print(x)
# myfunc()
# 전역 변수: 함수의 외부에서 생성된 변수는 프로그램의 어디에서나 사용 가능
# gx = 100
#
# def myfunc():
#   print(gx)
#
# myfunc()
# print(gx)

# 지역 변수는 함수마다 동일한 이름 사용 가능
# def fun1():
#   x = 1
# def fun2():
#   x = 2

# 함수 안에서 전역변수 변경
# 함수 안에서 변수에 닶을 저장하면 새로운 지역 변수가 만들어짐
# gx = 100
#
# def myfunc():
#   gx = 200
#   print(gx)
#
# myfunc()
# print(gx) -> 200
#              100

# 함수 안에서 전역 변수의 값을 변셩하고 싶은 경우 - global
# gx = 100
#
# def myfunc():
#   global gx
#   gx = 200
#   print(gx)
#
# myfunc()
# print(gx) -> 200
#              200

# ex1
"""
def get_peri(radius = 5.0):
    num = 2 * 3.14 * radius
    return num

print(f"get_peri() =", get_peri())
print(f"get_peri(4.0) =", get_peri(4.0))
"""

# ex2
"""
def add(num1, num2):
    result = num1 + num2
    return result

def minus(num1, num2):
    result = num1 - num2
    return result

def multiply(num1, num2):
    result = num1 * num2
    return result

def divide(num1, num2):
    result = num1 / num2
    return result

num1 = int(input("첫 번째 정수를 입력하시오: "))
num2 = int(input("두 번째 정수를 입력하시오: "))
print(f"({num1} + {num2}) =", add(num1, num2))
print(f"({num1} - {num2}) =", minus(num1, num2))
print(f"({num1} * {num2}) =", multiply(num1, num2))
print(f"({num1} / {num2}) =", divide(num1, num2))
"""

# ex3
"""
def calc(num1, num2):
    sum = num1 + num2
    diff = num1 - num2
    multi = num1 * num2
    divide = num1 / num2
    return sum, diff, multi, divide

num1 = int(input("첫 번째 정수를 입력하시오: "))
num2 = int(input("두 번째 정수를 입력하시오: "))
a, b, c, d = calc(num1, num2)
print(f"{a}, {b}, {c}, {d}이 반환되었습니다.")
"""

# ex4
"""
def getGrade(score):
    if score >= 90:
        return "A"
    elif score >= 80:
        return "B"
    elif score >= 70:
        return "C"
    elif score >= 60:
        return "D"
    else:
        return "F"

score = int(input("점수를 입력하세요: "))

print(f"성적은 {getGrade(score)} 입니다")
"""

# ex5 #.islower, .isupper, .isdigit 활용
"""
def checkPass(p):
    lower_count = 0
    upper_count = 0
    digit_count = 0

    for i in p:
        if i.islower():
            lower_count += 1
        elif i.isupper():
            upper_count += 1
        elif i.isdigit():
            digit_count += 1

    sum = lower_count + upper_count

    if len(p) >= 8 and sum >= 1 and digit_count >= 1:
        print("사용할 수 있습니다.\n")
        return 0
    elif p == "0":
        return 1
    else:
        print('사용할 수 없습니다. 다시 입력하세요!\n')
        return 0


flag = True
while flag == True:
    pw = input("패스워드를 입력하시오: ")

    if checkPass(pw) == 0:
        continue
    elif checkPass(pw) == 1:
        flag = False
        break
"""

# ex6
"""
def calc(n1, n2):
    print(f"정수 {n1}+{n2}의 합은?")

num1 = int(input("첫 번째 정수를 입력하시오: "))
num2 = int(input("두 번째 정수를 입력하시오: "))

calc(num1, num2)
"""

# ex7
"""
def getIntRange(a, b, msg):
    flag = True

    while flag == True:
        num = int(input(msg))

        if num >= a and num <= b:
            flag = False
            return num
            break
        else:
            continue



print("날짜를 입력하시오(월과 일)") # msg = 메시지
month = getIntRange(1, 12, "월을 입력하시오(1부터 12사이의 값):")
day = getIntRange(1, 31, "일을 입력하시오(1부터 31사이의 값:")
print("")
print(f"입력된 날짜는 {month}월 {day}일 입니다.")
"""

# ex8 함수를 2개 만듦
"""
def transtostr(num):
    if num == 9:
        return "구"
    elif num == 8:
        return "팔"
    elif num == 7:
        return "칠"
    elif num == 6:
        return "육"
    elif num == 5:
        return "오"
    elif num == 4:
        return "사"
    elif num == 3:
        return "삼"
    elif num == 2:
        return "이"
    elif num == 1:
        return "일"
    elif num == 0:
        return "영"

def getMoneyText(amount):
    num_100 = transtostr(amount // 100)
    num_10 = transtostr(amount % 100 // 10)
    num_1 = transtostr(amount % 100 % 10)

    if amount == 1000:
        print(f"천원")
    elif amount >= 100:
        print(f"{num_100}백 {num_10}십 {num_1}원")
    elif amount >= 10:
        print(f"{num_10}십 {num_1}원")
    elif amount >= 0:
        print(f"{num_1}원")


money = int(input("1000 이하의 금액을 입력하시오: "))
getMoneyText(money)
"""

# ex9
"""
def max_same_num(num1, num2):
    for i in range(min(num1, num2), 0, -1):
        if num1 % i == 0 and num2 % i == 0:
            return i

num1 = int(input("첫 번째 정수: "))
num2 = int(input("두 번째 정수: "))

print(max_same_num(num1, num2))
"""

# ex10
"""
def testPrime(n):
    if n == 2:
        return 0
    else:
        divisor = 2

        while divisor < n:
            if n % divisor == 0:
                return 1 # 만나는 즉시 함수를 끝냄
            
            divisor += 1

        return 0


for i in range(2, 101, 1):
    if testPrime(i) == 0:
        print(i, end = " ")
    else:
        continue
"""

# ex11 # reverse() 사용, 리스트, 정수->문자열->정수
# 10진수 -> 2진수: 몫을 2로 나누어 0이 될때까지 나눔, 나머지를 역순으로 정렬
"""
def deci2bin(n):
    temp = []
    num = 0
    n2 = ""

    while n // 2 != 0:
        temp.append(n % 2)
        n = n // 2

    temp.append(n)

    temp.reverse()

    for i in range(len(temp)):
        n2 = n2 + str(temp[i])
        int(n2)

    return n2

number = int(input("10진수: "))
print(deci2bin(number))
"""

# ex12
"""
def getSorted(x, y):
    M = max(x, y)
    m = min(x, y)

    return m, M

num1 = int(input("첫 번째 정수: "))
num2 = int(input("두 번째 정수: "))
min, max = getSorted(num1, num2)
print(f"({min}, {max})")
"""

# ex13
"""
import random

def dice_game():
    flag = True
    human = random.randint(1, 6)
    cpu = random.randint(1, 6)

    while flag == True:
        print("=========== dice_game() 호출 ===========")
        print("인간: 주사위값=", human)
        print("컴퓨터: 주사위값=", cpu)

        if human == cpu:
            print("비김")
        elif human > cpu:
            print("인간승리")
        elif human < cpu:
            print("컴퓨터 승리")

        print("=========== dice_game() 복귀 ===========")
        print("")

        ss = input("중단할까요?  Y/Ny")

        if ss == "Y":
            flag = False
        elif ss == "Ny":
            continue

dice_game()
"""

# ex14
"""
def func(g):
   x = 2
   y = 1

   x_g = x / g

   if abs(x_g - g) < 0.001:
       return g
   else:
       average = (g + x_g) / 2
       return func(average)

g = 1
print(func(g))
"""

