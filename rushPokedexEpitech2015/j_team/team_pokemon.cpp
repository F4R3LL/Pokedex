//
// pokemon.cpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 13:54:09 2015 Julien Selaries
// Last update Sat Jan 24 14:37:22 2015 Julien Selaries
//

#include	<iostream>
#include	"pokemon.hpp"

Pokemon::Pokemon()
{
  this->stats = new t_stat;
  this->details = new t_detail;
  this->moves = new t_move;

  this->stats->ev_HP = 0;
  this->stats->ev_Atk = 0;
  this->stats->ev_Def = 0;
  this->stats->ev_SpA = 0;
  this->stats->ev_SpD = 0;
  this->stats->ev_Spe = 0;
  this->details = NULL;
  this->moves = NULL;

  std::cout << "built" << std::endl;
}

Pokemon::~Pokemon()
{
  if (this->stats != NULL)
    delete this->stats;
  if (this->details != NULL)
    delete this->details;
  if (this->moves != NULL)
    delete this->moves;

  std::cout << "destroyed" << std::endl;
}

t_stat		*Pokemon::getStats()
{
  return (this->stats);
}

t_detail	*Pokemon::getDetails()
{
  return (this->details);
}

t_move		*Pokemon::getMoves()
{
  return (this->moves);
}

//
// Stats
//

void		Pokemon::setHP(unsigned int HP)
{
  this->stats->HP = HP;
}

void		Pokemon::setAtk(unsigned int Atk)
{
  this->stats->Atk = Atk;
}

void		Pokemon::setDef(unsigned int Def)
{
  this->stats->Def = Def;
}

void		Pokemon::setSpA(unsigned int SpA)
{
  this->stats->SpA = SpA;
}

void		Pokemon::setSpD(unsigned int SpD)
{
  this->stats->SpD = SpD;
}

void		Pokemon::setSpe(unsigned int Spe)
{
  this->stats->Spe = Spe;
}


void		Pokemon::set_ev_HP(unsigned int HP)
{
  this->stats->HP = HP;
}

void		Pokemon::set_ev_Atk(unsigned int Atk)
{
  this->stats->Atk = Atk;
}

void		Pokemon::set_ev_Def(unsigned int Def)
{
  this->stats->Def = Def;
}

void		Pokemon::set_ev_SpA(unsigned int SpA)
{
  this->stats->SpA = SpA;
}

void		Pokemon::set_ev_SpD(unsigned int SpD)
{
  this->stats->SpD = SpD;
}

void		Pokemon::set_ev_Spe(unsigned int Spe)
{
  this->stats->Spe = Spe;
}


void		Pokemon::setStats(t_stat *stats)
{
  this->stats = stats;
}

//
// !Stats
//

void		Pokemon::setDetails(t_detail *details)
{
  this->details = details;
}

void		Pokemon::setMoves(t_move *moves)
{
  this->moves = moves;
}
