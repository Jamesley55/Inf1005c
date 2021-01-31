import math
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

       


def mod_vect(x,y,z):
    Distance = math.sqrt(x*x + y*y + z*z)
    print ("La distance de ce point à l'origine est:")
    print (Distance)
    return Distance

def exo5():
    print ("Veuillez entrer un point en x :")
    x = int(input())
    print ("Veuillez entrer un point en y :")
    y = int(input()) 
    print ("Veuillez entrer un point en z :")
    z = int(input())
    plus_proche_de_lorigine = mod_vect(x,y,z)
    while plus_proche_de_lorigine != 0:
        print ("Veuillez entrer un point en x :")
        x = int(input())
        print ("Veuillez entrer un point en y :")
        y = int(input()) 
        print ("Veuillez entrer un point en z :")
        z = int(input())
        dist_nouveau_point = mod_vect(x,y,z)
        if  dist_nouveau_point < plus_proche_de_lorigine:
            print("Ce point est plus proche de l'rogine que les point precedent")
            plus_proche_de_lorigine=dist_nouveau_point

    print("vous avez trouvez le point le plus proche de l'origine")


def f(y,x):
    return (y+x/y)/2 

def exo6():
    print("Entrez un réel positif x")
    x = int(input()) 
    y0=x
    i=1

    e=1
    while  e > 0.01:
        racine=f(i,x)
        if (racine>i):
            e=racine-i
        else:
            e=i-racine
        i=racine
    print("La racine carré de x est: ")
    print(i)  

exo6()