class Remove:
    def count(self,word):#문자열을 이루는 알파벳 수를 알기위한 count함수 생성
        count = {}#count라는 이름의 빈 사전 생성
        for letter in word:#문자열 내 알파벳 반복
            if letter not in count:#문자열내에 해당 알파벳이 없으면 0으로 지정
                count[letter] = 0
            count[letter] += 1#있을 때는 1씩 증가
        return count

    def remove(self,str):
        counts=self.count(str)#알파벳 탐색을 위해 counts생성
        stack=[]
        save=set()#이미 들어간 알파벳 탐색을 위한 빈 집합 save생성
        for char in str:
            counts[char]-=1#한 알파벳 탐색시 -1을하여 명시
            if char in save:#이미 문자열에 추가된것은 통과
                continue
            while stack and char<stack[-1] and counts[stack[-1]]>0:
                save.remove(stack.pop())#스택이 비어있고, 탐색 알파벳이 스택의 
                #마지막 알파벳보다 작고 아직 탐색 알파벳이 남아있으면 pop으로 제거

            stack.append(char)#스택에 알파벳 추가
            save.add(char)#집합에 알파벳 추가
        return ''.join(stack)#문자열로 값 반환

s=input("Input = ")#문자열을 입력
answer=Remove().remove(s)#입력된 문자열을 처리하여 값을 도출
print("Result: ",answer)
