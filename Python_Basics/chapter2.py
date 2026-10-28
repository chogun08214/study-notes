# Chapter 2 변수와 수식

# 2-2 변수

# 변수: 컴퓨터의 메모리 공간에 이름을 붙이는 것으로 값을 저장 가능
# 변수에 어떤 타입의 데이터도 저장 가능

# 변수 정의 - 할당문 또는 대입문 사용
# 변수이름 = 값 -> x = 100

# 변수: 데이터 값을 저장, 컴퓨터 안의 메인 메모리 안에 만들어 짐
# 변수에 있는 값은 언제든지 변경 가능

# sum.py 두 수의 합 계산
"""
x = 100
y = 200
sum = x + y
print("합은", sum)
"""

# area.py 원의 면적 계산
"""
radius = 10

area = 3.14 * radius * radius

print("반지름", radius, "인 원의 면적=", area)
"""

# 변수의 이름
# 첫 글자는 영문자 또는 _로 시작, 나머지 문자는 문자, 숫자 또는 _ 이어야 함
# #와 같은 기호는 사용x, 공백도 x
# 소문자와 대문자는 다르게 취급
# 예약어 사용 불가

# 2-3 자료형

# 자료형: 데이터의 종류
# 변수에 어떤 자료형의 값이든지 저장 가능

# 자료형을 알려면?
# type(수식) -> type(1234)

# 파이썬에서는 모든 것이 객체(object)
# 변수에 저장되는 것은 실제 값이 아니고 객체의 주소

# 2-4 변수의 세부 구현 사항

# 객체의 참조값(주소)를 알려면 id() 함수
# id(변수) -> x = 3, id(x)

# 참조값은 실행할 때마다 달라질 수 있음
# 참조값을 객체가 저장된 메모리의 주소로 생각 가능
# 변수를 다른 변수에 복사하여도 같은 주소 (새로운 값이 할당되면 주소가 달라짐) -> x = 3, y = x, id(x) = id(y) if y = 10 id(x) != id(y)

# 불변객체: 한 번 만들어지면 변경x (정수, 부동소수점수, 문자열), 변수에 저장된 값을 변경하면 값을 저장하는 객체가 새로 생성, 새로운 객체의 참조값이 변수에 저장
# 가변객체: 직접 객체를 변경 가능 (리스트, 딕셔너리)

# light_speed.py 별까지의 거리 계산
"""
speed = 300000
distance = 40000000000000
secs = distance / speed
light_year = secs / (60 * 60 * 24 * 365)
print(light_year, "광년")
"""

# 2-5 주석과 상수

# 주석
# '#'로 시작하면 줄의 끝까지 주석 취급

# 상수: 한번 값이 결정되면 절대로 변경되지 않는 변수
# 상수도 단순한 변수로 정의
# 변수의 이름을 대문자, 일반적인 변수와 구분

# 매직 넘버: 설명없이 등장하는 숫자

# volume.py 원기둥의 부피 계산
"""
PI = 3.14

radius = 5
height = 10

volume = PI * radius * radius * height

print("반지름=", radius, "높이=", height, "원기둥의 면적=", volume)
"""

# 2-6 수식

# 산술연산자: 덧셈, 뺄셈, 곱셈, 나눗셈, 나머지 연산을 실행하는 연산자
# 정수 나눗셈: //, 실수 나눗셈: /, 나머지: %
# 수식에서 정수와 부동소수점을 혼합하여 연산하면 수식의 결과는 항상 부동소수점 값

# 할당 연산자: =, 변수에 값을 저장하는 연산자
# 하나의 값을 여러 변수에 할당 -> x = y = z = 0
# 동시에 여러 변수에 값을 할당 -> x, y, z = 10, 20, 30
# 변수 x와 변수 y의 값을 교환 -> x, y = y, x

# 복합 연산자: 할당 연산자와 다른 연산자를 합쳐 놓은 연산자 -> +=
# x += 2;

# 지수: **
# 다른 연산자들보다 높은 우선순위
# 오른쪽에서 왼쪽으로 계산 -> 2**2**3 = 2**(2**3) = 2**8

# 우선순위
# ① 지수 ② 곱셈, 나눗셈, 나머지 ③ 덧셈, 뺄셈
# 괄호는 어떤 연산자보다도 먼저 계산

# invest.py 복리 계산
"""
money = 24
rate = 0.08
year = 382

result = money * (1 + rate)**year
print(result)
"""

# 2-7 타입 변환과 반올림

# 정수와 부동소수점수를 동시에 사용하여 수식을 만들면 정수를 부동소수점수로 변환: 자동적인 타입 변환

# 강제적 타입 변환
# 새로운타입(변수) -> x = 3.14, y = int(x)

# round(): 실수를 반올림
# 소수점 2번째 자리에서 반올림 -> round(x, 2)

# 변수가 가지고 있는 값을 변경하는 것이 아닌 변수의 값을 변환시켜 제공

# 2-8 문자열

# 문자열(string): 문자들의 나열
# 텍스트를 큰 따욤표("...")로 감싸면 문자열
# 문자열은 변수에 저장될 수 있음
# 작은 따옴표('...')도 가능
# "로 시작했다가 '로 끝나면 오류

# "철수가 "안녕"이라고 말했습니다." - 오류
# "철수가 '안녕'이라고 말했습니다."

# 세 따옴표("""..."""): 여러 줄의 문자열을 변수에 할당
# 문자열 안의 줄바꿈이나 스페이스 등이 그대로 유지된 채 출력

# + 연산자로 2개의 문자열을 하나의 문자열로 합칠 수 있음: 문자열 접합
# 문자열을 반복하려면 * 연산자를 사용

# 수치형 데이터(정수, 실수)와 문자열을 구분
# 문자열의 연결은 문자열끼리만 가능

# str(): 문자열로 변환
# 문자열을 숫자로 변환 - int(), float()

# 특수 문자열
# \n: 줄바꿈, \t: 탭문자, \\: 역슬래시 자체. \": 큰 따옴표 자체, \': 작은 따옴표 자체

# 문자열 안의 문자는 인덱스를 사용하여 접근 가능
# 첫 번째 문자는 0, 대괄호 안에 인덱스 표기하여 접근 -> s[0]
# 음의 인덱스: 맨 마지막 문자의 인덱스는 항상 -1

# 문자열은 객체
# 객체: 관련 있는 변수와 함수를 하나로 묶은 것
# 메소드:: 객체 안에 정의된 함수, 특정 유형의 객체에서만 사용 가능
# 객체를 적은 후 .을 찍고 메소드의 이름

# robot.py 로봇 기자
"""
stadium = input("경기장은 어디입니까?")
winner = input("이긴팀은 어디입니까?")
loser = input("진팀은 어디입니까?")
mvp = input("우수선수는 누구입니까?")
score = input("몇대몇입니까?")

print("")
print("===========================================")
print("오늘", stadium, "에서 야구 경기가 열렸습니다.")
print(winner, "과", loser, "은 치열한 공방전을 펼쳤습니다.")
print(mvp, "이 맹활약을 하였습니다.")
print("결국", winner, "가", loser, "를", score, "로 이겼습니다.")
print("===========================================")
"""

# 2-9 입력과 출력

# input(): 사용자로부터 데이터를 얻음
#사용자의 입력을 문자열 형태로 반환
# 변수 = input(안내메시지) -> x = input("이름을 입력하시오: ")
# x = input("첫 번째 정수"), y = input("두 번째 정수"), sum = x + y, print(sum) -> 300400 - 문자열
# 정수값을 읽으려면 input() 함수를 사용하여 문자열을 얻은다음 int() 함수를 사용하여 정수로 변환
# x = int(input("첫 번째 정수?")

# 부동소수점 값을 읽으려면 입력된 문자열을 부동소수점으로 변환, float()
# eval(): 사용자의 입력을 평가하여 정수나 실수로 변환

# f-문자열: 문자열의 앞에 f를 붙이고 문자열 중간에서 {}을 이용
# x = 100, y = 200, print(f"{x}와 {y}의 합={x+y}")

# "%.2f": 소수점 이하 두 자리 숫자
# 필드 너비 지정: "%10.2f" -> 10개의 문자, 6개의 공백과 4개의 문자 -      7.76
# "10.2f": 형식지정자, 값을 출력하는 형식을 나타냄, 문자 f는 부동소수점 값, 정수를 출력할때는 d, 문자열 s

# 형식문자열 % (값1, 값2, ..., 값n) -> p = 7.76, print("102f" % py)
# 하나 이상의 형식 지정자와 리터럴 문자가 포함, 형식지정자가 아닌 문자는 그대로 출력
# 출력하는 값이 여러 개: 값을 괄호로 묶고 쉼표로 구분
# print("평: %102f -> 제곱미터: %8.2f" % (py, area))

# char_bot.py 대화
"""
print("안녕하세요?")
print("")
name = input("이름이 어떻게 되시나요? ")
print("만나서 반갑습니다.", name + "씨")
print("이름의 길이는 다음과 같군요:", len(name))
print("")
age = int(input("나이가 어떻게 되나요? "))
print("내년이면", str(age +1) + "이 되시는군요." ) # 숫자와 문자열을 +로 자동 변환해서 합쳐주지 않음 
"""

# bmi.py BMI 계산
"""
weight = float(input("몸무게를 kg 단위로 입력하시오: "))
height = float(input("키를 미터 단위로 입력하시오: "))
BMI = weight / (height**2)
print("당신의 BMI=", BMI)
"""

# shpere.py 구의 부피 계산
"""
radius = float(input("구의 부피를 입력하시오: "))
volume = (4/3) * 3.141592 * radius**3
print("구의 부피=", volume)
"""

# atm.py 자판기
"""
price = int(input("물건값을 입력하시오: "))
print("===입력금액===")

money_1000 = int(input("1000원 지폐개수: "))
money_500 = int(input("500원 동전개수: "))
money_100 = int(input("100원 동전개수: "))

total_money = money_1000 * 1000 + money_500 * 500 + money_100 * 100 - price

n500 = total_money // 500
total_money = total_money % 500

n100 = total_money // 100
total_money = total_money % 100

n10 = total_money // 10
total_money = total_money % 10

n1 = total_money

print("===거스름돈 출력===")
print(f"500원= {n500} 100원= {n100} 10원= {n10} 1원= {n1}")
"""

# ex1
"""
X = int(input("x: "))
Y = int(input("y: "))

print("두수의 합:",  X + Y)
print("두수의 차:", X - Y)
print("두수의 곱:", X * Y)
print("두수의 평균:", (X + Y) / 2)
print("큰수::", max(X, Y))
print("작은수:", min(X, Y))
"""

# ex2
"""
chicken = int(input("닭의 수: "))
pig = int(input("돼지의 수: "))
cow = int(input("소의 수: "))

total = chicken * 2 + pig * 4 + cow *4
print("전체 다리의 수:", total)
"""

# ex3
"""
first = int(input("삼각형의 첫 번쨰 변의 길이: "))
second = int(input("삼각형의 두 번째 변의 길이: "))
result = (first + second) - 1
print("삼각형의 나머지 변의 최대 길이 =", result)
"""

# ex4
"""
hour = int(input("시간을 입력하시오: "))
minute = int(input("분을 입력하시오: "))
second = hour * 60**2 + minute * 60
print(hour, "시간", minute, "분은", second, "초입니다.")
"""

# ex5
"""
F = int(input("화씨 온도를 입력하시오: "))
C = round((F - 32.0) * 5/9, 2)
print(f"화씨 {F}도는 섭씨 {C}도에 해당합니다.")
"""

# ex6
"""
food_price = int(input("음식 비용: "))
print("팁 비율: 10%")
total = int(food_price + food_price * 0.1)
print(f"총액: {total}달러")
"""

# ex7
"""
x1 = int(input("x1="))
y1 = int(input("y1="))
x2 = int(input("x2="))
y2 = int(input("y2="))

distance = ((x1 - x2)**2 + (y1 - y2)**2)**0.5
print("두점 사이의 거리=", distance)
"""

# ex9
"""
number = int(input("정수="))

n1 = number // 1000
number = number % 1000

n2 = number // 100
number = number % 100

n3 = number // 10
number = number % 10

n4 = number

total = n1 + n2 + n3 + n4
print(total)
"""

# ex11
"""
drive = input("드라이브 이름: ")
directory = input("디렉토리 이름: ")
file = input("파일 이름: ")
extend = input("확장자: ")

print("완전한 이름은 " + drive + ":" + directory + file + "." + extend)
"""

# ex12
"""
number = int(input("숫자를 입력하시오: "))
foward = number // 1000
back = number % 1000
print(str(foward) + "," + str(back))
"""
