//
// pokemon.cpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 13:54:09 2015 Julien Selaries
// Last update Sat Jan 24 15:00:22 2015 Julien Selaries
//

#include	<iostream>
#include	"pokemon.hpp"

Team_Pokemon::Team_Pokemon()
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

Team_Pokemon::~Team_Pokemon()
{
  std::cout << "destroyed" << std::endl;
}

t_stat		*Team_Pokemon::getStats()
{
  return (this->stats);
}

t_detail	*Team_Pokemon::getDetails()
{
  return (this->details);
}

t_move		*Team_Pokemon::getMoves()
{
  return (this->moves);
}

//
// Stats
//

void		Team_Pokemon::set_ev_HP(unsigned int HP)
{
  this->stats->HP = HP;
}

void		Team_Pokemon::set_ev_Atk(unsigned int Atk)
{
  this->stats->Atk = Atk;
}

void		Team_Pokemon::set_ev_Def(unsigned int Def)
{
  this->stats->Def = Def;
}

void		Team_Pokemon::set_ev_SpA(unsigned int SpA)
{
  this->stats->SpA = SpA;
}

void		Team_Pokemon::set_ev_SpD(unsigned int SpD)
{
  this->stats->SpD = SpD;
}

void		Team_Pokemon::set_ev_Spe(unsigned int Spe)
{
  this->stats->Spe = Spe;
}


void		Team_Pokemon::setStats(t_stat *stats)
{
  this->stats = stats;
}

//
// !Stats
//

void		Team_Pokemon::setDetails(t_detail *details)
{
  this->details = details;
}

void		Team_Pokemon::setMoves(t_move *moves)
{
  this->moves = moves;
}
