/*
 제목: 없어진 기록 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT ao.animal_id, ao.name
FROM animal_ins ai
    RIGHT OUTER JOIN animal_outs ao ON ai.animal_id = ao.animal_id
WHERE ai.animal_id IS NULL
ORDER BY 1;