/*
 제목: 고양이와 개는 몇 마리 있을까
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_type, COUNT(*)
FROM animal_ins
GROUP BY animal_type
ORDER BY animal_type;