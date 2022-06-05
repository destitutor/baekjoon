/*
 제목: 어린 동물 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/24
*/
SELECT animal_id, name
FROM animal_ins
WHERE intake_condition != 'Aged';