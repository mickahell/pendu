import random
import pickle
import math

import dessin


jouer = True
pseudo = input("Ton pseudo --> ")
score = 0

partie = 0

while jouer:
    partie += 1
    count = 10

    # 0. Mode de jeu
    mode = input("1 ou 2 joueurs ? 1/2 : ")
    mode = int(mode)
    while mode != 1 and mode != 2:
        print("Gnéééééé...")
        mode = int(input("1 ou 2 joueurs ? 1/2 : "))

    # 1. Avoir un mot
    # Un joueur
    if mode == 1:
        mot = ""
        dico = open("../dico.txt", "r")
        contenu = dico.read()
        dico.close()
        i = 0
        rand = 0
        while i < len(contenu):
            if contenu[i] == '\n':
                rand += 1
            i += 1

        randomNb = random.randrange(rand)
        while randomNb == 0:
            randomNb = random.randrange(rand)

        i = 0
        while i < len(contenu) and randomNb != 0:
            if contenu[i] == '\n':
                randomNb -= 1
            if randomNb == 1:
                mot += contenu[i]
            i += 1

        mot = mot[1:]
        motMystere = mot.upper()

    # Deux joueurs
    else:
        mot = str(input("Choisie un mot --> "))
        motMystere = mot.upper()


    # 2. Masquer le mot
    i = 0
    masquage = ""
    while i < len(motMystere):
        masquage += '*'
        i += 1


    # 4. Deviner le mot
    while motMystere != masquage and count != 0:
        print("\nTu as ", count, " coups pour découvrir le mot \n -->", masquage)
        devine = input("Donne moi une lettre --> ")
        motDevine = devine.upper()

        # Verification
        i = 0
        while i < len(motMystere):
            # 1. Bonne lettre
            if motDevine == motMystere[i]:
                masquage = masquage[:i] + motDevine + masquage[i+1:]

            i += 1
        if masquage.find(motDevine) == -1:
            count -= 1
            dessin.dessin(count)

    if masquage == motMystere:
        print("BRAVO !")
    else:
        print("BOUUUUUH")


    # 5. Nouvelle partie ?
    score += count / partie
    score = math.ceil(score)
    print("\nTon score -->", score)
    again = input("Autre partie ? (Y/N) --> ")
    again = str(again)
    again = again.upper()
    while again != 'Y' and again != 'N':
        print("Gnéééééé...")
        again = input("Autre partie ? (Y/N) --> ")
        again = again.upper()
    if again == 'N':
        jouer = False

        saveRecup = pickle.load(open("scores", "rb"))
        saveRecup[pseudo] = score
        print("Bybye...\n\n")
        print("Best scores :")

        pickle.dump(saveRecup, open("scores", "wb" ))

        for user, scoring in saveRecup.items():
            print("{} : {}".format(user, scoring))

    if again == 'Y':
        clear = "\n" * 10
        print(clear)
