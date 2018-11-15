//
// Pokemon.hh for pokemonhnh in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Wed Jan 21 17:46:35 2015 Tristan Roby
// Last update Fri Jan 23 20:51:18 2015 Tristan Roby
//

#ifndef POKEMON_H_
#define POKEMON_H_

#include <iostream>

class		Pokemon
{
public:
  std::string	name;
  std::string	type;
  std::string	typesec;
  int		ID;
  int		HP;
  int		ATK;
  int		DEF;
  int		SPD;
  int		SAT;
  int		SDF;
  std::string	*evolution;
  std::string	species;
  double	height;
  double	weight;
  std::string	description;
  std::string	*ability;
  std::string	xml;
private:
  void	setName();
  void	setType();
  void	getPokemonXml(std::string const &xml);
  int	setStats(std::string const &stat);
  void	setEvolution();
  void	setSpecies();
  double setCorpse(std::string const &a);
  void	setDescription();
  void	setAbility();
public:
  void	aff_evo();
  void	aff_abilities();
  Pokemon(int id, std::string const &xml);
  Pokemon();
  ~Pokemon();
};

#endif
