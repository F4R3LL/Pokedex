//
// aff_list.hh for  in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Thu Jan 22 20:00:51 2015 Tristan Roby
// Last update Sun Jan 25 14:45:54 2015 Filipe Da Silva
//

#ifndef AFF_LIST_HH_
# define AFF_LIST_HH_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class affList
{
public:
  affList(std::string *PokemonName);
  ~affList();
  sf::Sprite getSpriteImg() const;
  sf::Sprite getSpriteSelect() const;
  sf::Sprite getStatSprite() const;
  sf::Sprite getStatRightSprite() const;
  sf::Sprite getSpriteRight() const;
  sf::Sprite getSpriteFond() const;
  sf::Text   getText() const;
  void	     lafonctionquivaaffichertoussa(int i, int pos);
  void		my_aff_selected(sf::RenderWindow &window, affList &a, int i, int j);
private:
  void		setAll();
  std::string	*PokemonName;
  sf::Sprite	imgPokemon;
  sf::Texture	texPokemon;
  sf::Text	Text;
  sf::Texture	select;
  sf::Font	myFont;
  sf::Texture	fond;
  sf::Sprite	fondsprite;
  sf::Texture	rightlist;
  sf::Sprite	rightlistsprite;
  sf::Sprite	selectsprite;
  sf::Texture	stat;
  sf::Sprite	statsprite;
  sf::Sprite	statrightsprite;
};

#endif
