from cs50 import SQL
from sys import argv

db = SQL("sqlite:///students.db")
house = argv[1]

#Checks command line arguments
if len(argv) != 2:
    print("Invalid input. Please try again with <roster.py> <House name>")
    exit (1)

for row in db.execute("SELECT first, middle, last, birth FROM students WHERE house IS ? ORDER BY last, first", house):
    if row["middle"] == None:
        print(row["first"], row["last"], ", born in", row["birth"])
    
    else:
        print(row["first"], row["middle"], row["last"], ", born in", row["birth"])


