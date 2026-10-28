# Chapter7 파이썬 자료구조 II (튜플, 딕셔너리, 세트, 문자열)

# 7-2 자료구조?
# 자료들을 저장하는 여러 가지 구조: 자료구조, 데이터구조
# 시퀀스: 리스트, 요소로 구성, 요소간에는 순서가 존재, 시퀀스의 요소들은 번호를 부여받음(인덱스)
# str, bytes, bytearray, list, tuple, range
# 시퀀스에 속하는 자료 구조들은 동일한 연산을 지원 - 인섹식, 슬라이싱, 덧셈 & 곱셈 연산

# 7-3 튜플
# 튜플은 변경이 불가능

# 튜플_이름 = (항목1, 항목2, ...)
# fruits = () - 공백 튜플 생성
# fruits = ("apple", "banana", "grape") - 초기값을 가진 튜플 생성
# result = fruits[1] - 인덱스를 사용하여 요소에 접근

# 쉼표로 값을 분리하여 튜플을 하나의 변수 안에 패킹
# fruits = "apple", "banana", "grape"처럼 괄호 없이 항목들을 쉼표로 분리하여도 자동으로 튜플 생성

# 요소가 하나뿐인 튜플을 만들 경우 요소의 끝에 반드시 쉼표(,)를 추가
# if 쉼표가 없으면 평범한 수식
# tuple = ("apple", ) -> o
# tuple = ("apple") -> x

# 튜플의 요소도 인덱스를 사용하여 접근
# fruits[1] -> banana

# 요소 변경은 불가능

# 튜플 <-> 리스트
# 리스트로부터 생성 가능
# mylist = [1, 2, 3, 4]
# mytuple = tuple(mylist)

# tuple(): 다른 자료구조를 받아서 튜플로 반환, 튜플 객체를 샏성

# 튜플을 리스트로 변경
# mytuple = (1, 2, 3, 4)
# mylist = list(mytuple)

# 튜플 연산들
# 한 번 생성되면 요소 추가 불가능
# 요소 삭제도 불가능

# but 튜플이 숫자를 저장하고 있는 경우 += 연산자를 이용하여서 다른 튜플을 추가 가능
# 새로운 튜플이 생성
# fruits = ("apple", "banana", "grape")
# fruits += ("pear", "kiwi") -> ("apple", "banana", "grape", "pear", "kiwi")

# 튜플 안에 변경 가능 객체가 저장
# 튜플 자체는 변경 불가지만 튜플 안의 리스트는 변경 가능
# student = ("Kim", [3.1, 3.6, 4.0, 0.0])
# student[1][3] = 4.3 -> ("Kim", [3.1, 3.6, 4.0, 4.3])

# += 연산자를 이용하여 튜플을 리스트에 추가 가능
# numbers = [10, 20, 30]
# numbers += (40, 50) -> [10, 20, 30, 40, 50]

# 튜플 패킹과 언패킹
# 튜플 패킹: 여러 개의 항목을 가지는 튜플 생성
# 튜플 언패킹: 하나의 튜플 안에 저장된 데이터를 풀어서 개별 변수에 저장 가능
# x = ("apple", "banana", "grape") - 패킹
# (s1, s2, s3) = x - 언패킹

# 서로 다른 자료형에 대해서도 패킹과 언패킹 가능
# student = ("Kim", [3.1, 3.6, 5.0, 0.0])
# name, grades = student
# name -> Kim
# grades -> [3.1, 3.6, 5.0, 0.0]

# 데이터의 순서 변경
# n1 = 10
# n2 = 90
# n1, n2 = (n2, n1)

# 함수로부터 2개 이상의 값을 반환 받을 수 있음, 튜플 사용

# enumerate() 사용
# 요소의 인덱스 값이 필요한 경우
# enumerate()를 사용하여 인덱스 값과 요소 값에 안전하게 접근 가능
# 반복 가능한 객체(리스트 or 튜플)을 받아 각 요소에 대해 (인덱스, 값) 형태의 튜플을 반환
# fruits = ["apple", "banana", "grape"]
# result = list(enumerate(fruits)) -> [(0, "apple"), (1, "banana"), (2, "grape")]

# 튜플의 장점
# 튜플을 반복하는 것이 리스트 반복보다 빠름 why? 튜플은 변경 불가능 객체이기 때문
# 변경 불가능한 요소들로 이루어진 튜플은 딕셔너리의 키 가능
# 다른 개발자가 특정 데이터를 변경하는 것을 금지

# 7-4 세트
# 세트: 고유한 값들을 저장하는 자료구조
# 세트의 요소는 특정 순서로 저장되지 않으며 위치별로 액세스 불가능
# 리스트 연산보다 훨씬 빠름, 중복된 항목은 없어야 함

# 세트 생성
# 세트_이름 = {항목1, 항목2, 항목3, ...}
# numbers = {1, 2, 3} - 초기화된 세트 생성
# values = set() - 공백 세트 생성

# 리스트로부터 세트 생성 가능: set() 함수 사용
# 세트는 집합이기 때문에 요소가 중복되면 자동으로 중복된 요소를 제거
# numbers = set([1, 2, 3, 1, 2, 3]) -> {1, 2, 3}

# 문자열로부터 세트 생성 가능
# letters = set("abc") - 각 문자들이 하나의 요소가 됨

# 비어 있는 세트를 생성- 인수 없는 set() 함수 사용
# {}가 아님, {}은 공백 딕셔너리 생성
# nubmers = set()

# 세트의 연산
# all(): 세트의 모든 요소가 True인 영우 True
# any(): 하나의 요소라도 True이면 True
# len(): 세트 안에 저장된 요소의 개수를 얻을 수 있음

# 어떤 항목이 세트 안에 있는지를 검사하여면 in 연산자 사용
# fruits = {"apple", "banana", "grape"}
# if "apple" in fruits:
#   print("집합 안에 apple이 있습니다")

# 세트의 항목은 순서가 없기 때문에 인덱스를 가지고 세트의 항목에 접근 불가능
# but for 반목문을 이용하여 각 항목들에 접근 가능
# fruits = {"apple", "banana", "grape"}
# for x in fruits:
#   print(x, end =" ") -> grape banana grape

# 요소 추가하고 삭제하기
# 세트는 변경 가능한 객체, 세트에 요소를 추가하거나 삭제 가능
# 세트의 요소에는 인덱스가 없으므로 인덱싱이나 슬라이스 연산은 의미x

# add()를 사용하여 하나의 요소를 추가 가능
# fruits = {"apple", "banana", "grape"}
# fruits.add("kiwi") -> {"apple". "banana", "grape", "kiwi"}

# 요소를 삭제할 때는 remove()
# fruits.remove("kiwi") -> {"apple", "banana", "kiwi"}

# discard()
# 삭제하고자 하는 요소가 없으면 discard()는 그냥 넘어 가지만 remove()는 요소를 생성 

# clear(): 세트의 모든 요소를 삭제
# fruits = {"apple", "banana", "grape", "kiwi"}
# fruits.clear() -> set()

# update(): 세트에 여러 개의 항목을 추가
# fruits = {"apple", "banana", "grape"}
# fruits.update(["orange", "mango", "kiwi"]) -> {"apple", "banana", "grape", "orange", "mango", "kiwi"}, []이 아닌 {}도 가능

# 세트 함축 연산
# 동일한 숫자는 딱 한번 추가
# 숫자가 저장된 리스트, 리스트 안의 숫자가 짝수이면 숫자를 세트에 추가, 짝수가 아니면 추가 x
# alist = [1, 2, 3, 4, 5, 1, 2]
# result = {x for x in alist if x % 2 == 0} -> {2, 4}

# 부분 집합 연산
# 어떤 집합이 다른 집합의 부분 집합인지를 검사: < or issubset()
# <=: 진부분 집합을 검사
# A = {"apple", "banana", "grape"}
# B = {"apple", "banana", "grape", "kiwi"}
# if A < B:     # A.issubset(B)
#   print("A는 B의 부분집합")

# 2개의 세트가 같은지 검사
# == or !=

# A = {"apple", "banana", "grape"}
# B = {"apple", "banana", "grape","kiwi"}
# if A == B:
#   print("같음")
# else:
#   print("같지 않음")

# 교집합, 합집합, 차집합 연산
# 연사자나 메소드로 수행

# A = {"apple", "banana", "grape"}
# B = {"apple", "banana", "kiwi"}

# 합집합은 2개의 집합을 합하는 연산
# 줄복되는 요소는 제거
# 합집합은 | 연산자나 union() 메소드 사용
# C = A|B     # C = A.union(B)

# 교집합: 2개의 집합에서 겹치는 요소를 구하는 연산
# & 연산자나 intersection() 메소드 사용
# C = A & B   # C = A.intersection(B)

# 차집합: 하나의 집합에서 다른 집합의 요소를 빼는 것
# - 연산자나 difference() 메소드 사용
# C = A - B   # C = A.difference(B)

# 리스트 <-> 세트
# 리스트에 set() 함수를 적용하면 세트
# 세트에 list() 함수를 적용하면 리스트

# 리스트 안에 서로 다른 정수 개수 세기
# list1 = [1, 2, 3, 4, 5, 1, 2, 4]
# len(set(list1)) -> 5

# 2개의 정수 리스트에 공통적으로 들어있는 숫자?
# list1 = [1, 2, 3, 4, 5]
# list2 = [3, 4, 5, 6, 7]
# set(list1) & set(list2) -> {3, 4, 5}

# set(seq): 시퉌스에서 요소를 꺼내서 세트를 만듦

# str_ex1.py 문자열 2개의 공통 문자를 추출
"""
str1 = input("첫 번째 문자열: ")
str2 = input("두 번째 문자열: ")

same_word = set(str1) & set(str2) # set("abc abc")는 공백 포함

print("\n공통적인 글자: ", end="")

for i in same_word:
    if i != " ":
        print(i, end = " ")
"""

# str_ex2.py 중복되지 않은 단어의 개수 세기
"""
input_text = input("입력 텍스트: ")
word = input_text.split(" ") #.split(" )
unique = set(word)

print("사용된 단어의 개수=", len((unique)))
print(unique)
"""

# 7-5 딕셔너리
# 딕셔너리: 값과 관련된 키도 저장
# 중괄호{} 안에 쉼표(,)로 분리시켜 나열
# 항목은 키(key)와 값(value)로 구성
# 키와 값 사이에는 클론(:)이 있어야 함

# 딕셔너리_이름 = { 키1:값1, 키2:값2, 키3:값3, ...}
# capitals = {} # 공캑 딕셔너리 생성
# capitals = { "Korea":"Seoul", "USA":"Washington", "UK":"London"}

# 키의 자료형은 혼합되어도 된다
# 값(vlaue)은 어떤 유형이든 상관없지만 키(key)는 반드시 불변 객체이고 또 유일해야 함 -> 유일한 문자열이나 숫자, 튜플이어야 함
# 딕셔너리도 어떤 유형의 값도 저장 가능
# dict = {"Name":"홍길동", "Age":7, "Class":"초급"}

# 항목 탐색
# 키를 가지고 연관된 값을 찾음
# 키가 있어야 값을 찾을 수 있음
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# capitals['Korea"] -> Seoul

# 존재하지 않는 키를 제시하면 오류
# get() 함수를 사용하여 오류 방지
# get(): 해당 키를 찾을 수 없으면 None 반환, 두 번째 인수 지정시 키를 찾을 수 없는 경우 두 번째 인수 반환
# capitals.get("France", "해당 키가 없습니다")

# in과 not in은 딕셔너리에 저장된 키가 포함되어 있는지 여부 확인 가능
# if "France" in capitals:
#   print("포함")
# else:
#   print("불포함")

# 항목 추가
# 딕셔너리에 새로운 항목 추가
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# capitals["France"] = "Paris" -> {"Korea":"Seoul", "USA":"Washington", "UK":"London", "France":"Paris"}

# 처음부터 공백 딕셔너리를 생성하고 항목을 하나씩 추가
# capitals = {}
# capitals["Korea"] = "Seoul" -> {"Korea":"Seuol"}

# 딕셔너리를 출력할 때 쉼표로 구분된 키-값 쌍의 리스트는 항상 중괄호로 묶임
# 딕셔너리는 순서가 지정되지 않은 콜렉션 -> 출력 순서는 키-값 쌍이 딕셔너리에 추가된 순서와 다를 수 있음

# 다른 딕셔너리 전체를 현재 딕셔너리에 추가하고 싶으면 update() 사용
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# capitals.update({"France":"Paris", "Germany":"Berlin"}) -> {"Korea":"Seoul", "USA":"Washington", "UK":"London", "France":"Paris", "Germany":"Berlin"}

# 항목 삭제
# 딕셔너리의 특정 항목을삭제하려면 pop() 메소드 사용
# city = capitals.pop("UK")

# 주어진 키를 가진 항목이 없으면 에러 발생
# if "UK" in capitals:
#   capitals.pop("UK")

# clear(): 딕셔너리에 저장된 모든 키-값 쌍을 삭제
# 딕셔너리가 비어있는지 검색하려면 len() 사용
# capitals.clear()
# if len(capitals) == 0:
#   print("비어 있음")
# else:
#   print("항목 있음")

# 항목 방문
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# for key in capitals:
#   print(key, end = " ") -> Korea USA UK

# 딕셔너리 capitals은 키들만 내보냄
# 키가 있으면 dictionary[key] 하여서 값을 알 수 있음
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# for key in capitals:
#      print(key, ":", capitals[key]) -> Korea:Seoul, USA:Washington, UK:London

# 딕셔너리의 items() 메소드 사용
# capitals = {"Korea":"Seoul", "USA":"Washington", "UK":"London"}
# for key in capitals.items():
#   print(key, ":", value) -> Korea:Seoul, USA:Washington, UK:London

# items() 함수는 키와 값을 튜플로 반환, key와 value 변수로 언패킹 되어 반복

# 딕셔너리 함축
# dic = { x : x**2 for x in values if x % 2 == 0}
# values 리스트에서 값을 하나씩 꺼내서 x에 대입하고 x가 짝수이면 x**2를 계산하여 x와 묶어서 딕셔너리 생성

# dic = {i:str(i) for i in [1, 2, 3, 4, 5]}

# fruits = {"apple", "orange", "banana"}
# dic = {f : len(f) for x in fruits} -> {"apple":5, "orange":6, "banana":6}

# 하나의 딕셔너리를 다른 딕셔너리에 매핑
# 고유한 값을 가진 딕셔너리에서 키-값 쌍을 뒤집을 수 있음, 값이 고유해야 키로 바꿀 수 있음
# dic1 = {"One":1, "Two":2, "Three":3}
# dic2 = {n:w for w, n in dic1.items()}

# d.values(): 딕셔너리 안의 모든 값의 시퀀스를 반환
# d.keys(): 딕셔너리 안의 모든 키의 시퀀스를 반환

# eng_dic.py 영한 사전
"""
dict = {}

dict["one"] = "하나"
dict["two"] = "둘"
dict["three"] = "셋"

word = input("단어를 입력하시오: ")
print(dict[word])
"""

# address.py 연락처
"""
flag = True
address = {}

while flag == True:
    print("1. 연락처 추가")
    print("2. 연락처 삭제")
    print("3. 연락처 검색")
    print("4. 연락처 출력")
    print("5. 종료")
    menu = int(input("메뉴 항목을 선택하시오: "))
    print("")

    if menu == 1:
        key = input("이름: ")
        phone_number = input("전화번호: ")
        address[key] = phone_number

    elif menu == 2:
        delete = input("삭제할 이름을 입력하시오: ")
        address.pop(delete)

    elif menu == 3:
        search = input("검색할 연락처의 이름: ")
        if search in address:
            print("존재하는 연락처입니다")

    elif menu == 4:
        for i in address:
            print(f"{i}의 전화번호: {address[i]}")

    elif menu == 5:
        print("종료합니다")
        break

    print("")
"""

# score.py 학생 성적 처리
"""
score_dic = {
    'Kim' : [99, 83, 95],
    'Lee' : [668, 45, 78],
    'Choi' : [25, 56, 69]
}

for name, score in score_dic.items():
    print(f"{name} 의 평균성적= {sum(score) / len(score)}")
"""

# counter.py 단어 빈도 계산
"""
text_data = "Create the highest, grandest vision possible for your life, because you become what you believe"

word_count = {}

for i in text_data.split(): # 문자열에서 단어들을 분리
    if i in word_count:
        word_count[i] += 1
    else:
        word_count[i] = 1

for word, count in sorted(word_count.items()):
    print(word, "의 등장횟수=", count)
"""

# 7-6 문자열

# 문자열 내장 함수
# chr(): 정수를 문자열로 변환
# ord(): 문자를 정수로 변환
# str(): 객체의 문자열 표현을 반환

# 컴퓨터는 모든 정보를 숫자로 저장
# 각 문자에는 숫자로 된 코드(번호)가 존재 -> 아스키(ASCII)
# ord(c): 문자 c의 코드갑 반환
# ord("a") -> 97

# 문자가 알파벳이 아니면 유니코드 값 반환

# chr(): 숫자 n을 전달하면 n에 해당하는 문자 반환
# chr(97) -> "a"

# str(obj): 객체의 문자열 표현을 반환
# str(1+2j) -> "(1+2j)"

# 인덱싱
# 문자열도 시퀀스라는 자료 구조
# 시퀀스: 항목들이 순서를 가지고 모인 자료구조
# 문자열에서 개별 문자들을 추출
# 문자열 안에 저장된 문자들은 0부터 시작하는 번호(인덱스)

# 슬라이싱
# 슬라이싱: 문자열의 일부를 잘라서 서브 문자열을 만드는 연산

# 여러개의 문자열을 동시에 선택
# s = "Monty Python"
# s[6:10] -> "Pyth"

# 끝의 한 문자만을 삭제
# t = s[:-1]
# t -> "Monty Pytho"

# 끝에서 2 문자를 선택
# t = s[-2:]
# t -> "on"

# s[:i] + s[i:]: 항상 s와 같아짐

# 시작 인덱스와 종료 인덱스가 모두 생략: 문자열 전체가 선택
# s[:] -> "Monty Python"

# reg = "980326"
# print(reg[0:2] + "년") -> 98년

# 파이썬 문자열은 변경 불가능한 객체, 문자열의 일부 글자를 바꾸려고 하면 오류 발생

# 문자열 안의 문자를 변경하는 것이 필요하면 문자열의 사본을 생성
# word = "abcdef"
# word = "A" + word[[1:] -> "Abcdef"

# 문자열 비교하기
# 문자열과 문자열을 비교, 관계 연산자를 이용하여서 문자열과 문자열을 비교 가능
# "apple" < "banana" -> True

# ==, !=, <, >
# 문자열들의 순서를 정할 때 사용, 문자열들의 정렬에도 사용

# 문자열 출력하기
# f-문자열: 변수를 손쉽게 문자열 안에 넣어서 출력 가능
# 변수 대체: f-string 리터럴 내에서 변수 이름을 직접 지정 가능, 파이썬은 변수 이름을 해당 값으로 바꿈

# palin.py 회문 여부 검사
"""
word1 = input("문자열을 입력하시오: ")

word2 = word1[::-1] # 간격이 음수면 시작위치가 끝에서부터로 바뀜 

if word1 == word2:
    print("회문입니다.")
else:
    print("회문이 아닙니다.")
"""

# 7-7 문자열 메소드
# 파이썬 프로그램에서 사용되는 모든 데이터는 객체
# 객체는 내부에 많은 함수들을 가지고 있음
# 메소드(method)는 객체 안에 있는 함수
# 객체에서 메소드를 호출 -> obj.sub( <인수> ): obj 객체의 메소드 sub()를 호출
# <인수>는 메소드에 전달되는 인수를 지정, 인수는 없을 수도 있음

# 대소문자 변환하기
# s.capitalize(): 첫 문자만 대문자로 변환
# s = "i am a student."
# s.capitalize() -> "I am a student."

# s.lower(): 모든 알파벳 문자가 소문자로 변환된 사본을 반환
# s.upper(): 모든 알파벳 문자가 대문자로 변환된 사본을 반환
# s = "Breakfast At Tiffany"
# s.lower() -> "breakfast at tiffany"
# s.upper() -> "BREAKFAST AT TIFFANY"

# 찾기 및 바꾸기
# startswith(s): 문자열 s로 시작되는 문자열이면 True가 반환
# endswith(s): 문자열 s로 종료되는 문자열이면 True가 반환
# s = input("소스 파일 이름: ")
# if s.endswith(s):
#   print("올바른 이름") -> aaa.py, 올바른 이름

# replace(): 문자열에서 부분 문자열을 다른 부분 문자열로 반환
# s = ""www.naver.com"
# s.replace("com", "co.kr") -> "www.naver.co.kr"

# find(): 대상 문자열 안에서 부분 문자열을 찾아서 인덱스를 반환, 찾지 못했을 경우 -1 반환
# s = "www.naver.co.kr"
# s.find(".kr") -> 12

# s.rfind(<sub>[, <start>[, <end>]]): 끝에서 시작하여 지정된 부분 문자열을 대상 문자열 안에서 검색
# s = "Let it be, let it be, let it be"
# s.rfind("let") -> 22

# count(): 문자열 중에서 부분 문자열이 등장하는 횟수를 반환
# s = "www.naver.co.kr"
# s.count(".") -> 3

# 이들 메소드는 선택적으로 시작 위치 및 종료 위치 인수를 지원
# 위치가 지정되면 모든 연산이 시작 위치에서 시작하여 종료 위치까지의 부분 문자열로 제한
# s = "www.naver.co.kr"
# s.count(".", 0, 5) -> 1, "."을 찾을 때 인덱스0~4까지의 슬라이스만들 대상으로 함

# 문자 분류
# s.isalpha(): 문자열 s안의 모든 문자가 알파벳이면 True 반환, 그렇지 않으면 False를 반환
# s.digit(): 문자열 s가 숫자로만 구성되어 있으면 True를 반환
# "ABCabc".isalpha() -> True
# "123".isdigit() -> True

# s.islower(): s안의 모든 알파벳 문자가 소문자이면 True를 반환
# s.isupper(): s안의 모든 문자가 대문자이면 True를 반환
# "abc".islower() -> True

# 공백 문자 제거
# strip(): 문자열에서 원치 않는 공백을 제거, 문자열의 첫 부분과 끝부분에서 공백 문자를 제거, 문자 사이의 공백은 제거x
# s = " Hello, World! "
# s.strip() -> "Hello, World!"

# 문자열의 앞뒤의 특정한 문자를 삭제하려면 문자를 strip()의 인수로 전달
# s = "########this is example#######"
# s.strip("#") -> "this is example"

# rstrip()과 lstrip()은 문자열의 오른쪽 끝과 왼쪽 끝에서 원치 않는 문자를 삭제
# s = "########this is example########"
# s.lstrip("#") -> "this is example########"
# s.rstrip("#") -> "########this is example"

# strip() 메소드는 텍스트 데이터를 분석할 때 불필요한 공백 문자를 제거하는데 사용

# 문자열을 분해하기
# split(): 문자열 안의 단어들이 쉼표나 빈칸 등의 구분자로 분리되어 있는 경우 구분자를 이용하여 문자열을 단어들로 분리하는 함수
# 주어진 분리자를 이용하여 문자열을 토큰들의 리스트로 반환
# s = "Welcome to Python"
# s.split() -> ["Welcome", "to", "Python"]

# split()에 인수를 주지 않고 호출하면 공맥문자"" 를 분리자로 가정
# 분리자 문자를 전달 가능
# s = "Hello, World!"
# s.split(",") -> ["Hello", " World!"], 분리자는 ',' 문자

# " W" 앞의 공백문자까지 제거하려면 " "도 분리자로 포함
# s = "Hello, World!"
# s.split(", ") -> ["Hello", "World!"]

# list(): 문자열을 문자들로 분해, 주어진 것을 리스트로 만드는 함수
# list("Hello, World!")
# ["H", "e", "l", "l", "o", ",", " ", "W", "o", "r", "l", "d", "!"]

# 문자열 결합하기
# join(): 단어들을 모아서 하나의 문자열로 만듬, 접착제 역할을 하는 문자 지정 가능
# ",".join(["apple", "grape", "banana"]) -> "apple,grape,banana"

# join은 접착제 문자를 단어 사이에만 넣고 단어의 앞이나 뒤에는 넣지 않음

# 문자들을 모아서 다시 문자열로 만들때도 사용
# s = "hello world"
# clist = list(s)
# ".".join(clist) -> "hello world"

# split()과 join()을 함께 사용하면 문자열 중에서 필요 없는 공백 제거 가능
# " ".join("Actions \n\t speak louder  than words".split()) -> "Actions speak louder than words", split()은 연속된 공백을 하나로 취급

# acronym.py 머리 글자어
"""
sentence = input("문자열을 입력하시오: ")

acronym = ""

for i in sentence.split():
    acronym = acronym + i[0]

print(acronym)
"""

# email.py 이메일 주소에서 아이디와 도메인을 구분
"""
email = input("이메일 주소를 입력하시오: ")

print(email)

split_email = email.split("@") # (id, domain) = email.split("@")

print(f"아이디:{split_email[0]}")
print(f"도메인:{split_email[1]}")
"""

# ch_count.py 문자열 내의 알파벳 문자의 개수를 계산
"""
sentence = input("문자열을 입력하시오: ")

dict = {"alphas": 0, "digits": 0, "spaces": 0}

for i in sentence:
    if i.isalpha():
        dict["alphas"] += 1
    elif i.isdigit():
        dict["digits"] += 1
    elif i.isspace():
        dict["spaces"] += 1 # .isspace(): 공백인지 검사

print(dict)
"""

# twitter1.py 트위터 메시지에서 단어의 개수를 계산
"""
t = "Python is very easy and powerful!"

emotion = t.split(" ")

print(len(emotion))
"""

# otp.py otp 구현
"""
import random

s = "01234566789"

otp = "".join(random.sample(s, 4)) # random.sample(string, number)

print(otp)
"""

# ex1
"""
list1 = [80, 20, 20, 30, 60, 30]

print("주어진 리스트:", list1)

list2 = sorted(set(list1))

print("정리된 리스트:", list2)
"""

# ex2
"""
dict = {x : x * x for x in range(1, 11)}

print(dict)
"""

# ex3
"""
d = {"Apple": 1, "Banana": 2, "Grape": 3}

for key, value in d.items():
    print(key, "->", value)
"""

# ex4
"""
d = {1: 10, 2: 20, 3: 30, 4: 40, 5: 50, 6: 60}

key = int(input("키를 입력하시오: "))

if key in d:
    print(f"키 {key}은 딕셔너리에 있습니다.")
"""

# ex5
"""
myDict = {"옷": 100, "컴퓨터": 2000, "모니터": 320}

sum = 0

for key in myDict:
    sum = sum + myDict[key] # sum(myDict.values())도 가능 

print("총합계=", sum)
"""

# ex6
"""
colors = ["red", "green", "blue"]
values = ["#FF0000", "#008000", "#0000FF"]

dictionary = dict(zip(colors, values)) # dict(): 딕셔너리로 변환 

print("colors =", colors)
print("values =", values)
print(dictionary)
"""

# ex7
"""
calender = {}

flag = True

while flag == True:
    date = input("날짜를 입력하시오: ")
    if date == "end":
        print(calender)
        break

    work = input("일정을 입력하시오: ")

    if date in calender:
        calender[date].append(work)
    else:
        calender[date] = []
        calender[date].append(work)

    print("")
"""

# ex8
"""
dict = {1 : "January", 2 : "February", 3 : "March", 4 : "April", 5 : "May", 6 : " June", 7 : "July", 8 : "August", 9 : "September", 10 : "October", 11 : "November", 12 : "December"}

month = int(input("달의 번호: "))

if month in dict:
    print(f"달의 번호: {dict[month]}")
"""

# ex9
"""
first_sentence = input("첫 번째 문자열: ")
second_sentence = input("두 번째 문자열: ")

result = set(first_sentence) & set(second_sentence)

print("모두 포함된 글자:", end = " ")

for i in result:
    if i.isalpha():
        print(i, end = " ")
"""

# ex10
"""
set1 = {10, 20, 30, 40, 50, 60}
set2 = {30, 40, 50, 60, 70, 80}

intersection = set1 & set2

result1 = set1 - intersection
result2 = set2 - intersection

result = result1 | result2

print(f"첫 번째 세트 {set1}")
print(f"두 번째 세트 {set2}\n")
print(f"어느 한쪽에만 있는 요소들 {result}")
"""

# ex11
"""
dict = {"파이썬" : "최근에 가장 떠오르는 프로그래밍 언어",
        "변수" : "데이터를 저장하는 메모리 공간",
        "함수" : "작업을 수행하는 문장들의 집합에 이름을 붙인것",
        "리스트" : "서로 관련이 없는 항목들의 모임"
        }

for key in dict.keys():
    print("다음은 어떤 단어에 대한 설명일까요?")
    print(f'"{dict[key]}"')
    print("(1)파이썬 (2)변수 (3)함수 (4)리스트")
    print("")
    answer = input("")

    if answer == key:
        print("정답입니다.!")
    else:
        print("틀렸습니다.!")
    print("")
"""

# ex12
"""
sentence = input("문자열을 입력하시오: ")
warning = input("금칙어를 입력하시오: ")

a = sentence
b = warning.split()

for i in range(len(b)): 
    if b[i] in a:
        a = a.replace(b[i], "*" * len(b[i])) # 원본이 아니라 누적시켜 변경해야 함

print(a)
"""

# ex13
"""
sentence = input("")

count_alpha = sum(1 for x in sentence if x.isalpha())
count_digit = sum(1 for x in sentence if x.isdigit())


print(f'"{sentence}" -> {{ "LETTERS":{count_alpha}, "DIGITS":{count_digit}" }}') # f-출력 안에 {}사용할려면 {{ }} 중괄호를 두번 겹쳐 씀
"""

# ex14
"""
for i in range(2):
    date = input("")

    a = date.split("/")

    b = [a[2], a[0], a[1]]

    c = "".join(b)

    print(f'"{date}" -> "{c}"')
"""

# ex15
"""
studentList = {
    "Park": "Korea",
    "Sam": "USA",
    "Sakura": "Japan"
}

for key in studentList:
    print(f"\"Hi! I'm {key}, and I'm from {studentList[key]}.\"") # \": 역슬래쉬 다음에는 특별한 취급 
"""

# ex16
"""
import random

s = "abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"

otp = "".join(random.sample(s, 8))

print(f"생성된 암호 = {otp}")
"""

