//
// PokedexText.hpp for PokedexText in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Jan 23 14:28:01 2015 Tristan Roby
// Last update Sun Jan 25 22:53:45 2015 Tristan Roby
//

#ifndef POKEDEXTEXT_HPP_
#define	POKEDEXTEXT_HPP_

#include "Pokemon.hh"
#include "aff_list.hh"
# define FSIZE 15
# define EVOSIZE 10
# define MAXMOVE 400
class		PokedexText
{
public:
  PokedexText(Pokemon *a, std::string *);
  ~PokedexText();
private:
  void		setName();
  void		setSpecies();
  void		setDescription();
  void		setTypes();
  void		setStats();
  void		setMensuration();
  void		setEvolution();
  void		setMove();
  bool		aff;
public:
  sf::Text	getName()const;
  bool		getStatus() const;
  sf::Text	getSpecies()const;
  sf::Text	getDescription()const;
  sf::Text	getTypes()const;
  sf::Text	getStats()const;
  sf::Text	getMensuration()const;
  sf::Sprite*	getEvolution();
  int		getNbEvo()const;
  int		setPosMove(int);
  sf::Text*	getMove();
  sf::Font	myFont;
private:
  Pokemon	*info;
  std::string	*list;
  sf::Text	species;
  sf::Text	name;
  sf::Text	description;
  sf::Text	types;
  sf::Text	Stats;
  sf::Text	mensuration;
  int		nbEvo;
  sf::Texture	tEvo[EVOSIZE + 1];
  sf::Sprite	sEvo[EVOSIZE + 1];
  sf::Text	move[400];
};

#endif
