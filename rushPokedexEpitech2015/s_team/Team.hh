//
// team_pokemon.hh for piscine in /home/selari_j/rendu/rush03_pool/s_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 16:53:02 2015 Julien Selaries
// Last update Sun Jan 25 18:39:43 2015 Julien Selaries
//

#ifndef		TEAM_HH_
# define	TEAM_HH_

#include	<string>
#include	"Team_Pokemon.hh"

# define	SIZE_TEAM	6

class		Team
{
private:

  std::string	name;
  int		id;

  int		size_team;
  std::string	path;

public:
  Team();
  ~Team();

  Team_Pokemon		pokemon[6];

  std::string		getName();
  void			setName(std::string);

  int			getId();
  void			setId(int);

  int			SaveTeam(std::string);
  int			getTeam(std::string);

  int			addPokemonById(int, int id, std::string xml);
  int			deletePokemonByPos(int);
};

#endif		/* !TEAM_POKEMON_HH_ */
