typedef struct Matricule Matricule;
struct Matricule
{
	long membre;
	Matricule *suivant;
};


typedef struct Pile Pile;
struct Pile
{
	Matricule *premier;
};


Pile* fcnt_initialiser();
void fcnt_ajouter(Pile*, long);
long fcnt_supprimer(Pile*);

void fcnt_afficher(Pile*);