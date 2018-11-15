//
// Pokedex.hh for pokedex in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:08:46 2015 Tristan Roby
// Last update Sat Jan 24 18:03:51 2015 Julien Selaries
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
