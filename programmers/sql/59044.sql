/*
 제목: 오랜 기간 보호한 동물(1)
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT ai.name, ai.datetime
FROM animal_ins ai
    LEFT OUTER JOIN animal_outs ao ON ao.animal_id = ai.animal_id
WHERE ao.animal_id IS NULL
ORDER BY ai.datetime
LIMIT 3;