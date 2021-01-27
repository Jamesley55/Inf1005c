
def  exercise3():
    n = -1 


    while n < 0: 
        print("Veuillez saisir un entier positif")
        n = int(input())

    array  = []
    i=0
    plusGrandeLongeur  = 0 
    longeurCourrant = 0

    while i < n: 
        print("Veuillez saisir un nombre ")
        suite = int(input())
        array.append(suite)
        if  i >= 1:
            if array[i] > array [i-1]:
                longeurCourrant = longeurCourrant +1
            if longeurCourrant > plusGrandeLongeur:
                plusGrandeLongeur = longeurCourrant
        i = i+1

    print(plusGrandeLongeur)

        

def exercise4():
    print("veillier entrer un phrase")
    phrase = input()
    
    Inf = "INF"

    i = 0 
    correctPosition = 0 
    while i < len(phrase):

        temp = i 
        j= 0
        while j < len(Inf):
            if Inf[j]  == phrase[temp]:
                correctPosition = correctPosition + 1
            j = j + 1
            temp = temp +1

        if correctPosition == len(Inf):
            print(i)
            print("voila")
            return   
        else: 
            correctPosition = 0
        i = i+1

       


exercise4()