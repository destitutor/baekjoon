/*
 제목: NULL 처리하기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_type, IF(name IS NULL, 'No name', name), sex_upon_intake
FROM animal_ins
ORDER BY animal_id;