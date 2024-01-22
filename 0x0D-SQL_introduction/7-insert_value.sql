-- Insert a new row into first_table, update if duplicate
INSERT INTO first_table (id, name) VALUES (89, 'Best School')
ON DUPLICATE KEY UPDATE name = VALUES(name);
