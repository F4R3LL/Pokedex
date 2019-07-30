//
// Team.hh for piscine in /home/selari_j/rendu/rush03_pool/v_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sun Jan 25 19:15:30 2015 Julien Selaries
// Last update Sun Jan 25 21:27:16 2015 Julien Selaries
//

#ifndef		TEAM_HH_
# define	TEAM_HH_

#include	<vector>
#include	"Pokeplus.hh"

class				Team
{
private:

  std::string			name;
  int				id;

  int				size_team;
  std::string			path;

public:
  Team();
  ~Team();

  std::vector<Pokeplus*>	tab_pokemon;

  std::string			getName();
  int				getId();

  void				setName(std::string);
  void				setId(int);
  
  int				addPokemon(int, std::string);
  int				deletePokemon(int);

  int				SaveTeam(std::string);
  int				GetTeam(std::string, std::string);
  int				getSizeTeam();
};

#endif		/* !TEAM_HH_ */
