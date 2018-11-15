//
// team.hpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 12:08:24 2015 Julien Selaries
// Last update Sat Jan 24 14:56:42 2015 Julien Selaries
//

#ifndef		TEAM_HPP_
# define	TEAM_HPP_

#include	<string>
#include	"team_pokemon.hpp"

# define	SIZE_TEAM	6

// faire une macro est rentable ? :p

class		Team
{
private:

  std::string	name;
  int		id; // combiner avec l'avatar
  Pokemon	team[SIZE_TEAM];
  
public:

  Team(std::string); //  les paramètres
  ~Team(); // FAUT FREE !!
  
  std::string	getName(); // ofc
  int		getId(); // rofl
  Pokemon	*getTeam(); // rofl

  void		setName(std::string);
  void		setId(int);
  void		setPokemon(Pokemon *);

  bool		addPokemon(std::string name, int pos); //add a pokemon par la case "new"
  bool		deletePokemon(std::string name, int pos); // delete a pokemon
  
  void		saveTeam(); // open write sauvegarde : data +\n (easy parser)
  void		getTeam(std::string name_folder);

  
};

#endif		/* !TEAM_HPP_ */
