//
// Team_Pokemon.cpp for piscine in /home/selari_j/rendu/rush03_pool/s_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 17:15:29 2015 Julien Selaries
// Last update Sun Jan 25 20:07:31 2015 Julien Selaries
//

#include	<ctime>
#include	<cstdlib>
#include	<iostream>
#include	<fstream>
#include	"Pokeplus.hh"

static int	get_random(int limit)
{
  srand(time(0));

  return (rand() % limit);
}

Pokeplus::Pokeplus()
{
  this->ev = new t_ev;
  this->iv = new t_iv; 

  this->ev->HP = 0;
  this->ev->Atk = 0;
  this->ev->Def = 0;
  this->ev->SpA = 0;
  this->ev->SpD = 0;
  this->ev->Spe = 0;
  
  this->hapiness = 0;

  setRandIv();
}

Pokeplus::~Pokeplus()
{
  delete[] this->ev;
  delete[] this->iv;
}

void		Pokeplus::setSizeTeam(int value)
{
  this->size_team = value;
}

int		Pokeplus::getSizeTeam()
{
  return (this->size_team);
}

void		Pokeplus::setRandIv()
{
  this->iv->HP = get_random(time(0) % 31);
  this->iv->Atk = get_random(time(0) % 31);
  this->iv->Def = get_random(time(0) % 31);
  this->iv->SpA = get_random(time(0) % 31);
  this->iv->SpD = get_random(time(0) % 31);
  this->iv->Spe = get_random(time(0) % 31);
}

int		Pokeplus::getHapiness()
{
  return (this->hapiness);
}

void		Pokeplus::setHapiness(int value)
{
  if (value < 0 ||
      value > 255)
    this->hapiness = value;
}

int		Pokeplus::getPokemonId()
{
  return (this->pokemon.ID);
}

/*
** IVs
*/

int		Pokeplus::setIvHP(int value)
{
  if (this->iv->HP += value > 31)
    this->iv->HP = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::setIvAtk(int value)
{
  if (this->iv->Atk += value > 31)
    this->iv->Atk = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::setIvDef(int value)
{
  if (this->iv->Def += value > 31)
    this->iv->Def = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::setIvSpA(int value)
{
  if (this->iv->SpA += value > 31)
    this->iv->SpA = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::setIvSpD(int value)
{
  if (this->iv->SpD += value > 31)
    this->iv->SpD = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::setIvSpe(int value)
{
  if (this->iv->Spe += value > 31)
    this->iv->Spe = value;
  else
    return (-1);
  return (0);
}

int		Pokeplus::getIvHP()
{
  return (this->iv->HP);
}

int		Pokeplus::getIvAtk()
{
  return (this->iv->Atk);
}

int		Pokeplus::getIvDef()
{
  return (this->iv->Def);
}

int		Pokeplus::getIvSpA()
{
  return (this->iv->SpA);
}

int		Pokeplus::getIvSpD()
{
  return (this->iv->SpD);
}

int		Pokeplus::getIvSpe()
{
  return (this->iv->Spe);
}

/*
** EVs
*/

int		Pokeplus::getAllEv()
{
  return (this->ev->HP +
	  this->ev->Atk +
	  this->ev->Def +
	  this->ev->SpA +
	  this->ev->SpD +
	  this->ev->Spe);
}

int		Pokeplus::setEvHP(int value)
{
  if ((this->getAllEv() + value) <= 510)
    if (this->ev->HP + value <= 255)
      {
	this->ev->HP += value;
	return (0);
      }
  return (-1);
}

int		Pokeplus::setEvAtk(int value)
{
 if ((this->getAllEv() + value) <= 510)
   if (this->ev->Atk + value <= 255)
     {
       this->ev->Atk += value;
       return (0);
     }
 return (-1);
}

int		Pokeplus::setEvDef(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->Def + value <= 255)
    {
      this->ev->Def += value;
      return (0);
    }
 return (-1);
}

int		Pokeplus::setEvSpA(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->SpA + value <= 255)
    {
      this->ev->SpA += value;
      return (0);
    }
 return (-1);
}

int		Pokeplus::setEvSpD(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->SpD + value <= 255)
    {
      this->ev->SpD += value;
      return (0);
    }
 return (-1);
}

int		Pokeplus::setEvSpe(int value)
{
 if ((this->getAllEv() + value) <= 510)
  if (this->ev->Spe + value <= 255)
    {
      this->ev->Spe += value;
      return (0);
    }
 return (-1);
}

int		Pokeplus::getEvHP()
{
  return (this->ev->HP);
}

int		Pokeplus::getEvAtk()
{
  return (this->ev->Atk);
}

int		Pokeplus::getEvDef()
{
  return (this->ev->Def);
}

int		Pokeplus::getEvSpA()
{
  return (this->ev->SpA);
}

int		Pokeplus::getEvSpD()
{
  return (this->ev->SpD);
}

int		Pokeplus::getEvSpe()
{
  return (this->ev->Spe);
}

int		Pokeplus::setPokemon(int id, std::string xml)
{
  Pokemon	*new_p = new Pokemon(id, xml);

  this->pokemon = *new_p;
  return (0);
}

void		Pokeplus::deletePokemon()
{
  
}
