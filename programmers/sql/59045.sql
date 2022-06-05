/*
 제목: 보호소에서 중성화한 동물
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT ai.animal_id, ai.animal_type, ai.name
FROM animal_ins ai
    JOIN animal_outs ao ON ao.animal_id = ai.animal_id
WHERE SUBSTRING_INDEX(ai.sex_upon_intake, ' ', 1) = 'Intact' AND
      SUBSTRING_INDEX(ao.sex_upon_outcome, ' ', 1) IN ('Spayed', 'Neutered');