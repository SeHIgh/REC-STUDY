import  openpyxl  as  op

#Workbook 객체 생성
wb = op.load_workbook("C:/Users/PC/Desktop/캠핑/Camping_List.xlsx")

#'test'라는 이름을 가진 Sheet를 객체로 생성
ws = wb.active

#ws에서 데이터범위 설정
type = input('종류: ')
brand = input('상표: ')
name = input('이름: ')
cnt = input('개수: ')
storage = input('보관 장소: ')
note = input('비고: ')

ws.append([type, brand, name, cnt, storage, note])

# #튜플에 대한 for 문
# for  row_data  in  rng:
#     for  data  in  row_data:
#         #해당 data가 공백이면 "없음"으로 변경
#         if data.value == "접이식 박스":
#             data.value = "회색 박스"

#Workbook 객체 저장
wb.save("C:/Users/PC/Desktop/캠핑/Camping_List.xlsx")