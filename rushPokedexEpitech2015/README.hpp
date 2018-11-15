################
How to use git??
################

-git pull
     Sert à mettre à jour.

-git add <fichier/dossier/etc...>
     ajoute les fichiers à la liste du push

-git commit -m 'ton message qui précise ce que tu as modifé'
     commit les fichiers

-git push
     ajoute les fichier au dépot.

###############
etape 2
###############

#define		SIZE_TEAM	6

// faire une macro est rentable ? :p

class		Team
{
private:

  std::string	name;
  int		id; // combiner avec l'avatar
  Pokemon	team[SIZE_TEAM];
  
public:

  Team(); // les paramètres
  ~Team(); // FAUT FREE !!
  
  std::string	getName(); // ofc
  int		getId(); // rofl
  Pokemon	*getTeam(); // rofl

  bool		addPokemon(std::string name, int pos); //add a pokemon par la case "new"
  bool		deletePokemon(std::string name, int pos); // delete a pokemon
  void		saveTeam(); // open write sauvegarde : data +\n (easy parser)
  void		getTeam(std::string name_folder); // ptet à lier avec l'init
};

typedef struct	s_stat
{
  int		HP;
  int		Atk;
  int		Def;
  int		SpA;
  int		SpD;
  int		Spe;
}		t_stat;

enum	e_gender
  {
    NONE,
    MALE,
    FEMALE
  };

typedef struct	s_detail
{
  e_gender	gender;
  int		hapiness;
  int		weight;
  int		height;
  bool		shiny;
  int		level;
  std::string	name;
  std::string	ability;
}		t_detail;

typedef	struct	s_move
{
  std::string	move_1; //transformer en class Move via getter
  std::string	move_2; // le getter check si le pokemon peut apprendre lattaque
  std::string	move_3; // ou via setter
  std::string	move_4;
}		t_move;

Class		Pokemon
{
  t_stat	stats;
  t_detail	details;
  t_move	moves;
}
