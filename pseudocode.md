# Lab3
[HEIG-PRG1/03_nbrePremiers](https://github.com/HEIG-PRG1/03_nbrePremiers)
## Pseudocode
### V1
> [!WARNING] Remarque
> La consigne spécifie "Seules les optimisations évidentes sont à prévoir dans vos algorithmes".
> Ainsi la version 1 sera utilisé même si les autres versions sont plus efficaces

1. Commencer le programme dans une boucle pour pouvoir le relancer
2. Commencer une boucle pour récupérer la variable utilisateur entre 2 et 1000, redemander sinon
3. Calcul des nombres premiers
	1. Démarrer une boucle de 2 jusqu'à la valeur rentré, indice `i` (ou sa racine selon cours de MAD, TODO check)
	2. Initialiser une variable booléenne `isPrime=true`
	3. Démarrer une seconde boucle de 2 jusqu'à `i-1`, indice `j` (à l'intérieur de la première boucle)
	4. Vérifier si `i%j==0` alors `isPrime=false` et on sort de la seconde boucle (`break`)
	5. Si `isPrime` on affiche `i` comme nombre premier (après que la seconde boucle soit fini)
4. Demander si l'utilisateur veut relancer le programme (O/N) selon la première boucle