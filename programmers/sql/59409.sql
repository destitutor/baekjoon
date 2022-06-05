/*
 제목: 중성화 여부 파악하기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_id, name, IF(SUBSTRING_INDEX(sex_upon_intake, ' ', 1) IN ('Neutered', 'Spayed'), "O", "X") AS 중성화
FROM animal_ins;