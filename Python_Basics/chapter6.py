# Chapter6 파이썬 자료구조 I

# 6-2 리스트
# 리스트: 여러 개의 값을 저장하고 처리, 항목(item)들을 저장하는 컨테이너로서 그 안에 항목들이 순서를 가지고 저장
# 항목의 개수 증가: 자동으로 늘어남, 항목의 개수 감소: 자동으로 줄어듬
# 어떤 타입이든 저장 가능
# 여러 개의 값 한 번에 저장 가능

# 리스트 만들기
# 리스트 안에 저장된 각가의 데이터를 항목(item) or 요소(element)
# 리스트_이름 = [요소1, 요소2, ...]
# temps = [28, 31, 33, 35, 27, 26, 25]
# e = temps[3]

# 리스트에는 어떤 것이든 저장 가능

# 리스트의 항목 접근
# 인덱스: 리스트에서의 항목의 위치(번호)
# 리스트이 인덱스는 0부터 시작
# 리스트의 요소값을 변경 가능

# 음수 인덱스
# 음수를 인덱슬호 사용
# 리스트의 가장 마지막 요소의 인덱스는 -1
# len(temps): 리스트의 길이를 반환

# 인덱스 오류
# 인덱스가 적정한 범위에 있응지를 항상 확인

# 리스트 방문
# 인덱스 값을 사용하여 방문
# temps = [28, 31, 33, 35, 27, 26, 25]
# for i in range(len(temps)):
#   print(temps[i], end=', ')

# 인덱스의 값이 필요없으면 for-each 루프를 사용
# temps = [28, 31, 33, 35, 27, 26, 25]
# for element in temps:
#   print(element, end= ', ')

# 동시에 2개 이상의 리스트를 반복하기 위해 zip() 함수를 사용, zip() 함수는 2개의 리스트를 묶어서 항목 2개를 묶어서 제공
# questions = ['name', 'quest', 'color']
# answers = ['Kim', '파이썬', 'blue']
# for q, a in zip(quesrions, answers):
#   print(f"What is your {q}? It is {a}")

# 6-3 리스트 연산들
# 메소드(object): 객체가 가지고 있는 함수

# append(): 새로운 요소를 리스트의 맨 끝에 추가

# insert(): 지정된 위치에 요소를 추가
# heroes.insert(1, "스타이더맨") -> 1번 인덱스에 추가
# 1번 인덱스의 모든 요소가 한 위치 아래로 이동
# 새 요소를 삽입할 인덱스는 0~현재 리스트에 있는 요소 수 사이

# 리스트 탐색하기
# 특정 항목이 리스트의 어디에 있는지 알려면 index() 사용
# heroes = ["아이언맨". "토르", "헐크", "스칼렛 위치", "헐크"]
# n = heroes.index("헐크") -> n = 2

# 탐색하고자 하는 항목이 리스트에 없으면 오류 발생
# 탐색하지 전에 in 연산자를 이용
# if "헐크"in heroes:
#   print(heroes.index("헐크"))

# 만약 값이 리스트에서 한 번 이상 등장하면 탐색을 시작하는 위치를 index() 함수로 넘길 수 있음
# heroes = ["아이언맨". "토르", "헐크", "스칼렛 위치", "헐크"]
# n = heroes.index("헐크", 3) -> n = 4(인덱스 3부터 찾음)

# 요소 삭제
# 항목이 저장된 위치를 알고 있음: pop(i)
# 항목의 값만 알고 있으면: remove(value)

# pop(i): 리스트에서 i번째 항목을 삭제하여 반환
# heroes = ["아이언맨", "토르", "헐크"]
# h = heroes.pop(1)

# remove(e)는 리스트에서 지정된 값을 삭제, 삭제된 값은 반환하지 않음
# heroes = ["아이언맨". "토르", "헐크"]
# heroes.remove("토르")

# remove() : 삭제하고자 하는 항목의 위치를 알 필요가 없음, 항목이 있다는 사실만 알면 됨
# 지정된 항목이 리스트에 없으면 오류가 발생

# 항목이 리스트 안에 있는지 검사: in 연산자
# if "토르" in heroes:
#   heroes.remove("토르")

# "value" in myList: "value"가 mylist에 있으면 True
# "value" not in myList: "value"가 myList에 없으면 True
# myList.sort(): myList를 정렬
# myList.index("value")

# 최소값: min()
# 최대값: max()
# values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# min(values)
# max(values)

# 정렬 #1
# 리스트의 요소들을 크기 순으로 정렬
# sort(): 제자리(in-place)에서 리스트를 정렬, 오름차순
# 원본 리스트가 변경
# a = [3, 2, 1, 5, 4]
# a.sort() -> [1, 2, 3, 4, 5]

# 문자열의 경우 알파벳 순서대로 정렬

# 역순으로 정렬 하려면
# a.sort(reverse=True) -> [5, 4, 3, 2, 1]

# 정렬 #2
# sorted(): 크기순으로 정렬된 새로운 리스트를 반환, 원래의 리스트는 수정되지 않음
# sorted(numbers)

# 리스트가 가지고 있는 메소드
# extend(): 리스트이 모든 요소를 다른 리스트에 추가
# clear(): 리스트로부터 모든 항목 삭제
# count(): 인수로 전달된 항목의 개수를 반환
# copy(): 리스트의 복사본을 반환

# 리스트에서 사용할 수 있는 내장 함수
# reduce(): 특정 함수를 리스트 안의 모든 요소에 저장하여 결과값을 저장하고 최종 합계값만을 반환
# ord(): 유니코드 문자의 코드값을 반환
# cmp(): 첫 번째 리스트가 두 번째 보다 크면 1을 반환
# all(): 리스트의 모든 요소가 참이면 참을 반환
# any(): 리스트 안의 한 요소라도 참이면 참을 반환
# enumerate(): 리스트의 요소들을 하나씩 반환하는 객체를 생성
# accumulate(): 특정한 함수를 리스트의 요소에 적용한 결과를 저장하는 리스트를 반환
# filter(): 리스트의 각 요소가 참인지 아닌지를 검사
# map(): 특정한 함수를 리스트의 각 요소에 적용하고 결과를 담은 리스트를 반환

# 리스트에서 랜검으로 선택
# choice() -> random.choice(list)

# score_proc.py 성적 처리
"""
STUDENTS = 5
list = []
count = 0

for i in range(STUDENTS):
    score = int(input("성적을 입력하시오: "))
    list.append(score)

for j in range(STUDENTS):
    if list[j] >= 80:
        count += 1


average = sum(list) / len(list)
max_num = max(list)
min_num = min(list)

print(f"성적 평균= {average}")
print(f"최대점수= {max_num}")
print(f"최소점수= {min_num}")
print(f"80점 이상= {count}")
"""

# second1.py 2번째로 큰 수 찾기
"""
list1 = [1, 2, 3, 4, 15, 99]

list1.sort()

print("두 번째로 큰수=", list1[-2])
"""

# second2.py 2번째로 큰 수 찾기
"""
list1 = [1, 2, 3, 4, 15, 99]

list1.remove(max(list1))

print("두 번째로 큰 수=", max(list1))
"""

# gym_score1.py 최대값과 최소값 제거하기
"""
scores = [10.0, 9.0, 8.3, 7.1, 3.0, 9.0]
print("제거전", scores)
scores.remove(max(scores))
scores.remove(min(scores))
print("제거후", scores)
"""

# gym.score2.py 최대값과 최속값 제거
"""
scores = [10.0, 9.0, 8.3, 7.1, 3.0, 9.0]
print("제거전", scores)
scores.sort()

new_score = scores[1:-1]
print("제거후", new_score)
"""

# stack.py
# pop을 인자 없이 호출하면 리스트의 맨 끝 원소를 꺼내서 반환하고 그 리스트에서 제거
"""
list = []

for i in range(3):
    fruit = input("과일을 입력하시오: ")
    list.append(fruit)

for j in range(3):
    print(list.pop())
"""

# friends.py 친구 관리
"""
menu = 0
friends = []

while menu != 9:
    print("--------------------")
    print("1. 친구 리스트 출력")
    print("2. 친구추가")
    print("3. 친구삭제")
    print("4. 이름변경")
    print("9. 종료")
    menu = int(input("메뉴를 입력하세요: "))

    if menu == 1:
        print(friends)

    elif menu == 2:
        insert_name = input("이름을 입력하시오: ")
        friends.append(insert_name)

    elif menu == 3:
        delete_name = input("이름을 입력하시오: ")
        if delete_name in friends:
            friends.remove(delete_name)
        else:
            print("존재하지 않는 이름입니다")

    elif menu == 4:
        original_name = input("이름을 입력하시오: ")
        change_name = input("이름을 입력하시오: ")

        if original_name in friends:
            search = friends.index(original_name)

            friends[search] = change_name
        else:
            print("존재하지 않는 이름입니다")

    elif menu == 9:
        break
"""

# 6-4 리스트 합병, 복제, 비교

# 리스트의 합병과 복제
# 2개의 리스트를 합병하여 새로운 리스트를 만들 수 있음, 합병은 + 연산자 사용
# list1 = [1, 2]
# list2 = [3, 4]
# new_list = list1 + list2 -> [1, 2, 3, 4]

# 만약 동일한 리스트를 여러 번 복제하영서 합병하려면 복제 연산자인 * 사용
# numbers = [1, 2] * 2 -> [1, 2, 1, 2]
# * 연산자의 뒤쪽 or 앞쪽에 리스트이 복사본 개수를 지정, 리스트 복사본들은 모두 합쳐짐

# 고정되 값으로 리스트를 초기화
# numbers = [0] * 5 -> [0, 0, 0, 0, 0]

# 리스트 비교
# 비교 연산자 (==, !=, >, <)를 사용하여 2개의 리스트를 비교 가능
# 2개의 리스트를 비교하려면 2개의 리스트가 동일한 자료형의 요소들을 가지고 있어야 한다
# 리스트의 첫 번째 요소들을 비교하고 첫 번째 요소의 비교에서 False가 나오면 더 이상의 비교는 없고 False 출력
# 첫 번째 요소가 같으면 두 번째 요소를 꺼내서 비교
# 리스트 안의 모든 요소가 비교될 때까지 동일한 작업을 반복
# 리스트 안의 모든 요소를 비교하여 모두 True가 나오면 전체 결과가 True

# 리스트 복사
# 리스트는 변수가 아닌 다른 곳에 저장되고 리스트의 참조값만 변수에 저장
# 참조값: 메모리에서 리스트 객체의 위치

# temps = [28, 31, 33, 35, 27]
# values = temps -> 리스트는 복사되지 않고 동일한 리스트를 가리킴

# values를 통해 리스트 요소의 값을 변경한다면 temps 리스트도 변경
# temps = [1, 2, 3]
# values = temps
# values[2] = 1 -> [1, 2, 1]

# 리스트를 올바르게 복사
# list(): 다른 리스트나 데이터들을 받아서 새로운 리스트를 생성하는 생성자 함수
# temps = [1, 2, 3]
# values = list(temps)

# ramge() 함수의 반환값을 모아서 리스트로 만들 때도 사용
# numbers = list(range(5)) -> [0, 1, 2, 3, 4]

# list_add.py 리스트 추가 방법 비교
"""
import time
SIZE = 50000

start_time = time.time()
mylist = []
for i in range(SIZE):
    mylist = mylist + [i * i]
print("수행시간=", time.time() - start_time)

start_time = time.time()
mylist = []
for i in range(SIZE):
    mylist.append(i * i)
print("수행시간=", time.time() - start_time)
"""

# time(): 수행시간을 측정

# 6-5 슬라이싱
# 슬라이싱: 리스트에서 한 번에 여러 개의 항목을 추출
# numbers[2:7]: 2부터 시작하여 7이 나오기 전에 중지 -> 2, 3, 4, 5, 6
# 슬라이싱에서 추출되는 항목의 개수: 두 번째 인덱스에서 첫 번째 인덱스를 빼서 계산

# 리스트[start:stop]

# 슬라이싱 하면 원래의 리스트는 손상되지 않음, 리스트가 생성되어 반환
# 슬라이스: 원래의 리스트의 부분 복사본
# 첫 번째 인덱스를 생략: 리스트의 처음부터
# numbers = [10, 20, 30, 40, 50, 60, 70, 80, 90]\
# numbers[:3] -> [10, 20, 30]

# 두 번째 리스트가 삭제되면 리스트의 끝까지
# numbers[3:] -> [40, 50, 60, 70, 80, 90]

# 클론(:)만 있으면 리스트의 처음부터 끝까지
# numbers[:] -> [10, 20, 30, 40, 50, 60, 70, 80, 90]

# 리스트 복사본 생성
# new_numbers = numbers[:]

# 고급 슬라이싱
# 슬라이싱을 할때 단계(step) 지정 가능

# 리스트[start:stop:step]
# nubmers[2, 7. 2] -> [30, 50, 70]

# 역순 나열 가능
# nubmers = [10, 20, 30]
# numbers[::-1] -> [30, 20, 10]

# 리스트 슬라이스에 새로운 리스트를 할당하여 리스트의 일부 수정 가능, 리스트의 나머지 부분은 변경되지 않음
# lst = [1, 2, 3]
# lst[0:2] = ['white', 'blue'] -> ['white', 'blue', 3]\

# 슬라이싱을 이용하여 리스트의 모든 요소를 삭제
# lst = [1, 2, 3]
# lst[:] = [] -> []

# 리스트의 오쇼들을 슬라이싱을 통해 삭제 가능
# del문장: 삭제하고자 하는 요소의 위피를 알고 있으면
# number = list(range(0. 5))
# del number[-1] -> [0, 1, 2, 3]

# 전체 삭제
# del number[:] -> []

# 문자열과 리스트
# 문자열: 문자들이 모인 리스트

# 리스트 슬라이싱
# 1
"""
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

reverse_list = numbers[::-2]
print(reverse_list)
"""

# 2
"""
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

numbers[1:] = []
print(numbers)
"""

# 6-6 리스트와 함수
# 함수로 인수를 전달하는 방식
# 값으로 호출: 함수로 변수를 전달할 때, 변수의 복사본이 함수로 전달
# 참조로 호출: 함수로 변수를 전달할 때, 변수의 참조가 전달, 함수에서 매개변수를 통하여 우너본 변수 변경 가능

# 객체의 참조값이 함수의 매개변수로 전달되지만 함수 안에서 객체의 값을 변경하면 새로운 객체가 생성

# id(): 객체의 참조값 출력

# 변경가능한 객체인 리스트를 함수에 전달 - 리스트도 참조값이 달리짐, 리스트는 함수 안에서 변경 가능, 리스트의 요소들은 변경될 수 있음

# salary.py 리스트 변경 함수
"""
money = [200, 250, 300, 280, 500]

def modify(list, num):
    for i in range(len(list)):
        list[i] = list[i] * num

print("인상전", money)

modify(money, 1.3)

print("인상후", money)
"""

# 6-7 리스트 함축
# 리스트의 요소를 생성하는 문장을 리스트 안에 넣음
# [수식 for (변수 in 리스트) if (조건) ]
# squares = [x*x for in range(10)] -> range(10)에 속하ㅡㄴ 모든 정수에 대하여 x^2을 계산하여서 리스트를 생성

# 간결하게 리스트 생성 가능

# if를 사용하여 조건 추가 가능
# squares = [x*x for x in range(10) if x % 2 == 0]

# 다양한 리스트 함축
# 숫자에 대해서만 적용되는 것이 아닌 어떤 자료형에 대해서도 리스트 함축 적용 가능
# 단어의 첫 글자만 추출
# words = ["All", "good", "things", "must", "come", "to", "an", "end,"]
# letters = [w[0] for w in words]

# 리스트 함축에는 여러 개의 인수 추가 가능
# numbers = [x+y for x in ['a', 'b', 'c'] for y in ['x', 'y', 'z']] -> ['ax', 'ay', 'az', 'bx', ...]
# 하나의 리스트와 다른 리스트에서 원소를 하나씩 꺼내어서 상호곱

# list_comp.py 리스트 함축 사용
"""
list = [x for x in range(100)if x % 2 == 0 and x % 3 == 0]
print(list)
"""

# list_comp2.py 누적값 리스트 만들기
"""
original_list = [10, 20, 30, 40, 50]
print("원래 리스트:", original_list)

new_list = [sum(original_list[0:x+1]) for x in range(0, len(original_list))]
print("새로운 리스트:", new_list)
"""

# pytha.py 정삼각형 찾기
"""
list = [(x, y, z) for x in range(1, 30) for y in range(x, 30) for z in range(y, 30) if x**2 + y**2 == z**2]
print(list)
"""

# 6-8 2차원 리스트
# 리스트를 2차원으로 만들 수 있음
# list = [
#         [1, 2, 3],
#         [4, 5, 6],
#         [7, 8, 9]
#                  ]
# -> [ [1, 2, 3], [4, 5, 6], [7, 8, 9]]

# 동적으로 2차원 리스트를 생성
# rows = 3
# cols = 5
# s = []
# for row in range(rows):
#   s = s + [[0] * cols]
# -> [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

# 리스트 함축 사용
# s = [([0] * cols) for row in range(rows)]

# for row in range(rows):
#   s += [0] * cols
# -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

# 요소 접근
# 2차원 리스트에서 요소에 접근하려면 2개의 인덱스 번호를 지정
# 첫 번째 번호: 행
# 두 번째 번호: 열

# s = [ [1, 2, 3],
#       [4, 5, 6],
#       [7, 8, 9]
#                 ]

# rows = len(s)
# cols = len(s[0])

# for row in range(rows):
#   for col in range(cols):
#       print([row][cols], end = ",")
#   print()

# len(s): 행의 개수
# len(s[0]): 열의 개수

# 리스트 안에 다른 리스트를 내장 가능
# a = ['a', 'b', 'c']
# n = [1, 2, 3]
# x = [a, n]
# -> x = [['a', 'b', 'c'], [1, 2, 3]]

# 열 합계와 행 합계를 계산
# 행 또는 열 합계를 계산
# s = [ [1, 2, 3],
#       [4, 5, 6].
#       [7, 8, 9]
#                ]
# rows = len(s)
# cols = len(s[0])
# i = 1
# total = 0
# for j in range(cols):
#   total = total + s[i][j]

# 2차원 리스트를 함수로 넘기기
# 함수 안에서는 2차원 리스트의 차원을 추출 가능
# 함수 안에서 2차원 리스트를 변경하면 원본 리스트가 변형

# checker.py 체스 보드 출력
"""
def printList(list):
    for row in range(len(list)):
        for col in range(len(list[0])):
            print(list[row][col], end = " ")
        print()

def init(list):
    for row in range(len(list)):
        for col in range(len(list[0])):
            if (row + col) % 2 == 0:
                list[row][col] = 1

table = []

for row in range(10):
    table = table + [[0] * 10]

init(table)
printList(table)
"""

# 2차원 리스트와 리스트 함축
# matrix = [[i for i in range(5)] for _ in range(6)]
# -> [[0, 1, 2, 3, 4], 5번 반복]

# [... for _ in range(6)]: 6개의 행을 만듦
# [i for i in range(5)]: 각 행을 순차적인 값으로 채움

# 리스트를 1차원 리스트로 평탄화
# matrix = [[0, 0, 0], [1, 1, 1], [2, 2, 2]]
# result = [num for row in matrix for num in row]
# -> [0, 0, 0, 1, 1, 1, 2, 2, 2]
# matrix의 각 행 row에 있는 요소들이 추출되어서 하나의 리스트로 병합
# 한 번에 한 행을 처리, 해당 행의 모든 요소를 추출해서 새로운 리스트에 추가

# transpose1.py 전치 행렬 추가
"""
list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

print("원래 행렬=", list)

list_t =[]

for i in range(len(list[0])):
    list_T = []
    for row in list:
        list_T.append(row[i])
    list_t.append(list_T)

print("전치 행렬=", list_t)
"""

# transpose2.py 전치 행렬 찾기
"""
list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print("원래 행렬=", list)

list_t = [[row[i] for row in list]for i in range(len(list[0]))]
print("전치 행렬=", list_t)
"""

# tic_tac_toe.py 틱택토
"""
table = [[' ' for x in range(3)]for y in range(3)]

while True:
    for r in range(3):
        print('  ' + table[r][0] + '|  ' + table[r][1] + '|  ' + table[r][2])
        if (r != 2):
            print("---|---|---")

    x = int(input("다음 수의 x좌표를 입력하시오: "))
    y = int(input("다음 수의 y좌표를 입력하시오: "))

    if table[x][y] != ' ':
        print("잘못된 위치")
        continue
    else:
        table[x][y] = 'X'

    done = False
    for i in range(3):
        for j in range(3):
            if table[i][j] == ' ' and not done:
                table[i][j] = '0'
                done = True
                break;
"""

# ex1
"""
list = []

count = int(input("입력할 값의 개수: "))

for i in range(count):
    num = int(input())
    list.append(num)

print("값의 합계=", sum(list))
"""

# ex2
"""
import random

values = []

for i in range(10):
    number = random.randint(1, 100)
    values.append(number)

print(values)
"""

# ex3
"""
list = [20, 1, 12, 9, 18]

for i in range(len(list)):
    if list[i] <10:
        print(f"{list[i]}  {'*' * list[i]}")
    else:
        print(list[i], '*' * list[i])
"""

# ex4
"""
list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
list2 = [i if i < 3 or i > 8 else -i for i in list1]

print("실행전", list1)
print("실행후", list2)
"""

# ex5
"""
list = ['aba', 'xyz', 'abc', '121']
count = 0

for word in list:
    if word[0] == word[-1]:
        count += 1

print("문자열의 개수=", count)
"""

# ex6
"""
list1 = [1, 2, 3, 4, 5, 6]
list2 = [6, 7, 8, 9, 10]
count = 0

print("list1=", list1)
print("list2=", list2)

for i in list1:
    for j in list2:
        if j == i:
            count += 1

if count >= 1:
    print("True")
else:
    print("False")
"""

# ex7
"""
import random

list1 = ['a0', 'a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7', 'a8', 'a9']

result = random.choice(list1)

print("list1=", list1)
print(result)
"""

# ex8
"""
a = [1, 2, 3, 4, 5]
b = [1, 3, 3, 4, 5, 6, 7]

list = [ x for x in a if x in b]

print("a=", a)
print("b=", b)
print("")
print("결과=", list)
"""

# ex12
"""
list = [[['#' for i in range(4)] for _ in range(3)] for _ in range(2)]

print(list)
"""

# ex13\
"""
reserve = []

print("-------------------------------")
print("  1  2  3  4  5  6  7  8  9  10")
print("-------------------------------")

for row in range(10):
    reserve = reserve + [[0] * 10]

row_number = 0
col_number = 0
flag = True

while flag == True:

    for rows in range(len(reserve)):
        for cols in range(len(reserve[0])):
            print(f"  {reserve[rows][cols]}", end="")
        print("")

    row_number = int(input("원하시는 좌석의 행번으롤 입력하세요(종료는 -1): "))
    if row_number == -1:
        print("종료되었습니다")
        break
    col_number = int(input("원하시는 좌석의 열번로를 입력하세요(종료는 -1): "))
    if col_number == -1:
        print("종료되었습니다")
        break

    if reserve[row_number - 1][col_number - 1] == 0:
        reserve[row_number - 1][col_number - 1] = 1
        print("예약되었습니다")
    elif reserve[row_number - 1][col_number - 1] == 1:
        print("이미 예약되어 있는 좌석입니다")
"""

# ex14
"""
import random

table = [["." for x in range(10)] for y in range(10)]

for rows in range(len(table)):
    for cols in range(len(table[0])):
        prob = random.randint(1, 100) / 100
        if prob < 0.3:
            table[rows][cols] = "#"

for rows in range(len(table)):
    for cols in range(len(table[0])):
        print(table[rows][cols], end=" ")
    print()
"""

# ex15
"""
import random

coin_result =[]
length_list = []
length = 1

for i in range(10):
    coin = random.randint(0, 1)

    if coin == 0:
        coin_result.append(0)
    elif coin == 1:
        coin_result.append(1)

print(coin_result)

for i in range(9):
    if coin_result[i] == coin_result[i + 1]:
        length += 1
    elif coin_result[i] != coin_result[i + 1]:
        length_list.append(length)
        length = 1

length_list.append(length) # 마지막 까지 이어지는 경우가 최대 일때를 위해

max_length = max(length_list)
print("최대 연속 길이=", max_length)
"""

# ex16
"""
number_list = list(range(2, 101))

divisor = 2

while divisor * divisor <= 100:
    if divisor in number_list:
        for i in range(2, 100 // divisor + 1):
            if (divisor * i) in number_list:
                number_list.remove(divisor * i)

    divisor += 1

print(*number_list)
"""