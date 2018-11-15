//
// Pokedex.hh for pokedex in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:08:46 2015 Tristan Roby
// Last update Thu Jan 22 20:54:02 2015 Tristan Roby
//

#include <iostream>

#ifndef POKEDEX_HH_
# define POKEDEX_HH_

class		Pokedex
{
public:
  std::string *pokemonName;
  Pokedex();
  ~Pokedex();
  void getPokemonNameList(std::string const &, int pknb);
};

#endif
