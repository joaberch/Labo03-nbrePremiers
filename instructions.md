## Nombres 1er

### Objectif
Ecrire un programme qui affiche tous les nombres premiers compris entre 1 et `limite`, où `limite` est une valeur saisie par l’utilisateur.

### A faire
1. Saisir une valeur `limite` comprise entre `2` et `1'000`.
	- Nous partons du principe qu'il n'y a pas d'erreur de saisie (un char `a` par exemple, au lieu d'une valeur numérique).
   - L'utilisateur peut saisir une valeur hors de l'intervalle, telle que `-5` ou `2345`, auquel cas l'utilisateur doit refaire sa saisie.
2. Calculer et afficher sur `n_col` colonnes tous les nombres 1er compris dans l'intervalle `[1 .. limite]`, où `n_col` est une constante définie dans `main`.
3. Un menu `Voulez-vous recommencer [O/N]` pour quitter ou recommencer.
	- Seuls les caractères `O` ou `N` sont acceptés, sinon une nouvelle saisie est faite.

### Compléments
- Commencer par un pseudo-code
- Soigner tout particulièrement la présentation du code
- Eviter toute redondance de code
- Seules les optimisations évidentes sont à prévoir dans vos algorithmes
- Après chaque saisie, il est prudent de vider le buffer avec l'instruction<br>`cin.ignore(numeric_limits<streamsize>::max(), '\n')` (nécessite `<limits>`)
- L'espacement réservé pour l'affichage d'une `valeur` peut être géré par `setw(n)`<br> exemple : `cout << setw(10) << valeur;` (nécessite `<iomanip>`)
- Ne pas utiliser de sous-programme

L'affichage suivant est attendu

~~~cpp
Ce programme ...

entrer une valeur [2-1000] : 1 
entrer une valeur [2-1000] : 1001
entrer une valeur [2-1000] : 55

Voici la liste des nombres premiers
        2       3       5       7       11 
        13      17      19      23      29 
        31      37      41      43      47 
        53 

Voulez-vous recommencer [O/N] : a
Voulez-vous recommencer [O/N] : N

Fin de programme
~~~

### Modalités
- 4 périodes
- **à faire seul(e)**
- à rendre dans git selon les indications des assistants

---
Bon travail