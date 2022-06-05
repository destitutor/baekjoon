/*
 제목: 이름에 el이 들어가는 동물 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_id, name
FROM animal_ins
WHERE animal_type = 'DOG' AND LOWER(name) LIKE '%el%'
ORDER BY 2;