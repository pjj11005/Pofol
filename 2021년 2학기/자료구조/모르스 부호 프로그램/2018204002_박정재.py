class Morse:

    def get_table(self): # table 리스트를 가져오는 함수
        table=[('A', '.-'), ('B', '-...'), ('C', '-.-.'), ('D', '-..'),
               ('E', '.'), ('F', '..-.'), ('G', '--.'), ('H', '....'),
               ('I', '..'), ('J', '.---'), ('K', '-.-'), ('L', '.-..'),
               ('M', '--'), ('N', '-.'), ('O', '---'), ('P', '.--.'),
               ('Q', '--.-'), ('R', '.-.'), ('S', '...'), ('T', '-'),
               ('U', '..-'), ('V', '...-'), ('W', '.--'), ('X', '-..-'),
               ('Y', '-.--'), ('Z', '--..')]
        return table

    def get_table2(self): # table에서 모스부호 값들로 table2라는 리스트에 새로저장 후 가져오는 함수 
        table=self.get_table()
        table2=[]
        for i in range(len(table)):
            table2.append(table[i][1])
        return table2
            
    def encode(self):# encoding 함수
        word=input("입력 문장 : ")
        table=self.get_table()# table 불러오기
        wlist=list(word)# 입력된 문자열을 리스트로 바꿔준다 
        mlist=[]
        for i in range(len(wlist)):
            mlist.append(table[ord(wlist[i])-65][1])#'A'의 아스키 코드값을 이용해 모스부호값을 저장
        return mlist

    def binarytree(self,a,x):# 이진 트리 함수
        start = 0
        end = len(a) - 1
        
        while start <= end: # 탐색할 범위가 남아 있는 동안 반복
            mid = (start + end) // 2 # 탐색 범위의 중간 위치
            if a.index(x) == mid:# x의 인덱스 값과 중간의 인덱스 값이 같은경우
                return mid
            elif a.index(x) > mid:# x의 인덱스 값이 중간의 인덱스 값보다 큰경우   
                start = mid + 1
            else:# x의 인덱스 값이 중간의 인덱스 값보다 작은경우
                end = mid - 1

        return -1  # 값을 못찾았을 때

    def decode(self,mlist):# decoding 함수
        table=self.get_table()# table 불러오기  
        table2=self.get_table2()# table2 불러오기
        wlist=[]            
        for i in range(len(mlist)):
            index=self.binarytree(table2,mlist[i])# 이진트리 함수로 인덱스 값 찾기
            wlist.append(table[index][0])# 모스부호에 해당하는 알파벳 저장
            
        word=''.join(wlist)#리스트를 문자열로 변환
        return word
    
answer=Morse().encode()#입력된 값을 모스부호로 변환 한 리스트를 answer에 저장
print("Morse Code: ",answer)
answer2=Morse().decode(answer)# 모스부호로 변환된 값을 알파벳으로 바꿔만든 문자열을 answer2에 저장
print("Decoding  :",answer2)
