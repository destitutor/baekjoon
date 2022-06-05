/*
 제목: 오랜 기간 보호한 동물(2)
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT ai.animal_id, ai.name
FROM animal_ins ai
    JOIN animal_outs ao ON ao.animal_id = ai.animal_id
ORDER BY DATEDIFF(ai.datetime, ao.datetime)
LIMIT 2;