SELECT DISTINCT name FROM movies
JOIN stars ON movie_id = movies.id
JOIN people ON people.id = person_id
WHERE person_id IN (SELECT people.id FROM people WHERE name = "Bradley Cooper" OR name = "Jennifer Lawrence)