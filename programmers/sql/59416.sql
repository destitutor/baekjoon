/*
 제목: DATETIME에서 DATE로 형 변환
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_id, name, DATE_FORMAT(datetime, "%Y-%m-%d")
FROM animal_ins
ORDER BY 1;