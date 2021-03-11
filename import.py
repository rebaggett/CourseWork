from cs50 import SQL
from sys import argv
import csv

db = SQL("sqlite:///students.db")

#Checks argv
if len(argv) !=  2:
    print("Invalid input. Please try again with <import.py> <csv file>")
    exit (1)

with open(argv[1]) as file:
    reader = csv.DictReader(file)
    
    #Adds by row values into database
    for row in reader:
        name = row["name"]
        split = name.split()
        
        #If person has no middle name, inserts None for middle
        if len(split) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)", split[0], split[1], row["house"], row["birth"])
        
        #If person has middle name, inserts all into database
        elif len(split) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", split[0], split[1], split[2], row["house"], row["birth"])
            
        else:
            exit(2)
