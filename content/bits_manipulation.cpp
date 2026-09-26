/** bits manipulation
 * Fonctions utiles pour manipuler les entiers bit à bit
 * ajouter ll à la fin pour passer un long long en argument 
**/

int x;
__builtin_popcount(x); // nb de bits égaux à 1
__builtin_parity(x); // popcount mod 2
__builtin_clz(x); // numbre de leading zeroes
__builtin_ctz(x); // nombre de trailing zeroes

 // astuces élémentaires
 x | (1<<k) // pour activer le kè bit
 x & ~(1<<k) // pour le désactiver
 x ^ (1<<k) // pour l'inverser
 x & (x-1) // pour désactiver le dernier bit non nul de x
 x & (x-1) == 0 // pour tester si x est une puissance de 2
 x | (x-1) // pour transformer les trainling zeroes en trainling ones
 31 - __builtin_clz(x) // floor(log2(x)), si x > 0
__builtin_ctz(x&-x) // v2(x), si x > 0
	
// parcourir les sous-ensembles d'un ensemble x
int b = 0;
do {
	// process subset b
} while (b = (b-x) & x);

// calculer le plus petit nombre supérieur à x avec autant de bits activés
int c = x&-x;
int r = x+c;
int next = ((r^x) >> 2) / c;
next |= r;

