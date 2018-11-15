//
// main.cpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 14:18:15 2015 Julien Selaries
// Last update Sat Jan 24 14:35:25 2015 Julien Selaries
//

#include	"pokemon.hpp"

int		main(void)
{
  Pokemon	pikachu;
  t_stat	lol;

  lol.HP = 35;
  lol.Atk = 55;
  lol.Def = 30;
  lol.Spe = 90;
  lol.SpA = 50;
  lol.SpD = 40;

  pikachu.setStats(&lol);
  return (0);
}
