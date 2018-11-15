//
// PokedexText.cpp for PokedexText.cpp in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Jan 23 14:27:10 2015 Tristan Roby
// Last update Sun Jan 25 14:27:19 2015 Filipe Da Silva
//

#include <sstream>
#include "PokedexText.hpp"
#include "Pokedex.hh"
#include "Pokemon.hh"
#include "aff_list.hh"
#include <cstdlib>

PokedexText::PokedexText(Pokemon *info, std::string *list)
{
  this->info = info;
  this->list = list;
  if (!this->myFont.loadFromFile("ressources/pokemonfont.ttf"))
    std::cout << "olalala" << std::endl;
  setName();
  setSpecies();
  setDescription();
  setTypes();
  setStats();
  setMensuration();
  setEvolution();
  setMove();
}

PokedexText::~PokedexText() {}

bool	PokedexText::getStatus() const
{
  return (this->aff);
}

void	PokedexText::setName()
{
  this->name.setCharacterSize(24);
  this->name.setFont(this->myFont);
  this->name.setColor(sf::Color::Black);
  this->name.setString(this->info->name);
  this->name.setStyle(sf::Text::Underlined);
  this->name.setPosition(40, 55);
  this->aff = true;
}

void	PokedexText::setSpecies()
{
  this->species.setCharacterSize(12);
  this->species.setFont(this->myFont);
  this->species.setColor(sf::Color::Black);
  this->species.setString(this->info->species);
  this->species.setPosition(40, 127);
}

void	PokedexText::setDescription()
{
  std::string	buffer = this->info->description;
  size_t	found;
  int		i = 1;
  while (found != std::string::npos)
    {
      found = buffer.find(" ", 20 * i);
      buffer[found] = '\n';
      ++i;
    }
  this->description.setCharacterSize(FSIZE);
  this->description.setFont(this->myFont);
  this->description.setColor(sf::Color::Black);
  this->description.setString(buffer);
  this->description.setPosition(50, 197);
}

void	PokedexText::setTypes()
{
  std::string buff = this->info->type;

  if (this->info->typesec != "")
    buff += " " + this->info->typesec;
  this->types.setCharacterSize(FSIZE);
  this->types.setFont(this->myFont);
  this->types.setColor(sf::Color::Black);
  this->types.setString(buff);
  this->types.setStyle(sf::Text::Underlined);
  this->types.setPosition(528 + 160 - ((FSIZE/2) * buff.size()), 60);  
}

void	PokedexText::setStats()
{
  std::string buff;
  std::stringstream	ss;

  this->Stats.setCharacterSize(FSIZE);
  this->Stats.setFont(this->myFont);
  this->Stats.setColor(sf::Color::Black);
  ss << this->info->HP;
  buff = "HP  : " + ss.str() + "\n\n";
  ss.str("");
  ss << this->info->ATK;
  buff += "ATK : " + ss.str() + "\n\n";
  ss.str("");
  ss << this->info->DEF;
  buff += "DEF : " + ss.str() + "\n\n";
  ss.str("");
    ss << this->info->SAT;
  buff += "SAT : " + ss.str() + "\n\n";
  ss.str("");
    ss << this->info->SDF;
  buff += "SDF : " + ss.str() + "\n\n";
  ss.str("");
    ss << this->info->SPD;
  buff += "SPD : " + ss.str();
  this->Stats.setString(buff);
  this->Stats.setPosition(617, 120);
}

void	PokedexText::setMensuration()
{
  std::string buff;
  std::stringstream	ss;

  ss << this->info->height;
  buff = "Height : " + ss.str() + "\n\n\n\n";
  ss.str("");
  ss << this->info->weight;
  buff += "Weight : " + ss.str();
  this->mensuration.setCharacterSize(FSIZE);
  this->mensuration.setFont(this->myFont);
  this->mensuration.setColor(sf::Color::Black);
  this->mensuration.setString(buff);
  this->mensuration.setPosition(290, 68);
}

void		PokedexText::setEvolution()
{
  int		i = 0;
  int		j = 492;
  int		fup = 0;
  std::string	img;
  std::stringstream	ss;

    if (info->evolution[1] != "")
    {
      while (info->evolution[i] != "")
	{
	  fup = 0;
	  while (info->evolution[i][fup] != 0)
	    info->evolution[i][fup] = toupper(info->evolution[i][fup++]);
	  while (j != 0 && info->evolution[i].compare(0, this->list[j].size(), this->list[j]) != 0)
	    --j;
	  ss << j + 1;
	  std::string str = ss.str();
	  img = "ressources/sprites/" + str + ".png";
	  ss.str("");
	  if (!this->tEvo[i].loadFromFile(img))
	    std::cout << "Olalalala" << std::endl;
	  this->tEvo[i].setSmooth(true);
	  this->sEvo[i].setTexture(this->tEvo[i]);
	  this->sEvo[i].setPosition(100 + 100 * i, 630);
	  i++;
	  j = 492;
	}
    }
  this->nbEvo = i;
}

void		PokedexText::setMove()
{
  int	i = 0;

  while (this->info->ability[i] != "")
    {
      this->move[i].setCharacterSize(12);
      this->move[i].setFont(this->myFont);
      this->move[i].setColor(sf::Color::White);
      this->move[i].setString(this->info->ability[i]);
      i++;
    }
}

int 		PokedexText::setPosMove(int i)
{
  int		j = -1;

  if (this->info->ability[i] == "")
    i--;
  else
    while (++j != 5)
      this->move[i + j].setPosition(550, 400 + 50 * j);
  return i;
}

sf::Text*	PokedexText::getMove()
{
  return this->move;
}

int		PokedexText::getNbEvo()const
{
  return this->nbEvo;
}

sf::Sprite*	PokedexText::getEvolution()
{
  return this->sEvo;
}

sf::Text	PokedexText::getName()const
{
  return this->name;
}

sf::Text	PokedexText::getSpecies()const
{
  return this->species;
}

sf::Text	PokedexText::getDescription()const
{
  return this->description;
}

sf::Text	PokedexText::getTypes()const
{
  return this->types;
}

sf::Text	PokedexText::getStats()const
{
  return this->Stats;
}

sf::Text	PokedexText::getMensuration()const
{
  return this->mensuration;
}


/*
  this->Text.setCharacterSize(18);
  this->Text.setFont(myFont);
  this->Text.setColor(sf::Color::Black);
*/
