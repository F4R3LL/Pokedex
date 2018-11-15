//
// Team.cpp for rush in /home/selari_j/rendu/rush03_pool/s_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sun Jan 25 16:29:24 2015 Julien Selaries
// Last update Sun Jan 25 20:33:22 2015 Julien Selaries
//

#include	<iostream>
#include	<fstream>
#include	"Team.hh"

Team::Team()
{
  this->name = "";
  this->id = 0;
  this->path = "./save/";
  this->size_team = 0;
}

Team::~Team()
{
}

std::string		Team::getName()
{
  return (this->name);
}

void			Team::setName(std::string value)
{
  this->name = value;
}

int			Team::getId()
{
  return (this->id);
}

void			Team::setId(int value)
{
  this->id = value;
}

/*
** Useful functions
*/

int			Team::SaveTeam(std::string name)
{
  std::fstream	file;
  std::string	filename;
  int		u;

  u = 0;
  filename = this->path + name;
  file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
  while (u < this->size_team)
    {
      file << this->pokemon[u].getPokemonId() << std::endl;
      
      file << this->pokemon[u].getIvHP() << std::endl;
      file << this->pokemon[u].getIvAtk() << std::endl;
      file << this->pokemon[u].getIvDef() << std::endl;
      file << this->pokemon[u].getIvSpA() << std::endl;
      file << this->pokemon[u].getIvSpD() << std::endl;
      file << this->pokemon[u].getIvSpe() << std::endl;
      
      file << this->pokemon[u].getEvHP() << std::endl;
      file << this->pokemon[u].getEvAtk() << std::endl;
      file << this->pokemon[u].getEvDef() << std::endl;
      file << this->pokemon[u].getEvSpA() << std::endl;
      file << this->pokemon[u].getEvSpD() << std::endl;
      file << this->pokemon[u].getEvSpe() << std::endl;
      
      file << this->pokemon[u].getHapiness() << std::endl;
      ++u;
    }
  file.close();
  return (0);
}

int		Team::getTeam(std::string name)
{
  std::fstream	file;
  std::string	filename;
  int		u;

  u = 0;
  filename = this->path + name;
  return (0);
}

int		Team::addPokemonById(int pos, int id, std::string xml)
{
  if (this->size_team < SIZE_TEAM)
    {
      this->pokemon[pos].AddPokemonById(id, xml);
      std::cout << "AAAAAAAA" << this->pokemon[pos].pokemon->getName() << std::endl;
      ++this->size_team;
      return (0);
    }
  return (-1);
}

int		Team::deletePokemonByPos(int pos)
{
  if (this->size_team > 0)
    {
      delete this->pokemon[pos].pokemon;
      --this->size_team;
      return (0);
    }
  return (-1);
}
