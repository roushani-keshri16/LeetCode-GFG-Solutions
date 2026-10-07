# Write your MySQL query statement below
SELECT DISTINCT l.num AS ConsecutiveNums
FROM (
    SELECT num,
           LAG(num, 1) OVER (ORDER BY id) AS prev_num,
           LEAD(num, 1) OVER (ORDER BY id) AS next_num
    FROM Logs
) l
WHERE l.num = l.prev_num AND l.num = l.next_num;