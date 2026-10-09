### V2
#### Explication
[Sieve of Atkin - Wikipedia](https://en.wikipedia.org/wiki/Sieve_of_Atkin)
**Complexité** : $O(n)$ voir $O(\frac{n}{\log(\log(n))})$ avec des optimisations de mémoires
> [!NOTE] Remarque
> La complexité d'Atkin est certes théoriquement inférieur à la méthode d'Ératosthène mais cela a lieu lorsque l'on prend des grands chiffres comme limite

**1. Tri par modulo de 60**
Tous les nombres premiers supérieurs à 5 ont leur modulo 60 qui est compris dans une liste :
- $p\%60\in\{1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59\}$
On peut donc déjà faire un tri, mais ils ne sont pas tous forcément des nombres premiers.

**2. Condition selon le modulo**
On a :
- $N$ le nombre potentiellement premier, utilisé comme _limite_ à chaque opération.
- $r$ le modulo de $p?$ (qui est donc compris dans la liste ci-dessus)

Alors, selon $r$ on a 3 équations différentes. On garde uniquement les nombres avec un nombre de résultat possible **impair**. (Il y a encore des faux positifs, typiquement les multiples de carré parfait)
1. $r_n\in\{1,13,17,29,37,41,49,53\}$
	$\Rightarrow4x^2+y^2=n$
	- Tout en sachant que $4x^2+y^2\leq N$
	- Donc au max $y=0\Rightarrow4x^2=N\Rightarrow x=\sqrt{\frac{N}{4}}$
	- Et au max $x=0\Rightarrow y^2=N\Rightarrow y=\sqrt{N}$
	- 
2. $r_n\in\{7,19,31,43\}$
	$\Rightarrow3x^2+y^2=n$
	- Tout en sachant que $3x^2+y^2\leq N$
	- Donc au max $y=0\Rightarrow3x^2=N\Rightarrow x=\sqrt{\frac{N}{3}}$
	- Et au max $x=0\Rightarrow y^2=N\Rightarrow y=\sqrt{N}$
	- 
3. $r_n\in\{11,23,47,59\}$
	$\Rightarrow3x^2-y^2=n|x\gt y$
	- Tout en sachant que $3x^2-y^2\leq N$
	- Donc ...
4. Sinon, on ignore

Ensuite on parcourt les nombres obtenu du plus bas au plus haut et pour chaque nombre qu'on a on vérifie ses multiples de carré ($n^2\cdot k$)
- Typiquement pour 7 : $1\cdot7^2=49,2\cdot7^2=98,3\cdot7^2=142$. jusqu'à ce que $k\cdot7^2>n$

#### Pseudocode
$limite$ la limite donné par l'utilisateur
On initialise un tableau `prime` de $[1,limite]$ en booléen faux.
Hardcoder `prime[2]=true` et `prime[3]=true`

Pour x de 1 jusqu'à $\sqrt{limite}$
	Pour y de 1 jusqu'à $\sqrt{limite}$
		//Première équation
		$n=4\cdot x^2+y^2$
		Si $n\leq limite$ ET $n\%60\in\{1,13,17,29,37,41,49,53\}$ ALORS `prime[n]=!prime[n]`.
		Seconde équation
		$n=3\cdot x^2+y^2$
		Si $n\leq limite$ ET $n\%60\in\{7,19,31,43\}$ ALORS `prime[n]=!prime[n]`.
		Troisième équation
		$n=3*x^2-y^2$
		Si $x\gt y$ ET $n\leq limite$ ET $n\%60\in\{11,23,47,59\}$ ALORS `prime[n]=!prime[n]`.

Pour z de 5 à $\sqrt{limite}$
	Si `prime[z]`
		Pour a de 1 à $\frac{limite}{z^2}$
			`prime[a*z^2]=false`

#### Code
```c++
void primeNumberAtkin() {  
    std::cout << "Entrez un numero atkin (1) : ";  
    int limit; std::cin >> limit;  
    bool prime[limit];  
    for (int i = 0; i < limit; i++) {  
        prime[i] = false;  
    }  
    prime[2] = true;  
    prime[3] = true;  
  
    int n = 0;  
    for (int x = 1; x < std::sqrt(limit); x++) {  
        for (int y = 1; y < std::sqrt(limit); y++) {  
            //1.  
            n=4*static_cast<int>(std::pow(x, 2))+static_cast<int>(std::pow(y,2));  
            if (n<limit&&(n%60==1||n%60==13||n%60==17||n%60==29||n%60==37||n%60==41||n%60==49||n%60==53)) {  
                prime[n] = !prime[n];  
            }  
  
            //2.  
            n=3*static_cast<int>(std::pow(x, 2))+static_cast<int>(std::pow(y,2));  
            if (n<limit&&(n%60==7||n%60==19||n%60==31||n%60==43)) {  
                prime[n] = !prime[n];  
            }  
  
            //3.  
            n=3*static_cast<int>(std::pow(x, 2))-static_cast<int>(std::pow(y,2));  
            if (n<limit&&x>y&&(n%60==11||n%60==23||n%60==47||n%60==59)) {  
                prime[n] = !prime[n];  
            }  
        }  
    }  
  
    for (int z=5;z<std::sqrt(limit);z++) {  
        if (prime[z]) {  
            for (int a=1;a<std::sqrt(limit)/std::pow(z,2);a++) {  
                prime[a*z^2] = false;  
            }  
        }  
    }  
  
    int cptr = 0;  
    for (int i=0;i<limit;i++) {  
        if (prime[i]) {  
            cptr++;  
            std::cout << std::setw(10) << i;  
            if (cptr%5==0) {  
                std::cout << std::endl;  
            }  
        }  
    }  
}
```


### V3
[Sieve of Eratosthenes - Wikipedia](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
**Complexité** : $O(N\log(\log(N)))$
#### Compréhension
$N$ la limite imposée.
On fait une liste de 2 jusqu'à $N$ : $[2,N]$
On fait en continu :
- On prend le plus petit de la liste, 2, c'est un nombre premier puis on calcule tous ses multiples qu'on désactive de la liste.
- On s'arrête à $\sqrt{N}$ car comme pour la [[#V2]]
#### Pseudocode
$limite$ la limite donné par l'utilisateur
On initialise un tableau `prime` de 1 à $limite$ : $[1,limite]$ avec `true` dans toutes les cases

Pour i de 2 à $\sqrt{limite}$
	Si `prime[i]`
		Pour m de $i^2$ à $limite$ (et $m+=i$ pour se charger des multiples)
			`prime[m]=false`

#### Code
```c++
void primeNumberEratosthene() {  
    std::cout << "Entrez un numero erat (1) : ";  
    int limit; std::cin >> limit;  
    bool prime[limit];  
    for (int i = 0; i < limit; i++) {  
        prime[i] = true;  
    }  
  
    for (int i = 2; i*i < limit; i++) {  
        if (prime[i]) {  
            for (int m = i*i; m < limit; m+=i) {  
                prime[m] = false;  
            }  
        }  
    }  
  
    int cptr = 0;  
    for (int i=0;i<limit;i++) {  
        if (prime[i]) {  
            cptr++;  
            std::cout << std::setw(10) << i;  
            if (cptr%5==0) {  
                std::cout << std::endl;  
            }  
        }  
    }  
}
```