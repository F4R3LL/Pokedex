//
// pokemon.hpp for piscine in /home/selari_j/rendu/rush03_pool/j_team
// 
// Made by Julien Selaries
// Login   <selari_j@epitech.net>
// 
// Started on  Sat Jan 24 12:12:22 2015 Julien Selaries
// Last update Sat Jan 24 15:00:47 2015 Julien Selaries
//

#ifndef		POKEMON_HPP_
# define	POKEMON_HPP_

#include	<string>

typedef struct	s_stat
{
  unsigned int		ev_HP;
  unsigned int		ev_Atk;
  unsigned int		ev_Def;
  unsigned int		ev_SpA;
  unsigned int		ev_SpD;
  unsigned int		ev_Spe;
}		t_stat;

enum	e_gender
  {
    NONE,
    MALE,
    FEMALE
  };

typedef struct	s_detail
{
  e_gender	gender;
  unsigned int 	hapiness;
  unsigned int 	weight;
  unsigned int 	height;
  bool		shiny;
  unsigned int 	level;
  std::string	name;
  std::string	ability;
}		t_detail;

typedef	struct	s_move
{
  std::string	move_1; //transformer en class Move via getter
  std::string	move_2; // le getter check si le pokemon peut apprendre lattaque
  std::string	move_3; // ou via setter
  std::string	move_4;
}		t_move;

class		Team_Pokemon
{
 private:
  t_stat	*stats;
  t_detail	*details;
  t_move	*moves;
  Pokemon	*pokemon;

 public:
  Team_Pokemon();
  ~Team_Pokemon();

  t_stat	*getStats();
  t_detail	*getDetails();
  t_move	*getMoves();

  void		set_ev_HP(unsigned int); //set_ev_ers pour les evs
  void		set_ev_Atk(unsigned int);
  void		set_ev_Def(unsigned int);
  void		set_ev_SpA(unsigned int);
  void		set_ev_SpD(unsigned int);
  void		set_ev_Spe(unsigned int);
  void		setStats(t_stat *stats);

  void		setDetails(t_detail *detail);
  void		setMoves(t_move *moves);

  Pokemon	*getPokemonByName(std::string name);
};

#endif		/* !POKEMON_HPP_ */
