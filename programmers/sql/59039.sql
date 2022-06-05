/*
 제목: 여러 기준으로 정렬하기
 데이터베이스: MySQL
 제출일자: 2022/04/24
*/
SELECT animal_id, name, datetime
FROM animal_ins
ORDER BY name, datetime DESC;