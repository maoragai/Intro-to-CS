"""
*Student name: Maor Agai
*Student ID: --
*Exercise name: ex7
"""


import sys

def isValidName(name):
    """
    Checks whether a certain name is valid (e.g. Capital letter and all the rest are lower).
    
    Keyword Arguments:
        name - The name that needs to be checked.
    Return - bool value, true if the name is correct, false if not.
    """
    name = name.split(' ')
    for n in name:
        if n[0].isupper() and n[1:].islower():
            continue
        else:
            return False
    return True


def dictionaryInitialization(file):
    """
    Initializing the db that we work with, with movies as keys and a set of actors as values.

    Keyword Arguments:
        file - The file name that we write to.
    Return - The db.
    """
    dictdb = dict()
    print("Processing...")
    with open(file) as f:
        lines = f.readlines()
        for line in lines:
            line = line.replace("\n", "")
            line = line.split(', ')
            for movie in line[1:]:
                if isValidName(line[0]) == False:
                    print("Error")
                    menu()
                if movie in dictdb:
                    dictdb[movie].append(line[0])
                else:
                    dictdb[movie] = list()
                    dictdb[movie].append(line[0])
        #   End of for loop.
    for key in dictdb:
        dictdb[key] = set(dictdb[key])
    return dictdb

def queryByMovie(query):
    """
    Checks out the 3 conditions on 2 movies.

    Keyword Arguments:
        query - The query that we run.
    Return - False if there one of the movies isnt in the db,
            if they are, the set with the actors that
    """
    query = query.split(",")
    movie1 = query[0].strip()
    movie2 = query[1].strip()
    query[2] = query[2].replace(" ", "")
    if movie1 in dictdb and movie1 in dictdb:
        if query[2] == "&":
            return dictdb[movie1] & dictdb[movie2]
        elif query[2] == "|":
            return dictdb[movie1] | dictdb[movie2]
        elif query[2] == "^":
            return dictdb[movie1] ^ dictdb[movie2]
    else:
        # Some of the movies isnt in the db.
        return False


def queryByActor(query):
    """
    Checks who played with a certain actor.

    Keyword Arguments:
        query - The query that we run on, probably in a valid run the query will be a name.
    Return - returns false if the name isn't in the db
            if it is, returns a list of the actors that he played with.
    """
    notActorFlag = False
    actors = list()
    for key in sorted(dictdb):
        if query in dictdb[key]:
            notActorFlag = True
            for element in dictdb[key]:
                if element != query:
                    actors.append(element)
    if notActorFlag is False:
        return None
    return actors


def addLine(line):
    """
    Adds a query to the db.

    Keyword Arguments:
        line - the line that asked to being added.
    Return - no return value.
    """
    line = line.replace("\n", "")
    line = line.split(',')
    if (len(line[1:]) == 0):
        print("Error")  # There is only movie
        return
    movie = line[0].strip()
    if movie not in dictdb:
        dictdb[movie] = set()
    for actor in sorted(line[1:]):
        dictdb[movie].add(actor.strip())

def saveToFile(file):
    """
    Saves the db to a file.
    Convert it from movie as a key to movies as values,
    and from actors as values to actor as the first value in a line.

    Keyword Arguments:
        file - the file name.
    Return - no value.
    """
    dictdbactorskey = dict()
    with open(file, 'w+') as f:
        actors = list()
        for key in dictdb:
            currentmovieactors = list(dictdb[key])
            for actor in currentmovieactors:
                if actor not in actors:
                    actors.append(actor)

        actors.sort()
        printlines = []
        for actor in actors:
            printlines.append(actor)
            for key in sorted(dictdb):
                if actor in dictdb[key]:
                    printlines[len(printlines) - 1] = printlines[len(printlines) - 1] + ", " + key
        actualprintlines = []
        for line in printlines:
            actualprintlines.append(line + "\n")
        f.writelines(actualprintlines)


def printlist(lst):
    """
    Checks who played with a certain actor.

    Keyword Arguments:
        lst - the list / set that we need to print.
    Return - none.
    """
    line = ""
    lst = list(lst)
    lst.sort()
    line = lst[0]
    for element in lst[1:]:
        line = line + ", " + element
    print(line)


def menu():
    """
    The menu that we print.

    Keyword Arguments:
        None.
    Return - No return value.
    """
    choice = 0
    while True:
        print("Please select an option:")
        print("1) Query by movies")
        print("2) Query by actor")
        print("3) Insert a new movie")
        print("4) Save and Exit")
        print("5) Exit")
        choice = input()
        choice = int(choice)
        if choice == 1:
            print("""Please select two movies and an operator(&,|,^) separated with ',':""")
            inputstring = input()
            ret = queryByMovie(inputstring)
            if ret != None and len(ret) > 0:
                printlist(ret)
            elif ret == None or len(ret) == 0:
                print("There are no actors in this group")
            else:
                print("Error")
        if choice == 2:
            print("""Please select an actor:""")
            inputstring = input()
            if isValidName(inputstring) == True:
                printlist(queryByActor(inputstring))
            else:
                print("Error")
        if choice == 3:
            print("Please insert a new movie:")
            inputstring = input()
            addLine(inputstring)
        if choice == 4:
            saveToFile(sys.argv[2])
            return
        if choice == 5:
            return
    # End of while loop.


file = sys.argv[1]
dictdb = dictionaryInitialization(file)
menu()
