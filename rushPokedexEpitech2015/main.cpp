//
// main.cpp for main in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:01:19 2015 Tristan Roby
// Last update Sun Jan 25 11:40:56 2015 Filipe Da Silva
//

#include <SFML/Audio.hpp>
#include "Pokedex.hh"
#include "Pokemon.hh"
#include "aff_list.hh"
#include "PokedexText.hpp"

std::string const my_read_from_xml(std::string ret)
{
  std::stringstream	str;
  std::fstream myfile("pokedata.xml");
  if(myfile.is_open())
    {
      str << myfile.rdbuf();
      ret = str.str();
      myfile.close();
      return (ret);
    }
  else
    {
      std::cout << "fstream open error" << std::endl;
      return ("");
    }
}

void	my_aff(affList &a, affList &b, affList &c, affList &d, affList &e, int i)
{
  a.lafonctionquivaaffichertoussa(i, 0);
  b.lafonctionquivaaffichertoussa(i, 1);
  c.lafonctionquivaaffichertoussa(i, 2);
  d.lafonctionquivaaffichertoussa(i, 3);
  e.lafonctionquivaaffichertoussa(i, 4);  
}

void	my_draw(sf::RenderWindow &window, affList &a, affList &b, affList &c, affList &d, affList &e, affList &selected, PokedexText *t, int &move)
{
  int		i = 0;

  window.clear();
  window.draw(a.getSpriteFond());
  window.draw(a.getSpriteRight());
  window.draw(a.getSpriteSelect());
  window.draw(a.getSpriteImg());
  window.draw(a.getText());
  window.draw(b.getText());
  window.draw(c.getText());
  window.draw(d.getText());
  window.draw(e.getText());
  window.draw(b.getSpriteImg());
  window.draw(c.getSpriteImg());
  window.draw(d.getSpriteImg());
  window.draw(e.getSpriteImg());
  window.draw(selected.getSpriteImg());
  window.draw(selected.getStatSprite());
  window.draw(selected.getStatRightSprite());
  if (t != NULL)
    {
      window.draw(t->getName());
      window.draw(t->getSpecies());
      window.draw(t->getDescription());
      window.draw(t->getTypes());
      window.draw(t->getStats());
      window.draw(t->getMensuration());
      while (i != t->getNbEvo())
	window.draw(t->getEvolution()[i++]);
      if (move < 0)
	move = 0;
      if (move > 395)
	move = 395;
      move = t->setPosMove(move);
      window.draw(t->getMove()[move]);
      window.draw(t->getMove()[move + 1]);
      window.draw(t->getMove()[move + 2]);
      window.draw(t->getMove()[move + 3]);
      window.draw(t->getMove()[move + 4]);
    }
  window.display();
}

int	main()
{
  Pokedex	pok;
  std::string xml;
  int		i = 1;
  int		j = 0;
  if ((xml = my_read_from_xml(xml)) == "")
    return (-1);
  while (i != 494)
    pok.getPokemonNameList(xml, i++);
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Pokedex");
  affList	a(pok.pokemonName);
  affList	b(pok.pokemonName);
  affList	c(pok.pokemonName);
  affList	d(pok.pokemonName);
  affList	e(pok.pokemonName);
  affList	selected(pok.pokemonName);
  sf::Music	My_music;
  sf::Music	scroll;
  sf::Music	pressEnter;
  Pokemon	*aff = NULL;
  PokedexText	*pokemontext = NULL;
  int		op = 0;

  if (!scroll.openFromFile("ressources/music/ak47-1.wav"))
    std::cout << "olalala" << std::endl;
  if (!My_music.openFromFile("ressources/music/theme.ogg"))
    std::cout << "olalala" << std::endl;
  if (!pressEnter.openFromFile("ressources/music/pressenter.ogg"))
    std::cout << "olalala" << std::endl;
  i = 1;
  scroll.setVolume(10);
  My_music.setVolume(20);
  pressEnter.setVolume(20);
  pressEnter.play();
  pressEnter.pause();
  scroll.setAttenuation(100);
  pressEnter.setAttenuation(100);
  My_music.play();
  My_music.setLoop(true);
  my_aff(a, b, c, d, e, i); 
  int	move = 0;
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	  {
	    scroll.stop();
	    ++i;
	    my_aff(a, b, c, d, e, i); 
	    if (i > 493)
	      i = 1;
	    scroll.play();
	  }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	  {
	    scroll.stop();
	    --i;
	    my_aff(a, b, c, d, e, i); 
	    if (i <= 0)
	      i = 493;
	    scroll.play();
	  }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    {	    
	      if (aff != NULL)
	      	{
	      	  delete aff;
	      	  delete pokemontext;
	      	}
	      aff = new Pokemon(i, xml);
	      pokemontext = new PokedexText(aff, pok.pokemonName);
	      pressEnter.stop();
	      selected.my_aff_selected(window, selected, i, j);
	      My_music.pause();
	      pressEnter.play();
	      move = 0;
	      op = i;
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	    ++move;
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	    --move;
	}
      ++j;
      if (j == 50)
	j = 0;
      if ((pressEnter.getStatus() != sf::Music::Playing && My_music.getStatus() != sf::Music::Playing))
	My_music.play();
      if (op != 0)
	{
	  selected.my_aff_selected(window, selected, op, j);
	}
      my_draw(window, a, b, c, d, e, selected, pokemontext, move);
  }
  return (0);
}
