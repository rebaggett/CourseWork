import csv
from sys import argv

def main():
    # Checks no. of arguments
    if len(argv) != 3:
        print("Invalid input. Please try again with <dna.py> <database> <sequence>")
        exit(1)
    
    # Opens user inputted database
    with open(argv[1]) as file:
        database = csv.reader(file)
        
        # Extracts substrings from database
        STR = list(next(database)[1:])
        
        # Creates list of max counts for each STR
        counts = [0] * len(STR)

        # Opens txt file
        with open(argv[2]) as txt:
            text = txt.read()
        
            #Iterates over each possible STR and counts maximum number of repetitions for that STR
            for i in range( len(STR) ):
                counts[i] = STR_maxcount(text, STR[i])
    
        print_name( database, counts )
 
    
#Counts the maximum amount of times an STR occurs in a given string    
def STR_maxcount(s, STR):
    
    # Creates substring starter value, substring ender value and max counter
    i = 0
    j = len(STR)
    counter = 0
    
    # Until we reach the end of the string
    while i + j < len(s) - 1:
    
        # Checks if snipped string is an STR, if yes, then adds to temp value
        if s[i : i + j] == STR:
            temp = 0
            while s[i : i + j] == STR:
                temp += 1
                i += j
                if temp > counter:
                    counter = temp
                
        # If not an STR, advances to next in series
        else:
            i += 1
        
    return counter
    
# Compare database STR numbers with our counter STR numbers, then prints the name if a match
def print_name(database, counts):
    
    for row in database:
        db_count = [ int(col) for col in row[1:] ]
        if db_count == counts:
            print(*row[:1])
            return
    
    print("No Match")
    return (1)
    
if __name__ == '__main__':
    main()
