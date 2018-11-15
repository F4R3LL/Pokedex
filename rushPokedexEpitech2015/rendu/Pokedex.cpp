//
// Pokedex.cpp for Pokedex.cpp in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:19:31 2015 Tristan Roby
// Last update Sat Jan 24 15:55:41 2015 Tristan Roby
//

#include <iostream>
#include <sstream>
#include <string>
#include "Pokedex.hh"

void Pokedex::getPokemonNameList(std::string const &xml, int pknb)
{
  std::string nb;
  std::stringstream convert;
  
  convert << pknb;
  nb = convert.str();
  std::string to_find;
  to_find = "pokemon id='";
  to_find += nb;
  to_find += "'>";
  std::size_t found = xml.find(to_find);
  std::string pokemon;
  if (found != std::string::npos)
    {
      while (xml[found] != '>')
	found++;
      found++;
      while (xml[found] != '>')
	found++;
      found++;
      while(xml[found] != '<')
	pokemon+=xml[found++];
    }
  else
    {
      std::cout << to_find << " not found in pokedata.xml" << std::endl;
      return;
    }
  this->pokemonName[pknb - 1] = pokemon;
}

Pokedex::Pokedex()
{
  this->pokemonName = new std::string[493];
}

Pokedex::~Pokedex()
{
  delete []this->pokemonName;
}
