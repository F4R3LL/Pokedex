//
// giveUName.cpp for  in /home/roby_t/rendu/cpp_pokedex/rush-pok-mon-2015
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Sun Jan 25 16:30:06 2015 Tristan Roby
// Last update Sun Jan 25 20:23:21 2015 Tristan Roby
//

#include "aff_list.hh"

# define LEVRETTE 540, 340

std::string  const giveUName(sf::RenderWindow &window)
{
  char		name[11];
  std::string	buff("");
 int		i = 0;
  sf::Texture	BlazeT;
  sf::Sprite	BlazeS;
  sf::Font	font;
  sf::Text	Blaze;

  while(i != 12)
    name[i++] = 0;
  i = 0;
  if (!(font.loadFromFile("ressources/pokemonfont.ttf")))
    std::cout << "olalala" << std::endl;
  if (!(BlazeT.loadFromFile("ressources/images/blaze.jpg")))
    std::cout << "olalala" << std::endl;
  BlazeS.setTexture(BlazeT);
  Blaze.setFont(font);
  Blaze.setColor(sf::Color::Black);
  Blaze.setCharacterSize(22);
  Blaze.setPosition(LEVRETTE);
  window.clear();
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::TextEntered)
	    {
	      if (event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
		  event.text.unicode >= 'a' && event.text.unicode <= 'z')
		{
		  if (i < 10)
		    {
		      name[i] = (event.text.unicode);
		      ++i;
		    }
		}
	      if (event.text.unicode == '\b')
		{
		  --i;
		  if (i < 0)
		    i = 0;
		  name[i] = 0;
		}
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && i > 0)
	    return buff;
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    return buff;
	}
      buff = name;
      Blaze.setString(buff);
      window.clear();
      window.draw(BlazeS);
      window.draw(Blaze);
      window.display();
    }
}
