/*
 제목: 루시와 엘라 찾기
 데이터베이스: MySQL
 제출일자: 2022/04/25
*/
SELECT animal_id, name, sex_upon_intake
FROM animal_ins
WHERE name IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty');