# Chapter 9 GUI 프로그래밍

# 9-1
# GUI(Graphic User Interface): 사용자 인터페이스(윈도우, 메뉴, 버튼, 마우스)

# 9-2 tkinter?
# tkinter: GUI를 개발할 때 필요한 모듈
# GUI는 그래픽을 통하여 사용자와 상호작용할 수 있는 인터페이스
# tkinter를 사용하면 윈도우를 생성하고 버튼이나 레이블과 같은 위젯을 이용하여서 사용자와 상호작용하는 프로그램 작성 가능

# 9-3 tkinter 시작하기
# 먼저 윈도우(window)를 생성하고 필요한 위젯들을 추가
# 위젯(widget): GUI 기반 시스템에서 사용하는 시각적 요소 (버튼, 레이블, 슬라이더, 콤보 박스)

# Hello tkinter 프로그램
# 레이블: GUI 에서는 텍스트를 표시하는 위젯

# label1.py
"""
from tkinter import * # tkinter 모듈을 포함

window = Tk() # 루트 윈도우 생성
label = Label(window, text="Hello tkinter") # 레이블 위젯 생성
label.pack() # 레이블 위젯을 윈도우에 배치

window.mainloop() # 윈도우가 사용자 동작을 대기
"""

# from tkinter import *: tkinter 모듈을 포함, Tk 툴킷을 사용하는데 필요한 모든 클래스와 함수, 상수를 가지고 있음, * 기호는 tkinter 모듈에서 모든 것을 포함시키라는 의미

# window = Tk(): # 루트 윈도우를 먼저 생성해야 함, Tk 클래스는 제목을 가지고 있는 일반적인 윈도우, Tk()을 호출하면 Tk 클래스의 객체가 생성되면서 화면에 하나의 윈도우가 생성, 이 윈도우 안에 여러가지 위젯을 추가할 수 있음, 각 프로그램은 하나의 루트 윈도우만 가져야 함, 루트 윈도우는 다른 윈도우보다 먼저 생성되어야 함

# label = Label(window, text = "Hello tkinter"): 레이블 위젯을 생성, Label은 레이블 위젯을 나타내는 클래스, Label()의 첫 번째 매개변수는 항상 부모 컨테이너, 컨테이너: 위젯을 내부에 가질 수 있는 객체, 여기서는 루트 윈도우가 부모 컨테이너로 전달, 두 번째 매개변수는 레이블에 표시되는 텍스트, 윈도우에 레이블이 추가

# label.pack(): pack()은 압축 배치 관리자를 이용하여서 레이블을 컨테이너에 위치, 압축 배치 관리자는 위젯을 윈도우의 한 행에 하나씩 배치, 레이블을 생성해도 pack() 함수를 호출하지 않으면 윈도우에 레이블이 나타나지 않음

# window.mainloop(): 사용자로부터 오는 마우스나 키보드 이벤트를 처리

# 기본 위젯들
# Label: 텍스트를 표시하는데 사용되는 위젯
# Button: 버튼을 제공하는 위젯
# Entry: 한 줄의 텍스트를 입력받는 위젯
# Text: 여러 줄로 된 텍스트를 입력받는 위젯
# Frame: 컨테이너 위젯

# 버튼 위젯
# 버튼(Button) 위젯은 클릭 가능한 버튼을 표시

# button1.py
"""
from tkinter import *

window = Tk()

button = Button(window, text = "클릭하세요!", bg = "yellow", fg = "blue", width = 80, height = 2)

button.pack()
window.mainloop()
"""

# 버튼이나 레이블은 기본 전경 색상 및 기본 배경 색상으로 텍스트를 표시
# 일반적으로 검정색과 흰색이지만 fg나 bg 매개 변수를 사용하여 색상 변경 가능
# 색상 이름은 "red", "yellow"나 "#00FF00"과 같이 166진수 RGB값 가용

# weight와 height 매개 변수를 사용하여 버튼이나 레이블의 너비와 높이를 제어 가능
# 너비와 높이는 글자 단위로 측정

# 엔트리 위젯
# 엔트리(Entry) 위젯은 사용자가 키보드로 입력한 내용을 우리에세 전달 
# get()을 사용하면 사용자의 입력을 가져올 수 있음
# 사용자의 입력을 삭제하려면 delete()를 사용
# 중간에 텍스트를 삽입하여면 insert()를 사용

# entry.py
"""
from tkinter import *
window = Tk()

entry = Entry(window, fg = "black", bg = "yellow", width = 80)
entry.pack()
window.mainloop()
"""

# 9-4 배치 관리자
# 버튼이나 레이블 등의 위젯은 윈도우 내부에 배치(컨테이너 안에 배치)
# 위젯의 관리를 배치 관리자에세 맡김
# 배치 관리자는 컨테이너 안에 존재하는 위젯의 크기와 위치를 자동적으로 관리

# Pack: 압축 배치 관리자
# 위젯들을 사각형 블록으로 간주하여 컨테이너 안에 상하로 배치
# 압축 배치 관리자를 사용하려면 pack() 메소드 사용

# Grid: 격자 배치 관리자
# 위젯들을 2차원적인 격자에 배치
# 격자 배치 관리자를 사용하려면 grid() 메소드 사용

# Place: 절대 배치 관리자
# 사용자가 지정한 위치에 위젯들을 배치
# 절대 배치 관리자를 사용하려면 place() 메소드 사용

# 압축 배치 관리자
# 압축 배치 관리자: 위젯을 최대한 압축하여서 상하로 배치

# pack.py
"""
from tkinter import *
window = Tk()

Button(window, text="박스 #1", bg="red", fg="white").pack()
Button(window, text="박스 #2", bg="green", fg="black").pack()
Button(window, text="박스 #3", bg="orange", fg="white").pack()

window.mainloop()
"""

# Button() 생성자는 버튼 객체를 반환

# 박스들의 방향 배치(side = LEFT, RIGHT, TOP, BOTTOM)
"""
Button(window, text="박스 #1", bg="red", fg="white").pack(side=LEFT)
Button(window, text="박스 #1", bg="red", fg="white").pack(side=LEFT)
Button(window, text="박스 #1", bg="red", fg="white").pack(side=LEFT)
"""

# 격자 배치 관리자
# 격자 배치 관리자: 위젯을 테이블 형태로 배치

# grid.py
"""
from tkinter import *
window = Tk()

b1 = Button(window, text="박스 #1", bg="red", fg="white")
b2 = Button(window, text="박스 #1", bg="green", fg="white")
b3 = Button(window, text="박스 #1", bg="orange", fg="white")
b4 = Button(window, text="박스 #1", bg="pink", fg="white")

b1.grid(row=0, column=0)
b2.grid(row=0, column=1)
b3.grid(row=1, column=0)
b4.grid(row=1, column=1)

window.mainloop()
"""

# 절대 위치 배치 관리자
# 절대 위치 배치 관리자: 정대 위치를 사용하여 위젯을 배치

# place.py
"""
from tkinter import *
window = Tk()

b1 = Button(window, text="박스 #1", bg="red", fg="white")
b1.place(x=0, y=0)
b2 = Button(window, text="박스 #2", bg="green", fg="black")
b2.place(x=20, y=30)
b3 = Button(window, text="박스 #3", bg="orange", fg="white")
b3.place(x=40, y=60)

window.mainloop()
"""

# 여러 배치 관리자 혼용하기

# frame.py
"""
from tkinter import *
window = Tk()
f = Frame(window) # 원도우 안에 프레임을 만듦

b1 = Button(f, text="박스 #1", bg="red", fg="white")
b2 = Button(f, text="박스 #2", bg="green", fg="black")
b3 = Button(f, text="박스 #3", bg="orange", fg="white")
b1.pack(side=LEFT)
b2.pack(side=LEFT)
b3.pack(side=LEFT)

l = Label(window, text="이 레이블은 버튼들 위에 배치된다.")
l.pack() # 레이블을 루트 윈도우에 압축 배치 관리자로 배치
f.pack()

window.mainloop()
"""

# 윈도우의 크기와 위젯의 크기 설정하기
# 루트 윈도우의 크기: geometry("600x200") # 너비: 600, 높이: 200
# 윈도우의 크기는 픽셀 단위

# wsize.py
"""
from tkinter import *

window = Tk()
window.geometry("600x100")

Button(window, text="박스 #1", width=10, height=1).pack()
Button(window, text="박스 #2", width=10, height=1).pack()
Button(window, text="박수 #3", width=10, height=1).pack()

window.mainloop()
"""

# temp_conv.py
"""
from tkinter import *
window = Tk()

Label(window, text="화씨").grid(row=0, column=0)
Label(window, text="섭씨").grid(row=1, column=0)

Entry(window).grid(row=0, column=1)
Entry(window).grid(row=1, column=1)

Button(window, text="화씨->섭씨").grid(row=2, column=1)
# Button(window, text="화씨->섭씨").grid(row=2, column=1, sticky= W + E + N + S)

window.mainloop()
"""

# grid.py
"""
from tkinter import *
window = Tk()

Label(window, text="너비").grid(row=0, column=0)
Label(window, text="높이").grid(row=1, column=0)

Entry(window).grid(row=0, column=1)
Entry(window).grid(row=1, column=1)

photo = PhotoImage(file="C:/Users/chogu/Downloads/hamburger.png")
Label(window, image=photo).grid(row=0, column=2, columnspan=2, rowspan=2)

Button(window, text="이미지 저장").grid(row=2, column=0, columnspan=2)
Button(window, text="확대").grid(row=2, column=2)
Button(window, text="축소").grid(row=2, column=3)

window.mainloop()
"""

# 9-5 버튼 이벤트 처리
# 이벤트 구동 프로그래밍: 이벤트가 프로그램의 실행 순서를 결정하는 프로그래밍
# 콜백함수(핸들러): 이벤트가 발생하였을 때 호출되는 함수
# 버튼에 콜백 함수를 등록하려면 버튼의 생성자를 호출할 때, command 매개변수에 이벤트를 처리하는 함수의 이름을 지정하면 됨

# Button = (window, command="함수 이름")

# event1.py
"""
from tkinter import *

window = Tk()

def process():
    print("버튼이 클릭되었습니다.")

button = Button(window, text="클릭하세요!", command=process)

button.pack()
window.mainloop()
"""

# stopwatch.py
"""
from tkinter import *

window = Tk()

counter = 0

def count():
    global counter # 전역 변수 counter 사용 
    counter += 1
    label["text"] = "버튼 클릭 횟수: " + str(counter) # 레이블 객체가 가진 "text" 속성은 딕셔너리 처럼 찾을 수 있음 

label = Label(window, text="아직 눌러지지 않음")
label.pack()
button = Button(window, text="증가", command=count)
button.pack()

window.mainloop()
"""

# temp_conv2.py
"""
from tkinter import *
window = Tk()

def process():
    tf = float(e1.get()) # e1.get()은 문자열 반환
    tc = (tf - 32.0) * 5.0 / 9.0
    e2.delete(0, END) # 처음부터 끝까지 지움
    e2.insert(0, str(tc)) # insert()의 두 번째 인자는 문자열


Label(window, text="화씨").grid(row=0, column=0)
Label(window, text="섭씨").grid(row=1, column=0)

e1 = Entry(window)
e1.grid(row=0, column=1)
e2 = Entry(window)
e2.grid(row=1, column=1)

Button(window, text="화씨->섭씨", command=process).grid(row=2, column=0, sticky=W+E+N+S)
Button(window, text="섭씨->화씨", command=process).grid(row=2, column=1)

window.mainloop()
"""

# 위젯의 속성 변셩
# fg, bg, font, text, command와 같은 매개 변수에 값을 전달하여서 속성 지정 가능

# 위젯이 생성되면 아래 형식을 통해 위젯의 속성 변경 가능
# label["text"] = "This is a label."
# label["fg"] = "blue"
# label["bg"] = "#FF00AA"

# config() 함수도 사용 가능
# label.config(text="World")

# guess.number.py
"""
from tkinter import *
import random

answer = random.randint(1, 100)

def guessing():
    guess = int(guessField.get())

    if guess > answer:
        msg = "높음!"
    elif guess < answer:
        msg = "낮음!"
    else:
        msg = "정답!"

    resultLabel["text"] = msg
    guessField.delete(0, 5)

def reset():
    global answer
    answer = random.randint(1, 100)
    resultLabel["text"] = "다시 한번 하세요! "

window = Tk()
window.configure(bg="white")
window.title("숫자를 맞춰보세요!")
window.geometry("500x80")

titleLabel = Label(window, text="숫자 게임에 오신 것을 환영합니다!", bg="white")
titleLabel.pack()

guessField = Entry(window)
guessField.pack(side="left")

tryButton = Button(window, text="시도", fg="green", bg="white", command=guessing)
tryButton.pack(side="left")

resetButton = Button(window, text="초기화", fg="red", bg="white", command=reset)
resetButton.pack(side="left")

resultLabel = Label(window, text="1부터 100사이의 숫자를 입력하시오.", bg="white")
resultLabel.pack(side="left")

window.mainloop()
"""

