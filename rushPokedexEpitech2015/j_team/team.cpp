//
// team.cpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 12:16:07 2015 Julien Selaries
// Last update Sat Jan 24 14:30:29 2015 Julien Selaries
//

#include	"piscine.hpp"

Team::Team(std::string name, int id, Pokemon team[SIZE_TEAM])
{
  this->name = name;
  this->id = id;
  this->team = new (Pokemon) * SIZE_TEAM;
}

Team::~Team()
{
  delete this->team;
}

std::string		Team::getName()
{
  return (this->name);
}

int			Team::getId()
{
  return (this->id);
}

Pokemon			*Team::getPokemon()
{
  return (this->Pokemon);
}

void			Team::setName(std::string Name)
{
  this->name = Name;
}

void			Team::setPokemon(Pokemon *pokemon)
{
  this->Pokemon = pokemon;
}

void			Team::addPokemon(std::string name, int pos)
{
  if (pos != SIZE_TEAM - 1)
    this->Pokemon[pos - 1] = this->Pokemon.getPokemonByName(name);
}
