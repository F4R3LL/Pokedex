//
// Team_Pokemon.cpp for piscine in /home/selari_j/rendu/rush03_pool/s_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 17:15:29 2015 Julien Selaries
// Last update Sun Jan 25 18:21:51 2015 Julien Selaries
//

#include	<ctime>
#include	<cstdlib>
#include	<iostream>
#include	<fstream>
#include	"Team_Pokemon.hh"

static int	get_random(int limit)
{
  srand(time(0));

  return (rand() % limit);
}

Team_Pokemon::Team_Pokemon()
{
  //  this->pokemon = new Pokemon [SIZE_TEAM];
  this->ev = new t_ev;
  this->iv = new t_iv; 
  this->pokemon = new Pokemon;

  this->ev->HP = 0;
  this->ev->Atk = 0;
  this->ev->Def = 0;
  this->ev->SpA = 0;
  this->ev->SpD = 0;
  this->ev->Spe = 0;
  
  this->hapiness = 0;

  setRandIv();
}

Team_Pokemon::~Team_Pokemon()
{
  delete[] this->ev;
  delete[] this->iv;
  delete this->pokemon;
}

void		Team_Pokemon::setSizeTeam(int value)
{
  this->size_team = value;
}

int		Team_Pokemon::getSizeTeam()
{
  return (this->size_team);
}

void		Team_Pokemon::setRandIv()
{
  this->iv->HP = get_random(31);
  this->iv->Atk = get_random(31);
  this->iv->Def = get_random(31);
  this->iv->SpA = get_random(31);
  this->iv->SpD = get_random(31);
  this->iv->Spe = get_random(31);
}

int		Team_Pokemon::getHapiness()
{
  return (this->hapiness);
}

void		Team_Pokemon::setHapiness(int value)
{
  if (value < 0 ||
      value > 255)
    this->hapiness = value;
}

int		Team_Pokemon::getPokemonId()
{
  return (this->pokemon->ID);
}

/*
** IVs
*/

int		Team_Pokemon::setIvHP(int value)
{
  if (this->iv->HP += value > 31)
    this->iv->HP = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::setIvAtk(int value)
{
  if (this->iv->Atk += value > 31)
    this->iv->Atk = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::setIvDef(int value)
{
  if (this->iv->Def += value > 31)
    this->iv->Def = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::setIvSpA(int value)
{
  if (this->iv->SpA += value > 31)
    this->iv->SpA = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::setIvSpD(int value)
{
  if (this->iv->SpD += value > 31)
    this->iv->SpD = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::setIvSpe(int value)
{
  if (this->iv->Spe += value > 31)
    this->iv->Spe = value;
  else
    return (-1);
  return (0);
}

int		Team_Pokemon::getIvHP()
{
  return (this->iv->HP);
}

int		Team_Pokemon::getIvAtk()
{
  return (this->iv->Atk);
}

int		Team_Pokemon::getIvDef()
{
  return (this->iv->Def);
}

int		Team_Pokemon::getIvSpA()
{
  return (this->iv->SpA);
}

int		Team_Pokemon::getIvSpD()
{
  return (this->iv->SpD);
}

int		Team_Pokemon::getIvSpe()
{
  return (this->iv->Spe);
}

/*
** EVs
*/

int		Team_Pokemon::getAllEv()
{
  return (this->ev->HP +
	  this->ev->Atk +
	  this->ev->Def +
	  this->ev->SpA +
	  this->ev->SpD +
	  this->ev->Spe);
}

int		Team_Pokemon::setEvHP(int value)
{
  if ((this->getAllEv() + value) <= 510)
    if (this->ev->HP + value <= 255)
      {
	this->ev->HP += value;
	return (0);
      }
  return (-1);
}

int		Team_Pokemon::setEvAtk(int value)
{
 if ((this->getAllEv() + value) <= 510)
   if (this->ev->Atk + value <= 255)
     {
       this->ev->Atk += value;
       return (0);
     }
 return (-1);
}

int		Team_Pokemon::setEvDef(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->Def + value <= 255)
    {
      this->ev->Def += value;
      return (0);
    }
 return (-1);
}

int		Team_Pokemon::setEvSpA(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->SpA + value <= 255)
    {
      this->ev->SpA += value;
      return (0);
    }
 return (-1);
}

int		Team_Pokemon::setEvSpD(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->SpD + value <= 255)
    {
      this->ev->SpD += value;
      return (0);
    }
 return (-1);
}

int		Team_Pokemon::setEvSpe(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->Spe + value <= 255)
    {
      this->ev->Spe += value;
      return (0);
    }
 return (-1);
}

int		Team_Pokemon::getEvHP()
{
  return (this->ev->HP);
}

int		Team_Pokemon::getEvAtk()
{
  return (this->ev->Atk);
}

int		Team_Pokemon::getEvDef()
{
  return (this->ev->Def);
}

int		Team_Pokemon::getEvSpA()
{
  return (this->ev->SpA);
}

int		Team_Pokemon::getEvSpD()
{
  return (this->ev->SpD);
}

int		Team_Pokemon::getEvSpe()
{
  return (this->ev->Spe);
}

/*
** usefull functions
*/

int		Team_Pokemon::AddPokemonById(unsigned int id, std::string xml)
{
  Pokemon	*new_p = new Pokemon(id, xml);

  this->pokemon = new_p;
  return (0);
}

void		Team_Pokemon::DeletePokemonByPos()
{
  delete this->pokemon;
}
