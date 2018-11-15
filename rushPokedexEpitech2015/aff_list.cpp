//
// aff_list.cpp for  in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Thu Jan 22 20:04:59 2015 Tristan Roby
// Last update Sun Jan 25 14:48:42 2015 Filipe Da Silva
//

#include "aff_list.hh"

affList::affList(std::string *PokemonName)
{
  this->PokemonName = PokemonName;
  this->setAll();
}

affList::~affList(){}

sf::Text	affList::getText() const
{
  return (this->Text);
}

sf::Sprite	affList::getSpriteSelect() const
{
  return (this->selectsprite);
}

sf::Sprite	affList::getStatRightSprite() const
{
  return (this->statrightsprite);
}

sf::Sprite	affList::getStatSprite() const
{
  return (this->statsprite);
}

sf::Sprite	affList::getSpriteRight() const
{
  return (this->rightlistsprite);
}

sf::Sprite	affList::getSpriteFond() const
{
  return (this->fondsprite);
}

sf::Sprite	affList::getSpriteImg() const
{
  return (this->imgPokemon);
}

void	affList::setAll()
{
  if (!this->select.loadFromFile("ressources/images/ceinture.png"))  
    std::cout << "olalala" << std::endl;
  if (!this->myFont.loadFromFile("ressources/pokemonfont.ttf"))
    std::cout << "olalala" << std::endl;
  this->select.setSmooth(true);
  this->selectsprite.setTexture(this->select);
  this->selectsprite.setPosition(1280-405, 180);
  if (!this->fond.loadFromFile("ressources/images/fond.jpg"))
    std::cout << "olalala" << std::endl;
  this->fondsprite.setTexture(this->fond);
  if (!this->rightlist.loadFromFile("ressources/images/Pokedex2.jpg"))
    std::cout << "olalala" << std::endl;
  this->rightlist.setSmooth(true);
  this->rightlistsprite.setTexture(this->rightlist);
  this->rightlistsprite.setPosition(1280-405, 0);
  this->Text.setCharacterSize(18);
  this->Text.setFont(myFont);
  this->Text.setColor(sf::Color::Black);
}


void affList::lafonctionquivaaffichertoussa(int i, int pos)
{
  std::stringstream ss;
  std::string	img;

  if (i + pos > 493)
    i -= 493;
  if (i + pos == 0)
    i = 493;
  ss << i + pos;
  std::string str = ss.str();
  img = "ressources/sprites/" + str + ".png";
  if (!this->texPokemon.loadFromFile(img))
    std::cout << "olalala" << std::endl;

this->texPokemon.setSmooth(true);
  this->imgPokemon.setTexture(this->texPokemon);
  this->imgPokemon.setPosition(1280-350, 200 + 100 * pos);
this->Text.setString(this->PokemonName[i + pos - 1]);
this->Text.setPosition(1280 - 220, 230 + 100 * pos);
}

void	affList::my_aff_selected(sf::RenderWindow &window, affList &a, int i, int j)
{
  std::stringstream ss;
  std::stringstream ss2;
  std::string	img;
  ss << j;
  ss2 << i;
  std::string str = ss.str();
  img = "ressources/gif/" + ss2.str() + "/" + ss2.str() + ".gif/" +  ss2.str() + "-" + str +".png";
  if (!this->texPokemon.loadFromFile(img))
    std::cout << "olalala" << std::endl;
  this->texPokemon.setSmooth(true);
  this->imgPokemon.setTexture(this->texPokemon, true);
  this->imgPokemon.setScale(1.5, 1.5);
  sf::Rect<int> r;

  r = imgPokemon.getTextureRect();

  this->imgPokemon.setPosition(350 - r.width/2, 450 - r.height/2);
  if (!this->stat.loadFromFile("ressources/images/stats.png"))
    std::cout << "olalala" << std::endl;
   this->stat.setSmooth(true);
   this->statsprite.setTexture(this->stat);
   this->statsprite.setScale(1.5, 1);
   this->statsprite.setPosition(20, 20);
   this->statrightsprite.setTexture(this->stat);
   this->statrightsprite.setScale(1, 2.2);
   this->statrightsprite.setPosition(1280 - 332 - 420, 20);
}

