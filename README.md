Bloțiu Mihnea-Andrei - 323CAa
Algoritmi de aproximare - Problema comis-voiajorului

* Am actualizat PDF-ul de la Etapa 1 conform feedback-ului primit;
- Am precizat exact cei 4 algoritmi pe care urmează să îi analizez
- Am adăugat câteva informații suplimentare cu privire la acești algoritmi
- Am schimbat numărul de teste pe care l-am menționat anterior, deoarece
am generat mai multe pentru o mai bună înțelegere și comparare a algoritmilor
în etapa a 3-a.

În cele ce urmează definim:
TSP = Travelling salesman problem
PCV = Problema comis-voiajorului
MST = Minimal spanning tree

Structura arhivei:

* Problema Comis-Voiajorului - Bloțiu Mihnea-Andrei - Actualizat Etapa a 2-a.pdf
  - Actualizarea conform feedback-ului din etapa 1.

* algo.h
  - Conține semnăturile funcțiilor folosite de către toți algoritmii
în afară de Christofides pentru rezolvarea efectivă a TSP.

* Christofides.h
  - Conține clasa cu obiectul de tip TSP, câmpurile acestuia și
semnăturile metodelor aplicate pentru euristica cu același nume;
  - Acestea sunt explicate fiecare prin comentariile din cod.

* tsp_back.cpp
  - Conține implementarea efectivă a funcției tsp_back folosită
pentru rezolvarea PCV cu backtracking;
  - Aceasta este documentată complet cu ajutorul comentariilor
din cod.

* tsp_Christofides.cpp
  - Conține implementarea efectivă a metodelor ce aveau semnătura
în fișierul .h și participă la rezolvarea PCV cu ajutorul euristicii
Christofides;
  - Aceasta este documentată complet cu ajutorul comentariilor
din cod.

* tsp_Greedy.cpp
  - Conține implementarea efectivă a funcției tsp_greedy folosită
pentru rezolvarea PCV prin metoda Greedy;
  - Aceasta este documentată complet cu ajutorul comentariilor
din cod.

* tsp_naive.cpp
  - Conține implementarea efectivă a funcției tsp_naive folosită
pentru rezolvarea PCV prin generarea tuturor permutărilor posibile;
  - Aceasta este documentată complet cu ajutorul comentariilor
din cod.

* test_backtracking.cpp
  - Conține testarea algoritmului tsp_back;
  - Citirea datelor din fișier se face după cum urmează: mai întâi se
citește numărul de noduri ale grafului și apoi o matrice de adiacență
unde pe poziția i,j se află costul necesar parcurgerii muchiei de la
nodul i la nodul j;
  - Se aplică algoritmul de backtracking și se calculează timpul necesar
finalizării acestui algoritm. Acesta este afișat după rularea fiecărui test.
  - Complexitatea de timp a acestui algoritm este O(n!), iar răspunsul furnizat
este cel optim.

* test_Christofides.cpp
  - Conține testarea algoritmului tsp_Christofides.cpp adică implicit,
aplicarea pe rând a fiecărei metode definite în acest fișier după cum urmează.
  - Pentru a varia metoda de transmitere a datelor de intrare, acum, sunt
oferite N orașe prin coordonatele acestora. Se construiește un vector de
structuri cu aceste orașe.
  - Se construiește matricea de adiacență cu aceeași semnificație ca și
în algoritmul anterior prin calcularea matematică efectivă a distanței dintre 
două puncte din plan caracterizate de coordonate.
  - Se construiește un MST folosind algoritmul lui Prim;
  - Se construiește un subgraf format doar din nodurile de ordin impar
din MST;
  - Se formează un nou graf prin combinația muchiilor din subgraf și cele
din graful inițial;
  - Se calculează un circuit eulerian pe noul graf;
  - Se scot din acest circuit muchiile care vizitează noduri deja vizitate
și se întoarce răspunsul final.
  - Se calculează timpul necesar finalizării acestui algoritm și se scrie
traseul parcurs în fișierele de output. 
  - Complexitatea de timp a acestui algoritm este O(n^4), iar răspunsul furnizat
este de 3/2 ori mai mare fată de cel optim.

* test_greedy.cpp
  - Conține testarea algoritmului tsp_greedy;
  - Citirea datelor din fișier se face după cum urmează: mai întâi se
citește numărul de noduri ale grafului și apoi o matrice de adiacență
unde pe poziția i,j se află costul necesar parcurgerii muchiei de la
nodul i la nodul j;
  - Se aplică algoritmul de greedy și se calculează timpul necesar
finalizării acestui algoritm. Acesta este afișat după rularea fiecărui test.
  - Complexitatea de timp a acestui algoritm este O(n^2 * log2 (n)), iar răspunsul furnizat
este considerat sub-optim pentru orice problemă de tip TSP.

* test_naive.cpp
  - Conține testarea algoritmului tsp_naive;
  - Citirea datelor din fișier se face după cum urmează: mai întâi se
citește numărul de noduri ale grafului și apoi o matrice de adiacență
unde pe poziția i,j se află costul necesar parcurgerii muchiei de la
nodul i la nodul j;
  - Se aplică algoritmul naiv și se calculează timpul necesar
finalizării acestui algoritm. Acesta este afișat după rularea fiecărui test.
  - Complexitatea de timp a acestui algoritm este O(n!), iar răspunsul furnizat
este cel optim.

* Makefile
  - Conține o regulă de build pentru toți cei 4 algoritmi menționați
anterior. La comanda „make” în terminal, vor rezulta executabilele
după cum urmează:
  - test1 = tsp_naive
  - test2 = tsp_backtracking
  - test3 = tsp_greedy
  - test4 = tsp_Chrisofides

  - Conține 5 reguli de run după cum urmează:
  - best = ./test4
  - run-p1 = ./test1
  - run-p2 = ./test2
  - run-p3 = ./test3
  - run-p4 = ./test4

  - Conține o regulă de clean pentru ștergerea fișierelor create
de build și a output-urilor realizate de către algoritmul
Christofides.

* Folderul in:
  - Conține 23 de teste variate care vor fi aplicate pentru
a testa algoritmii: naiv, backtracking și greedy deoarece aceștia
au fost configurați pentru a avea modalitatea de citire a datelor
identică.
  - Testele sunt gândite după cum urmează:
a) Testele 1-2: Teste relativ mici de dimensiuni cu matrice simetrice.
b) Testele 3-15, 18-22 : Cresc în dimensiuni și nu reprezintă matrice
simetrice.
c) Testele 16, 17, 23: Reprezintă cazuri particulare de graf, naive
însă care netratate pot cauza anumite probleme după cum urmează:
  - Testul 16: Graf fără niciun nod;
  - Testul 17: Graf cu un singur nod;
  - Testul 23: Graf cu toate costurile între toate laturile identice

* Folderul out:
  - Conține 4 subfoldere intitulate: p1, p2 și p3 cu output-urile
corespunzătoare pentru fiecare dintre algoritmii menționați anterior unde
aplicăm aceste teste.

Toate acestea se testează pe rând folosind următoarele comenzi în terminal:
- python3 checker.py --algo p1 --task 4 --unique-tests
- python3 checker.py --algo p2 --task 4 --unique-tests
- python3 checker.py --algo p3 --task 4 --unique-tests
Acestea afișează și timpul de execuție pentru fiecare test în parte (în secunde).

* Folderul tests_big_Greedy:
  - Conține două subfoldere, in - cu număr mare de orașe folosite doar
pentru algoritmul Greedy (20 - 50 orașe) și out - cu răspunsurile corespunzătoare
fiecărui test în parte.
  - Acestea trebuie testate manual prin schimbarea modului de citire și afișare
a datelor în fișierul test_greedy.cpp. Peste tot unde este scris „fin” se va
transforma în „cin” iar „fout” în „cout”.
  - După aceste modificări se vor rula testele în terminal după compilare
folosind linia de comanda ./test3 < tests_big_Greedy/in/testX_big.in 

* Folderul tests_Christofides:
  - Conține 6 teste mari și foarte mari, de ordinul a 10.000 de orașe ce vor
fi aplicate doar pe algoritmul Christofides după compilare folosind comanda:
./test4 tests_Christofides/tsp_example_X.txt
  - Aceasta va genera un fișier în același director cu extensia .out care
reprezintă atât lungimea totală cât și ordinea în care au fost parcurse
orașele.

* checker.py
  - Checker-ul folosit pentru verificarea automată a testelor precizate
anterior.

* README
  - Acest fișier în care sunt explicate toate cele menționate;
  - Total fișiere și directoare root arhivă: 18. 
  
O parte din surse și testele pe care am verificat algoritmii au fost preluate
din urmatoarele surse:
- https://stemlounge.com/animated-algorithms-for-the-traveling-salesman-problem/
- https://www.geeksforgeeks.org/travelling-salesman-problem-greedy-approach/
- https://www.geeksforgeeks.org/travelling-salesman-problem-set-2-approximate-using-mst/
- https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/?ref=rp
- https://www.geeksforgeeks.org/travelling-salesman-problem-implementation-using-backtracking/?ref=rp
- https://github.com/sth144/christofides-algorithm-cpp
