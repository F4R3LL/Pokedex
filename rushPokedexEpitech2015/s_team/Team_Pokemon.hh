//
// team_pokemon.hh for piscine in /home/selari_j/rendu/rush03_pool/s_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 16:53:02 2015 Julien Selaries
// Last update Sun Jan 25 18:21:57 2015 Julien Selaries
//

#ifndef		TEAM_POKEMON_HH_
# define	TEAM_POKEMON_HH_

#include	<vector>
#include	"Pokemon.hh"

# define	SIZE_TEAM	6

typedef struct	s_ev
{
  unsigned int	HP;
  unsigned int	Atk;
  unsigned int	Def;
  unsigned int	SpA;
  unsigned int	SpD;
  unsigned int	Spe;
}		t_ev;

typedef struct	s_iv
{
  unsigned int	HP;
  unsigned int	Atk;
  unsigned int	Def;
  unsigned int	SpA;
  unsigned int	SpD;
  unsigned int	Spe;
}		t_iv;

class		Team_Pokemon
{
private:

  t_iv		*iv;
  t_ev		*ev;

  unsigned int	hapiness;
  int		size_team;	

  std::string	path;

public:
  Team_Pokemon();
  ~Team_Pokemon();

  Pokemon	*pokemon;

  void		setSizeTeam(int);
  int		getSizeTeam();

  void		setRandIv();

  int		setIvHP(int);
  int		setIvAtk(int);
  int		setIvDef(int);
  int		setIvSpA(int);
  int		setIvSpD(int);
  int		setIvSpe(int);

  int		getIvHP();
  int		getIvAtk();
  int		getIvDef();
  int		getIvSpA();
  int		getIvSpD();
  int		getIvSpe();

  int		getAllEv();

  int		setEvHP(int);
  int		setEvAtk(int);
  int		setEvDef(int);
  int		setEvSpA(int);
  int		setEvSpD(int);
  int		setEvSpe(int);

  int		getEvHP();
  int		getEvAtk();
  int		getEvDef();
  int		getEvSpA();
  int		getEvSpD();
  int		getEvSpe();

  int		getPokemonId();

  int		getHapiness();
  void		setHapiness(int);

  int		AddPokemonById(unsigned int id, std::string xml);
  void		DeletePokemonByPos();

};

#endif		/* !TEAM_POKEMON_HH_ */
