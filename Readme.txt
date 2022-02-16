Pentru rezolvarea temei 1 varianta alternativa, am folosit structuri de date din STL, precum list, queue, array, vector si stack.
Structura algoritmului e asemanatoare cu prima varianta, insa faptul ca am folosit functii deja definite a usurat munca.
Astfel, am inceput prin definirea claselor Team si Player si a metodelor acestor clase. Clasa Player este agregata in clasa Team. Jucatorii fiecarei echipe sunt stocati intr-un vector.
Fiecare echipa este stocata in lista de echipe declarata in main. Pentru compararea echipelor a fost utila supradefinirea operatorului <.
Meciurile s-au desfasurat in felul urmator: Dupa eliminarea echipelor cu cel mai mic punctaj din lista, am populat coada "queue_of_teams" care se va modifica pe parcurs. Din aceasta coada, pentru fiecare meci, au fost scoase primele doua echipe din lista, s-a comparat punctajul acestora si au fost introduse fie in stack-ul "winners" fie in stack-ul "defeated". Coada de echipe este populata cu elementele din stack-ul winners iar meciurile se reiau pana la aflarea echipe castigatoare. 
Pentru afisarea primelor opt echipe, in timp ce meciurile aveau loc, am testat cand raman opt echipe in stack-ul "winners" si le-am stocat intr-un array numit "last_teams".
Acest array a fost ordonat si afisat.
De asemenea, am utilizat acest array si la ultima cerinta, pentru a afisa echipele de pe nivelul 2.