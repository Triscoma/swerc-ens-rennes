/**
  Techniques avancées de lecture d'entrées
*/

// Si on ne connaît pas à l'avance le nombre de valeurs, on peut lire 
// jusqu'à la fin de l'entrée (EOF)
int x;
while (cin >> x) {
	// traiter x
}

// getline() permet de récupérer toute une ligne dans une string
string line;
getline(cin, line);

// attention : si on fait cin >> x sur x à la fin d'une ligne, il restera
// dans le flux standard le caractère '\n' en première ligne, donc getline
// ne capturera que ce caractère. Il faut faire cin.ignore() après cin, qui
// ignore le prochain caractère.
int x; cin >> x; cin.ignore();
string line; getline(cin, line);

// pour tout ignorer jusqu'à la fin de la ligne au lieu d'un seul caractère :
cin.ignore(numeric_limits<streamsize>::max(), '\n');

// le type stringstream permet de lire et d'écrire des strings comme avec
// cin / cout (istringstream pour seulement cin, ostringstream pour seulement 
// cout). Utile après avoir getline :
string line;
getline(cin, line);
istringstream iss(line);
while (iss >> x) {
	// traiter x
}

// Si un nombre inconnu de lignes contient un nombre inconnu de valeurs : 
string line;
while (getline(cin, line)) {
	istringstream iss(line);
	int x;
	while (iss >> x) {
		// traiter x
	}
}
