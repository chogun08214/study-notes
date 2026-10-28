# Chapter 8 객체와 클래스

# 8-1
# 객체(object): 함수와 변수를 하나의 단위로 묶을 수 있는 방법 - 객체지향

# 8-2 객체 지향 프로그래밍
# 서로 관련 있는 데이터와 함수를 묶어서 객체로 만들고 이들이 하나로 모여 하나의 프로그램

# 객체 지향 프로그래밍
# 고유의 기능을 수행하며 다른 객체들과 상호작용

# 절차 지향과 객체 지향
# 절차 지향 프로그래밍: 프로시저(함수)를 기반으로 하는 프로그래밍 방법, 전체 프로그램은 함수들의 집합으로 이루어짐
# 문제를 더 작은 서브 함수로 분해하여 원하는 수준에 도달할 때까지 이 과정을 반복함으로써 문제를 해결
# 단점은 서로 관련된 데이터와 함수를 묶을 수 없음

# 객체 지향 프로그래밍
# 객체 지향 프로그래밍: 함수와 데이터를 묶음 - 캡슐화

# 객체
# 객체: 하나의 물질
# 속성: 자동차의 메이커, 색상, 연식, 가격 등
# 동작: 자동차가 주행, 방향 전환, 정지 등

# 클래스
# 객체들은 설계도에 의하여 생성
# 클래스: 객체에 대한 설계도, 특정한 종류의 객체들을 찍어내는 청사진
# 클래스로부터 만들어지는 객체를 그 클래스의 인스턴스라고 함

# 파이썬에서는 모든 것이 객체
# 객체의 특징은 우리가 사용할 수 있는 메소드를 가지도 있음 (메소드 ex: insert(), remove(), upper()등)

# 공용 인터페이스: 클래스에 의하여 제공되는 메소드
# 캡슐화: 공용 인터페이스만 제공하고 구현 세부 사항을 감추는 것 (데이터와 알고리즘을 묶음)

# 8-3 클래스 작성
# 클래스: 객체의 형태를 정의하는 틀(template)

# class 클래스이름:
#   def __init__(self, ...):
#       ...
#   def 메소드1(self, ...):
#       ...
#   def 메소드2(self, ...):
#       ...
#
# class Counter:
#   def __init__(self): # 생성자를 정의
#       self.count = 0
#   def increment(self): # 메소드를 정의
#       self.count += 1

# 클래스 안에서 변수와 함수를 정의
# 인스턴스 변수: 클래스 안에서 정의된 변수
# 메소드: 클래스 안에 정의된 함수
# 멤버: 인스턴스 변수 + 메소드
# 인스턴스 변수는 객체의 속성을 나타내고 메소드는 객체의 동작을 나타냄

# 변수 이름 앞에 self.을 붙이고 값을 저장하면 인스턴스 변수가 됨

# 생성자 이름은 항상 __init__()
# 생성자 메소드는 객체가 생성되면 반드시 호출되어서 객체를 초기화하는 함수

# 클래스를 정의할 때는 키워드 class로 시작하며 클래스의 이름을 뒤에 붙임
# 클래스 이름의 첫 글자는 일반적으로 대문자로 함
# 클래스 본채는 들여쓰기 해야 함
# 클래스 본체 안에 메소드를 정의
# 모든 메소드의 첫 번째 매개 변수는 객체를 가리키는 self 변수여야 함

# __init__() 메소드는 생성자라고 함
# 생성자는 객체를 초기화하는 메소드로서 클래스로 객체를 생성할 때 기폴트로 호출
# init 앞뒤에 반드시 __을 추가해야 함
# 항상 자기 자신을 가리키는 self가 매개 변수에 포함
# 인스턴스 변수는 생성자 안에서 초기화해야 함

# 메소드의 첫 번째 매개 변수는 항상 self
# 인스턴스 변수에 접근할 때도 앞에 self를 붙여야 함

# 객체 생성
# 클래스는 객체를 찍어내기 위한 틀을 만든 것이므로 아직 객체는 생성되지 않았음
# 클래스는 객체를 만들기 위한 설계도
# a = Counter()
# 클래스 이름에 ()을 붙여서 함수처럼 호출하면 객체가 생성
# 객체가 생성되며 생성자 메소드인 __init__()가 자동으로 호출

# 객체의 멤버 접근
# 객체가 가지고 있는 메소드를 호출하려면 객체 이름에 점(.)을 붙이고 메소드 이름을 적어주면 됨
# 객체가 가지고 있는 변수에 접근 할때도 객체 이름에 점(.)을 붙이고 변수 이름을 적어주면 됨
# 객체이름.변수
# 객체이름.메소드(인수)
#
# a = Counter()
# a.increment()
# a.count = 100

# class Counter:
#   def __init__(self):
#       self.count = 0
#   def increment(self):
#       self.count += 1
#
# a = Counter()
# a.increment()
# print("카운터 값=", a.count)

# Counter()라고 호출하면 객체가 생성되고 객체의 참조값을 변수 a에 저장
# 객체가 생성되며 생성자 메소드 __init__()가 호출되어서 인스턴스 변수 count가 생성되고 0으로 초기화
# a의 increment()를 호출하면 count 값이 하나 증가
# a.count하면 객체 a의 변수 count의 현재값을 얻을 수 있음

# 클래스 당 하나의 생성자만을 허용, 매개변수에 기본값을 줄 수 있는 기능을 사용하면 어느 정도 보완
# 생성자도 함수의 일종이므로 매개 변수를 가질 수 있음
# class Counter:
#   def __init__(self, init_value = 0): # 클래스의 생성자에서 카운터의 초기값을 받아서 그 값으로 초기화
#       self.count = init_value

# a = Counter(100) # 카운터의 초기값은 100
# a = Counter() # 카운터의 초기값은 0

# 하나의 클래스로 객체는 많이 만들 수 있음
# 하나의 클래스로 여러 개의 객체를 만들 수 있음
# 클래스로 생성된 각각의 객체는 별도의 인스턴스 변수를 가짐
# class Counter:
#   def __init__(self, initValue = 0):
#       self.count = initValue
#   def increment(self):
#       self.count += 1
#
# a = Counter(0) # 0으로 초기화한 Counter 객체 생성
# b = Counter(100) # 100으로 초기화한 Counter 객체 생성

# Counter 클래스로 객체 a와 b를 작성 하였다면 객체 a와 b는 모두 자신만의 count 인스턴스 변수를 가짐
# 동일한 클래스로 객체를 여러 개 생성하더라도 객체가 가지고 있는 변수의 값은 다를 수 있음
# 객체가 가지고 있는 데이터는 객체마다 다르게 설정할 수 있음

# Tv 클래스 정의
# class Television:
#   def __init__(self, channel, volume, on):
#       self.channel = channel # 인스턴스 변수
#       self.volume = volume
#       self.on = on
#
#   def show(self): # 객체가 이미 가지고 있는 값
#       print(self.channel, self.volume, self.on)
#
#   def setChannel(self, channel): # 외부에서 값을 받아 객체의 상태를 바꿈
#       self.channel = channel
#
#   def getChannel(self):
#       return self.channel
#
# t = Television(9, 10, True) # 객체를 생성
# t.show()
# t.setChannel(11)
# t.show -> 9 10 True
#           11 10 True

# circle.py 원 클래스
"""
import math

class Circle:
    def __init__(self, radius = 0):
        self.radius = radius

    def getArea(self):
        return math.pi * radius * radius

    def getPrimeter(self):
        return 2 * math.pi * radius

c = Circle(10)
print("원의 면적", c.getArea())
print("원의 둘레", c.getPrimeter())
"""

# 자동차 클래스 작성
"""
class Car:
    def __init__(self, speed, color, model):
        self.speed = speed
        self.color = color
        self.model = model

    def drive(self):
        self.speed = 60

myCar = Car(0, "blue", "E-class")
print("자동차 객체를 생성하였습니다.")
print("자동차의 속도는", myCar.speed)
print("자동차의 색상은", myCar.color)
print("자동차의 모델은", myCar.model)
myCar.drive()
print("자동차의 속도는", myCar.speed)
"""

# 8-4 정보 은닉
# 마음대로 인스턴스 변수의 값을 변경하는 것은 좋은 방법이 아님

# 인스턴스 변수의 값이 올바르지 않게 변경될 수 있음

# 클래스를 유지 보수하는 것이 어려워짐

# 정보은닉: 구현의 세부 사항을 클래스 안에 감춤, 클래스 안의 데이터를 외부에서 마음대로 변경하지 못하게 함
# 클래스 안에 변수를 선언: private (외부로부터의 접근이 차단 됨)
# 변수는 감추고 외부에서는 메소드만 사용하게 함
# 인스턴스 변수를 private으로 정의하려면 변수 이름 앞에 __을 붙이면 됨
# private이 붙은 인스턴스 변수는 클래스 내부에서만 접근 가능

# student.py 학생을 클래스로 모델링
"""
class Student:
    def __init__(self, name = None, age = 0):
        self.__name = name # __ 변수 앞에 붙으면 외부에서 변경 금지
        self.__age = age

obj = Student()
print(obj.__age) # 오류 발생 
"""

# 메소드를 정의 할 때도 앞에 __을 붙이면 변수의 경우와 비슷

# 접근자와 설정자
# private이 앞에 붙은 인스턴스 변수와 메소드는 클래스 내부에서만 접근 가능, 외부에서는 접근 불가
# 외부에서 이들 변수 값이 필요한 경우 특수한 메소드 사용

# 접근자: 인스턴스 변수값을 반환
# 설정자: 인스턴스 변수값을 설정
# get이나 set이 메소드 이름 앞에 붙여짐

# student.py
"""
class Student:
    def __init__(self, name = None, age = 0):
        self.__name = name
        self.__age = age

    def getAge(self):
        return self.__age

    def getName(self):
        return self.__name

    def setAge(self, age):
        self.__age = age

    def setName(self, name):
        self.__name = name

obj = Student("Hong", 20)
print(obj.getName())
"""

# 인스턴스 변수가 private로 정의되어 있더라도 외부에서는 접근자나 설정자 메소드를 이용하여 불편 없이 인스턴스 변수의 값을 변경하거나 값을 읽을 수 있음

# account.py 은행 계좌
"""
class BankAccount:
    def __init__(self, balance = 0):
        self.__balance = balance

    def withdraw(self, amount):
        self.balance = self.__balance - amount
        print("통장에서 ", amount, "가 출금되었음")
        return self.__balance

    def deposit(self, amount):
        self.__balance = self.__balance + amount
        print("통장에 ", amount, "가 입금되었음")
        return self.__balance

a = BankAccount()
a.withdraw(100)
a.deposit(10)
"""

# 8-5 객체 참조
# 변수는 실제로 객체를 저장하지 않음
# 변수는 객체의 메모리 주소를 저장
# 객체 자체는 메모리의 다른 곳에 저장

# class Televison:
#   def __init__(self, channel, volume, on):
#       self.channel = channel
#       self.volume = volume
#       self.on = on
#
#   def setChannel(self, channel):
#       self.channel = channel
#
# t = Televison(11, 10, True)

# 변수 t는 객체의 주소만 저장
# 생성자 Televison()은 새로운 객체에 대한 주소를 반환하고 이것이 변수 t에 저장
# 객체의 주소 = 객체의 참조값
# 일반적으로 메모리 주소이지만 다른 값이 될 수 도 있음
# 객체를 구별하여 참조할 수 있는 값이면 됨

# 참조 공유
# 객체의 참조값을 저장하고 있는 변수를 다른 변수로 복사
# t = Televison(11, 10, True)
# s = t
# 객체가 복사되는 것이 아닌 참조값만 복사되어 변수 s에 저장 (변수 s와 t가 동일한 객체를 가리킴)

# s를 통하여 객체를 수정
# t = Televison(11, 10, True)
# s = t
# s.channel = 9
# t가 가리키는 객체의 값도 변경

# is & is not
# 2개의 변수가 동일한 객체를 참조하고 있는지 검사
# if s is t:
#   print("2개의 변수는 동일한 책체 참조")
# if s is not t:
#   print("2개의 변수는 다른 객체 참조")

# is는 두 객체가 저장하고 있는 데이터가 동일한지를 비교하지 않음
# 두 객체가 참조하고 있는 객체가 동일한지만 검사

# None 참조값
# 변수가 현재 아무것도 가리키고 있지 않다면 None으로 설정하는 것이 옳음
# None은 아무것도 참조하고 있지 않다는 것을 나타냄
# myTv = None

# 어떤 변수가 None인지 아닌지 검사
# if myTv is None:
#   print("현재 Tv가 없습니다.")

# None을 가지고 있는 변수를 이용하여 어떤 객체의 멤버를 호출하면 오류
# myTv = None
# myTv.setChannel(5) # 오류

# 객체를 함수로 전달
# 객체가 함수로 전달되었을 때, 함수 안에서 객체를 변경 -> 어떤 객체가 전달되었느냐에 따라 다름
# if 숫자나 문자열과 같은 변경 불가능한 객체가 전달되면 객체는 변경x
# but 우리가 작성한 객체가 전달되면 함수가 객체를 변경 가능

# class Televison:
#   def __init__(self, channel, volume, on):
#       self.channel = channel
#       self.volume = volume
#       self.on = on
#
#   def show(self):
#       print(self.channel, self.volume, self.on)
#
# def setSilentMode(t):
#   t.volume = 2
#
# myTv = Televison(11, 10, True)
# setSilentMode(myTv)
# myTv.show() -> 11 2 True

# 함수에 객체를 전달하면 객체의 참조값이 변경
# 함수 안에서 객체의 참조값을 이용하여 객체를 찾아서 객체 안의 내용을 변경하면 원본 객체가 변경

# 8-6 클래스 변수
# 인스턴스 변수는 항상 객체를 통하여 사용 but 객체를 통하지 않고 사용할 수 있는 변수를 생성하는 것이 가능
# 이 변수는 모든 객체를 통틀어서 하나만 생성되고 모든 객체가 이것을 공유 -> 클래스 멤버
# 클래스를 정의할 때, 메소드와 동일한 수준에서 변수를 정의하면 클래스 변수

# 인스턴스 변수 vs 클래스 변수
# 클래스 변수는 정적변수라고도 함

# 동일한 클래스 설게도를 이용하여 많은 객체들이 생성될 때 각각의 객체(인스턴스)들은 자신만의 변수를 가짐
# 이들 변수들은 인스턴스마다 별도로 생성되기 때문에 인스턴스 변수라고 함
# 각 객체는 이들 변수에 대하여 별도의 기억 공간을 가지고 있으며 각기 다른 값을 가지고 있음

# 모든 객체에 공통인 변수가 필요한 경우가 있음 -> 클래스 변수
# 클래스 변수는 하나의 클래스에 하나만 존재
# 객체보다는 클래스와 연결, 모든 객체들은 하나의 클래스 변수를 공유
# 클래스 변수를 만들려면 클래스 안이지만 메소드의 외부에 변수를 생성
# 클래스 변수는 인스턴스를 생성하지 않아도 사용이 가능

# class Television:
#   serialNumber = 0 # 클래스 변수
#
#   def __init__(self, channel, volume, on):
#       self.channel = channel
#       self.volume = volume
#       self.on = on
#       Television.serialNumber += 1
#       self.number = Television.serialNumber
#
#   def show(self):
#       print(self.channel, self.volume, self.on, self.number)
#
# myTv = Television(11, 10, True)
# myTv.show() -> 11 10 True 1

# 상수정의
# 상수들은 흔히 클래스 변수로 정의

# class Monster:
#   WEAK = 0 # 상수값 정의
#   NORMAL = 10
#   STRONG = 20
#   VERY STRONG = 30
#
#   def __init__(self):
#       self.health = Monster.NORMAL

# eat() 메소드가 호출되면 건강상태를 STRONG으로 변경

# def eat(self):
#   self.health = Monster.STRONG

# 다른 캐릭터를 공격하면 건강이 약해짐
# def attack(self):
#   self.health = Monster.WEAK

# dog.py 클래스 변수 (강아지를 클래스로 모델링)
"""
class Dog:
    kind = "Bulldog"

    def __init__(self, name, age):
        self.name = name
        self.age = age

a = Dog("Baduk", 2)
b = Dog("Marry", 3)

print(a.kind)
print(b.kind)
print(Dog.kind)
print(a.name)
print(b.name)
"""

# 8-7 특수 메소드
# 특수 메소드: +, -, *, /
# 객체에 대하여 +, -, *, /와 같은 연산을 적용하면 자동으로 호출

# __add__(self, y): x + y, 덧셈
# __sub__(self, y): x - y, 뺄셈
# __mul__(self, y): x * y, 곱셈
# __truediv__(self, y): x / y, 실수 나눗셈
# __floordiv__(self, y): x // y, 정수 나눗셈
# __mod__(self, y): x % y, 나머지
# __divmod__(self, y): 실수나눗셈과 나머지
# __pow__(self, y): x ** y, 지수
# __lshift__(self, y): x << y, 왼쪽 비트 이동
# __rshift__(self, y): x >> y, 오른쪽 비트 이동
# __le__(self, y): x <= y, 작거나 같음
# __lt__(self, y): x < y, 작다
# __ge__(self, y): x >= y, 크거나 같음
# __gt__(self, y): x > y, 크다
# __eq__(self, y): x == y, 같다
# __neq__(self, y): x != y, 같지 않다

# __str__() 메소드
# 객체를 출력하였을 때 객체 안의 정보들을 출력

"""
class Counter:
    def __init__(self, count = 0):
        self.count = count

    def increment(self):
        self.count += 1

    def __str__(self):
        msg = "카운트값: " + str(self.count)
        return msg

a = Counter(100)
print(a)
"""

# __str__() 메소드는 우리가 객체를 print()로 출력할 때 자동적으로 호출
# 객체의 데이터를 문자열로 만들어서 반환

# vector.py 벡터를 클래스로 모델링
"""
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __str__(self):
        return '(%g, %g)' % (self.x, self.y)

u = Vector(0, 1)
v = Vector(1, 0)
w = Vector(1, 1)
a = u + v
print(a)
"""

# dice.py 주사위를 클래스로 모델링
"""
from random import randint

class Dice:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y
        self.size = 30
        self.__value = 1

    def roll_dice(self):
        self.__value = randint(1, 6)

    def read_dice(self):
        return self.__value

    def print_dice(self):
        print("주사위의 값=", self.__value)


d = Dice(100, 100)
d.roll_dice()
d.print_dice()
"""

# ex1
"""
class Cat:
    def __init__(self, name = None, age = 0):
        self.name = name
        self.age = age

    def setName(self, name):
        self.name = name

    def getName(self):
        return self.name

    def setAge(self, age):
        self.age = age

    def getAge(self):
        return self.age

    def __str__(self):
        msg = f"{self.name} {str(self.age)}" # print() 있다 생각하고 사용
        return msg


missy = Cat("Missy", 3)
lucky = Cat("Lucky", 5)
print(missy)
print(lucky)
"""

# ex2
"""
class Rocket:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def moveUp(self):
        self.y += 1

myRocket =  Rocket()
print("로켓의 높이:", myRocket.y)

myRocket.moveUp()
print("로켓의 높이:", myRocket.y)
"""

# ex3
"""
class BOX:
    def __init__(self, l = 0, h = 0, d = 0):
        self.l = l
        self.h = h
        self.d = d

    def getHeight(self):
        return self.h

    def getLength(self):
        return self.l

    def getDepth(self):
        return self.d

    def setHeight(self, h):
        self.h = h

    def setLength(self, l):
        self.l = l

    def setDepth(self, d):
        self.d = d

    def __str__(self):
        msg = f"({self.l}, {self.h}, {self.d})"
        return msg

b1 = BOX(100, 100, 100)
print(b1)
print("상자의 부피는", b1.getHeight()*b1.getLength()*b1.getDepth())
"""

# ex4
"""
class Rectangle:
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def getW(self):
        return self.width

    def getH(self):
        return self.height

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def setW(self, width):
        self.width = width

    def setH(self, height):
        self.height = height

    def getArea(self):
        return self.width * self.height

    def overlap(self, r):
        if self.x > r.x + r.width or r.x > self.x + self.width or self.y > r.y + r.height or r.y > self.y + self.height:
            print("r1과 r2는 서로 겹치지 않습니다.")
        else:
            print("r1과 r2는 서로 겹칩니다.")

r1 = Rectangle(0, 0, 100, 100)
r2 = Rectangle(10, 10, 100, 100)
r1.overlap(r2)
"""

# ex5
"""
class Triangle:
    def __init__(self, a1, a2, a3):
        self.angle1 = a1
        self.angle2 = a2
        self.angle3 = a3
        self.numberOfSides = 3

    def getAngle1(self):
        return self.angle1

    def getAngle2(self):
        return self.angle2

    def getAngle3(self):
        return self.angle3

    def setAngle1(self, angle1):
        self.angle1 = angle1

    def setAngle2(self, angle2):
        self.angle2 = angle2

    def setAngle3(self, angle3):
        self.angle3 = angle3

    def checkAngles(self):
        if self.angle1 + self.angle2 + self.angle3 == 180:
            return True
        else:
            return False

triangle = Triangle(90, 30, 60)
print(triangle.checkAngles())
"""

# ex6
"""
class Person:
    def __init__(self, name = None, mobile = None, office = None, email = None):
        self.name = name
        self.mobile = mobile
        self.office = office
        self.email = email

    def getName(self):
        return self.name

    def getMobile(self):
        return self.mobile

    def getOffice(self):
        return self.office

    def getEmail(self):
        return self.email

    def setName(self, name):
        self.name = name

    def setMobile(self, mobile):
        self.mobile = mobile

    def setOffice(self, office):
        self.office = office

    def setEmail(self, email):
        self.email = email

    def __str__(self):
        msg = f"{self.name} {self.mobile} {self.office} {self.email}"
        return msg

p1 = Person("Kim", office = "1234567", email = "kim@company.com") # 생성자의 변수 이름과 같아야 함 
p2 = Person("Park", office = "2345678")
p2.setEmail("park@company.com")
print(p2)
"""

# ex7
"""
class PhoneBook:
    def __init__(self):
        self.contacts = {}

    def add(self, name, mobile = None, office = None, email = None):
        self.contacts[name] = {"mobile": mobile, "office": office, "email": email} # {"Kim" : {"mobile": mobile, "office": office, ..., "Park": {...}}}

    def __str__(self):
        msg = ""
        for name, info in self.contacts.items():
            msg += name + "\n"
            if info["mobile"]:
                msg += "mobile phone: " + info["mobile"] + "\n"
            if info["office"]:
                msg += "office phone: " + info["office"] + "\n"
            if info["email"]:
                msg += "email address: " + info["email"] + "\n"
            msg += "\n"
        return msg


obj = PhoneBook()
obj.add("Kim", office = "1234567", email = "kim@company.com")
obj.add("Park", office = "2345678", email = "park@company.com")
print(obj)
"""

# ex8
"""
class Song:
    def __init__(self, lyrics):
        self.lyrics = lyrics

    def sing(self):
        for i in self.lyrics:
            print(i)

aSong = Song(["Twinkle, twinkle, little star,",
              "How I wonder you, you are!",
              "Up above the world so high,",
              "Like a diamond in the sky."])
aSong.sing()
"""

