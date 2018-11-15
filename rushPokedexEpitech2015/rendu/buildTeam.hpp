//
// buildTeam.hpp for BUildTeam in /home/roby_t/rendu/cpp_pokedex/rush-pok-mon-2015
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Sun Jan 25 21:44:11 2015 Tristan Roby
// Last update Sun Jan 25 22:56:43 2015 Tristan Roby
//

#ifndef BUILDTEAM_H_
# define BUILDTEAM_H_

#include "aff_list.hh"
#include "Team.hh"

class		aff_team
{
public:
  sf::Sprite	Spokemon[6];
  sf::Texture	Tpokemon[6];
  sf::Text	Npokemon[6];
  sf::Font	myFont;
  void	my_aff_team(Team &team);
};

#endif
