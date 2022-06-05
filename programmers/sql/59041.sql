/*
 제목: 동명 동물 수 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT name, COUNT(*)
FROM animal_ins
WHERE name IS NOT NULL
GROUP BY name
HAVING COUNT(*) >= 2
ORDER BY name;