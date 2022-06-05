/*
 제목: 입양 시각 구하기(2)
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT hour, SUM(count)
FROM
    ((WITH RECURSIVE seq AS (SELECT 0 AS value UNION ALL SELECT value + 1 FROM seq WHERE value < 23)
      SELECT value AS hour, 0 AS count FROM seq)
    UNION
    (SELECT HOUR(datetime) AS hour, COUNT(*) AS count FROM animal_outs GROUP BY 1)) t
GROUP BY 1;