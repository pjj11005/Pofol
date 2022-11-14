class HW_Hashing:
    def __init__(self,size):
        self.M=size
        self.h=[[None,None] for x in range(size)]# h-talble
        self.d=[[None,None] for x in range(size)]# d-talbe
        self.k=[None,None]# h 임시저장 table
        self.l=[None,None]# d 임시저장 table
        self.count1=0 #h-table 항목수 
        self.count2=0 #d-table 항목수
        self.repeat=0 #반복수 (h,d-table 밀어내기 시행후 다시 h-table 밀어내기로 갈 때 1증가)

    def hash(self,key):# h-hash fuction, h(key)
        return key%self.M

    def hash2(self,key):# d-hash function, d(key)
        return (key*key%17)*11%self.M

    def put(self,key,data):# item (key,data) 삽입위한 method
        i=self.hash(key)# key값의 hash함수에서의 index
        j=self.hash2(key)# key값의 hash2함수에서의 index
        while True:
          if self.h[i][0]==None:# h-table이 비어있으면 key값과 data값 삽입
            self.h[i][0]=key
            self.h[i][1]=data
            print("i= ",i)# h-table에 삽입될 index값 출력
            print("h-table: [",i,"] [",self.h[i][0],", '",self.h[i][1],"']")# 삽입된 key,data값 출력
            self.repeat=0# 반복수 초기화
            self.count1+=1# h-table 항목수 1 증가
            return
          if self.h[i][0]==key:# key값이 h-table에 존재할 때
            print("i= ",i)# hash함수 index 출력
            self.h[i][1]=data# data값만 바꿔준다
            return
          if self.d[j][0]==key:# key값이 d-table에 존재할 때
            print("i= ",i)# hash함수 index 출력
            self.d[j][1]=data# data값만 바꿔준다
            return
          if self.h[i][0]!=None:# h-table 충돌 발생시
            if self.repeat==0:# 첫 충돌이면
              print("i= ",i)# hash 함수 index 출력
            self.k[0]=self.h[i][0]# 기존h-table요소 h 임시저장 table에 저장
            self.k[1]=self.h[i][1]
            self.h[i][0]=key# key,data값 h-table에 대입
            self.h[i][1]=data
            j=self.hash2(self.k[0])#h-table에서 밀려난 요소의 d-table에서의 index 계산
            print("[",self.k[0],", '",self.k[1],"'] | h[",i,"]  [",self.h[i][0],", '",self.h[i][1],"'] | h[",i,"]")#h-table에서 밀려난 (key,data)쌍과 삽입된쌍 출력
            if self.d[j][0]==None:# d-table 비어있을때
              self.d[j][0]=self.k[0]#d-table에 h-table에서 밀려난 key,data 삽입
              self.d[j][1]=self.k[1]
              print("d-table: [",j,"] [",self.d[j][0],", '",self.d[j][1],"']")#삽입된 key,data 정보 출력
              self.count2+=1# d-table 항목수 1 증가
              self.repeat=0# 반복수 초기화
              return
            else:# d-table에서 충돌 발생시
              self.l[0]=self.d[j][0]#d-table의 원래 key,data쌍 d 임시저장 table에 저장
              self.l[1]=self.d[j][1]
              self.d[j][0]=self.k[0]#h-table에서 밀려난 key,data쌍 삽입
              self.d[j][1]=self.k[1]
              print("[",self.l[0],", '",self.l[1],"'] | d[",j,"]  [",self.d[j][0],", '",self.d[j][1],"'] | d[",j,"]")#d-table에서 밀려난 (key,data)쌍과 삽입된쌍 출력
              i=self.hash(self.l[0])# d-table에서 밀려난 요소의 hash함수로 계산한 인덱스값 계산
              key=self.l[0]# d-table에서 밀려난 key값 key변수에저장
              data=self.l[1]# d-table에서 밀려난 data값 data변수에저장
              self.repeat+=1# 반복수 1 증가
              continue

          if self.count1>self.M and self.count2>self.M:# h-table, d-table 두개 다 꽉찰 때 까지 반복해도 성공하지 못할 때
            break

    def get(self,key):# key 값에 해당하는 value 값을 return
        i=self.hash(key)# key값의 hash함수에서의 index
        j=self.hash2(key)# key값의 hash2함수에서의 index
        if self.h[i][0]==key:# key값이 h-table에 존재하면
          return self.h[i][1]# value값 반환
        elif self.d[j][0]==key:# key값이 d-table에 존재하면
          return self.d[j][1]# value값 반환
        else:# 존재하지 않을 때
          return None
        
    def delete(self,key):# key를 가지는 item 삭제
        i=self.hash(key)# key값의 hash함수에서의 index
        j=self.hash2(key)# key값의 hash2함수에서의 index
        if self.h[i][0]==key:# key값이 h-table에 존재하면
          self.h[i][0]=None# dey,value값 삭제
          self.h[i][1]=None
        elif self.d[j][0]==key:# key값이 d-table에 존재하면
          self.d[j][0]=None# dey,value값 삭제
          self.d[j][1]=None
        else:# 존재하지 않을 때
          return None

    def print_table(self):# h,d-table 출력
        print('********* Print Tables ************')
        print('h-table:')# h-table 출력
        for i in range(13):
          if i==12:
            print(i)
          else:
            print(i,end='\t')
        for i in range(13):
          if i==12:
            print(self.h[i][0])
          else:
            print(self.h[i][0],end='\t')

        print('d-table:')# d-table 출력
        for i in range(13):
          if i==12:
            print(i)
          else:
            print(i,end='\t')
        for i in range(13):
          if i==12:
            print(self.d[i][0])
          else:
            print(self.d[i][0],end='\t')

if __name__ == '__main__':
    t=HW_Hashing(13)
    t.put(25,'grape')       # 25: 12,  0
    t.put(43,'apple')       # 43:  4,  0
    t.put(13,'banana')      # 13:  0,  7 
    t.put(26,'cherry')      # 26:  0,  0
    t.put(39,'mango')       # 39:  0, 10
    t.put(71,'lime')        # 71:  9,  8
    t.put(50,'orange')      # 50: 11, 11
    t.put(64,'watermelon')  # 64: 12,  7
    print()
    print('--- Get data using keys:')
    print('key 50 data = ',t.get(50))#key값이 50인요소의 value값 가져오기
    print('key 64 data = ',t.get(64))#key값이 64인요소의 value값 가져오기
    print()
    t.print_table()
    print()
    print('----- after deleting key 50: ---------------')
    t.delete(50)# key값이 50인 요소 삭제
    t.print_table()
    print()
    print('key 64 data = ',t.get(64))#key값이 64인요소의 value값 가져오기
    print('-----after adding key 91 with data berry:---------------')
    t.put(91,'berry')       # 91:  0,  9
    t.print_table()
    print()
    print('-----after changing data with key 91 from berry to kiwi:----------')
    t.put(91,'kiwi')
    print('key 91 data = ',t.get(91))
    t.print_table()
