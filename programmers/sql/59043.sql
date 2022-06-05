/*
 제목: 있었는데요 없었습니다
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT ai.animal_id, ai.name
FROM animal_ins ai
    JOIN animal_outs ao ON ao.animal_id = ai.animal_id
WHERE ai.datetime > ao.datetime
ORDER BY ai.datetime;