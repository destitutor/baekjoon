/*
 제목: 입양 시각 구하기(1)
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT HOUR(datetime), COUNT(*)
FROM animal_outs
WHERE HOUR(datetime) >= 9 AND HOUR(datetime) <= 19
GROUP BY 1
ORDER BY 1;