//
// Pokemon.cpp for pokemoncpp in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Wed Jan 21 17:46:31 2015 Tristan Roby
// Last update Sun Jan 25 17:41:20 2015 Julien Selaries
//

#include "Pokemon.hh"
#include <fstream>
#include <sstream>
#include <string>

void	Pokemon::setAbility()

{
  std::string to_find;
  to_find = "<move type=";
  std::size_t found = 0;
  std::string	*evo = new std::string [400];
  int		i = 0;
  while ((found = xml.find(to_find, found)))
    {
      if (found != std::string::npos)
	{
	  found = xml.find("<name>", found);
	  if (found != std::string::npos)
	    {
	      found+= 6;
	      while (xml[found] != '<')
		evo[i] += xml[found++];
	      found = xml.find("<lvl>", found);
	      if (found != std::string::npos)
		{
		  found+= 5;
		  evo[i] += " at level ";
		  while (xml[found] != '<')
		    evo[i] += xml[found++];
		  
		}
	    }
	}
      else
	{
	  evo[i] = "";
	  this->ability = evo;
	  return;
	}
      ++i;
    }
    this->evolution = evo;
}

void	Pokemon::setDescription()
{
  std::string to_find;
  to_find = "<description>";
  std::size_t found = xml.find(to_find);
  if (found != std::string::npos)
    {
      found += 13;
      while (xml[found] != '<')
	this->description += xml[found++];
    }
  else
    {
      this->description = "";
      std::cout << to_find << " not found in pokedata.xml" << std::endl;
      return;
    }
}

double	Pokemon::setCorpse(std::string const &stat)
{
  std::string to_find;
  to_find = stat;
  std::string HP;
  std::size_t found = xml.find(to_find);
  double value = 0;
  if (found != std::string::npos)
    {
      found += stat.length();
      while (xml[found] != '<')
	HP += xml[found++];
      std::istringstream buffer(HP);
      buffer >> value;
    }
  return (value);
}

void	Pokemon::aff_evo()
{
  int	i = 0;
  while (this->evolution[i] != "")
    {
      std::cout << this->evolution[i] << std::endl;
      ++i;
    }
}

void	Pokemon::setSpecies()
{
  std::string to_find;
  to_find = "<species>";
  std::size_t found = xml.find(to_find);
  if (found != std::string::npos)
    {
      found += 9;
      while (xml[found] != '<')
	this->species += xml[found++];
    }
  else
    {
      this->species = "";
      std::cout << to_find << " not found in pokedata.xml" << std::endl;
      return;
    }
}

void	Pokemon::setEvolution()
{
  std::string to_find;
  to_find = "<evolution id=";
  std::size_t found = 0;
  std::string	*evo = new std::string [20];
  int		i = 0;
  while ((found = xml.find(to_find, found)))
    {
      if (found != std::string::npos)
	{
	  found = xml.find("<name>", found);
	  if (found != std::string::npos)
	    {
	      found+= 6;
	      while (xml[found] != '<')
		evo[i] += xml[found++];
	      if (i != 0)
		{
		  found = xml.find("<lvl>", found);
		  if (found != std::string::npos)
		    {
		      found+= 5;
		      evo[i] += " at level ";
		      while (xml[found] != '<')
			evo[i] += xml[found++];
		    }
		}
	    }
	}
      else
	{
	  evo[i] = "";
	  this->evolution = evo;
	  return;
	}
      ++i;
    }
    this->evolution = evo;
}

void Pokemon::getPokemonXml(std::string const &xml)
{
  std::string nb;
  std::stringstream convert;
  std::stringstream convert2;
  convert << this->ID;
  nb = convert.str();
  std::string to_find;
  std::string to_find2;
  to_find = "pokemon id='";
  to_find += nb;
  to_find += "'>";
  std::size_t found1 = xml.find(to_find);
  to_find2 = "pokemon id='";
  std::size_t found2 = xml.find(to_find2, found1 + 3);
  this->xml = xml.substr(found1, found2 - found1);
}

int	Pokemon::setStats(std::string const &stat)
{
  std::string to_find;
  to_find = stat;
  std::string HP;
  std::size_t found = xml.find(to_find);
  int value = 0;
  if (found != std::string::npos)
    {
      found += stat.length();
      while (xml[found] != '<')
	HP += xml[found++];
      std::istringstream buffer(HP);
      buffer >> value;
    }
  return (value);
}

void	Pokemon::setType()
{
  std::string to_find;
  to_find = "<type>";
  std::size_t found = xml.find(to_find);
  if (found != std::string::npos)
    {
      found += 6;
      while (xml[found] != '<')
	this->type += xml[found++];
      found = xml.find(to_find, found);
      if (found != std::string::npos)
	{
	  found += 6;
	  while (xml[found] != '<')
	    this->typesec += xml[found++];
	}
      else
	this->typesec = "";
    }
  else
    {
      this->type = "";
      this->typesec = "";
      std::cout << to_find << " not found in pokedata.xml" << std::endl;
      return;
    }
}

void	Pokemon::setName()
{
  std::string to_find;
  to_find = "<name>";
  std::size_t found = xml.find(to_find);
  std::string pokemon;
  if (found != std::string::npos)
    {
      found += 6;
      while (xml[found] != '<')
	pokemon += xml[found++];
    }
  else
    {
      this->name = "";
      std::cout << to_find << " not found in pokedata.xml" << std::endl;
      return;
    }
  this->name = pokemon;
}

void	Pokemon::aff_abilities()
{
  int	i = 0;
  while (this->ability[i] != "")
    {
      std::cout << this->ability[i] << std::endl;
      ++i;
    }
}

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(int id, std::string const &xml)
{
  this->ID = id;
  this->getPokemonXml(xml);
  setName();
  setType();
  this->HP = setStats("<HP>");
  this->ATK = setStats("<ATK>");
  this->DEF = setStats("<DEF>");
  this-> SPD = setStats("<SPD>");
  this-> SAT = setStats("<SAT>");
  this-> SDF = setStats("<SDF>");
  this->setEvolution();
  this->setSpecies();
  this->height = this->setCorpse("<height>");
  this->weight = this->setCorpse("<weight>");
  this->setDescription();
  this->setAbility();
  //  this->aff_evo();
  //  this->aff_abilities();
}

Pokemon::~Pokemon()
{
  
  std::cout << this->name << " of type "<< this->type <<  " " << this->typesec << " and species " << this->species << " with " << this->HP << "HP " << this->ATK << "ATK " << this->DEF << "DEF " << this->SPD << "SPD " << this->SAT << "SAT " << this->SDF << "SDF" << " has been slain! pew pew HEADSHOT! CREAMFREASH" << std::endl;
  std::cout << "He was " << this->height << " tall and weights " << this->weight << " Lbs." << std::endl;
  std::cout << this->description << std::endl;
  if (this->evolution != NULL)
    delete []this->evolution;
  if (this->ability != NULL)
  delete []this->ability;
}
