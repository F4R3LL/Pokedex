//
// Team.cpp for piscine in /home/selari_j/rendu/rush03_pool/v_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sun Jan 25 19:22:24 2015 Julien Selaries
// Last update Sun Jan 25 21:59:34 2015 Julien Selaries
//

#include	<sstream>
#include	<fstream>
#include	<boost/lexical_cast.hpp>
#include	"Team.hh"

Team::Team()
{
  this->name = "";
  this->id = 0;

  this->size_team = 0;
  this->path = "./.save/";
}

Team::~Team()
{

}


std::string			Team::getName()
{
  return (this->name);
}

int				Team::getId()
{
  return (this->id);
}



void				Team::setName(std::string value)
{
  this->name = value;
}

void				Team::setId(int value)
{
  this->id = value;
}

int				Team::addPokemon(int id, std::string xml)
{
  Pokeplus	*new_p = new Pokeplus;

  if (this->size_team < 6)
    {
      new_p->setPokemon(id, xml);
      this->tab_pokemon.push_back(new_p);
      ++this->size_team;
      return (0);
    }
  return (-1);
}

int				Team::deletePokemon(int pos)
{
  if (this->size_team > 0 &&
      pos < 6 &&
      pos >= 0)
    {
      this->tab_pokemon.erase(this->tab_pokemon.begin() + pos);
      --this->size_team;
      return (0);
    }
  return (-1);
}

int				Team::getSizeTeam()
{
  return (this->size_team);
}

int			Team::SaveTeam(std::string name)
{
  std::fstream	file;
  std::string	filename;
  int		u;

  u = 0;
  filename = this->path + name;
  file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
  if (!file.is_open())
    return (-1);
  file << this->size_team << std::endl;
  file << this->name << std::endl;
  file << this->id << std::endl;
  while (u < this->size_team)
    {
      file << this->tab_pokemon.at(u)->pokemon.ID << std::endl;

      file << this->tab_pokemon.at(u)->getIvHP() << std::endl;
      file << this->tab_pokemon.at(u)->getIvAtk() << std::endl;
      file << this->tab_pokemon.at(u)->getIvDef() << std::endl;
      file << this->tab_pokemon.at(u)->getIvSpA() << std::endl;
      file << this->tab_pokemon.at(u)->getIvSpD() << std::endl;
      file << this->tab_pokemon.at(u)->getIvSpe() << std::endl;
      
      file << this->tab_pokemon.at(u)->getEvHP() << std::endl;
      file << this->tab_pokemon.at(u)->getEvAtk() << std::endl;
      file << this->tab_pokemon.at(u)->getEvDef() << std::endl;
      file << this->tab_pokemon.at(u)->getEvSpA() << std::endl;
      file << this->tab_pokemon.at(u)->getEvSpD() << std::endl;
      file << this->tab_pokemon.at(u)->getEvSpe() << std::endl;

      file << this->tab_pokemon.at(u)->getHapiness() << std::endl;
      ++u;
    }
  file.close();
  return (0);
}

int			Team::GetTeam(std::string name, std::string xml)
{
  std::fstream		file;
  std::string		filename;
  std::string		buffer;
  int			u;

  u = 0;
  filename = this->path + name;
  file.open(filename.c_str(), std::fstream::in);
  if (!file.is_open())
    return (-1);

  getline(file, buffer);
  this->size_team = boost::lexical_cast<int>(buffer);
  
  getline(file, buffer);
  this->setName(buffer);

  getline(file, buffer);
  this->id = boost::lexical_cast<int>(buffer);

  while (u < this->size_team)
    {
      getline(file, buffer);
      Pokeplus	*new_p = new Pokeplus;

      new_p->setPokemon(boost::lexical_cast<int>(buffer), xml);
      this->tab_pokemon.push_back(new_p);

      /* ivs */
      
      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvHP(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvAtk(boost::lexical_cast<int>(buffer));
      
      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvDef(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvSpA(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvSpD(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setIvSpe(boost::lexical_cast<int>(buffer));

      /* evs */

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvHP(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvAtk(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvDef(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvSpA(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvSpD(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setEvSpe(boost::lexical_cast<int>(buffer));

      getline(file, buffer);
      this->tab_pokemon.at(u)->setHapiness(boost::lexical_cast<int>(buffer));
      
      ++u;
    }
  std::cout << this->size_team << std::endl;
  return (0);
}
