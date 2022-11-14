List = []
class person :
    def __init__(self, name, phoneNum, age):
        self.name = name
        self.phoneNum = phoneNum
        self.age = age

def Input() :
    print("이름 입력 : ",end='')
    Name = input()
    print("폰번호 입력 : ",end='')
    Phone = input()
    print("나이 입력 : ",end='')
    Age = int(input())
    p = person(Name, Phone, Age)
    List.append(p)
    OUTPUT()
    return

def OUTPUT() :
    i = 0
    print("=============================")
    print("전체 데이터 출력")
    while i < len(List) :
        print(List[i].name, List[i].phoneNum, List[i].age)
        i += 1
    print("=============================")
    
def Search() :
    print("탐색할 이름 입력 : ", end = ' ')
    search = input()
    j = 0
    while j < len(List) :
        if search == List[j].name :
            print(List[j].phoneNum)
        j += 1
    return

def Del() :
    print("삭제할 이름 입력 : ", end = ' ')
    delete = input()
    k = 0
    while k < len(List) :
        if delete == List[k].name :
            List.remove(List[k])
        k += 1
    OUTPUT()
    return
 


print('전화번호 관리 프로그램 시작')

while True :
    print("1 : 전화번호 추가,  2 : 탐색,  3 : 삭제,  4 : 종료")
    menu = int(input(''))
    if menu == 1 :
        Input()
    elif menu == 2 :
        Search()
    elif menu == 3 :
        Del()
    elif menu == 4 :
        print("프로젝트 종료")
        break
    else :
        print("메뉴 잘못 입력")
