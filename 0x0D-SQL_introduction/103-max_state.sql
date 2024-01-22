-- Display the max temperature of each state (ordered by State name)
SELECT State, MAX(Temperature) AS max_temp
FROM temperatures
GROUP BY State
ORDER BY State;
