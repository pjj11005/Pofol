class Remove:
    def remove(self,str):
        for char in sorted(set(str)):# 집합으로 순서대로 정렬된 것에서 알파벳을 반복하여 대입
            rest = str[str.index(char):]# 해당 알파벳이 처음 나오는 곳 부터 끝까지를 rest로 지정
            if set(str) == set(rest): # 전체 집합과 나머지 집합이 일치할때 분리 후 순환 진행
                return char + self.remove(rest.replace(char, ''))
        return ''
            
s=input("Input = ")# 문자열을 입력
answer=Remove().remove(s)#입력된 문자열을 처리하여 값을 도출
print("Result: ",answer)
