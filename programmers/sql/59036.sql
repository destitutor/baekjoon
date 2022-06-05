/*
 제목: 아픈 동물 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/22
*/
SELECT  animal_id
       ,name
FROM animal_ins
WHERE intake_condition = 'Sick';