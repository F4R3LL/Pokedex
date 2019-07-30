//
// main.cpp for main in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:01:19 2015 Tristan Roby
// Last update Sun Jan 25 23:30:34 2015 Tristan Roby
//

#include <SFML/Audio.hpp>
#include "Pokedex.hh"
#include "buildTeam.hpp"
#include "Pokemon.hh"
#include "aff_list.hh"
#include "PokedexText.hpp"

std::string const  giveUName(sf::RenderWindow &);

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

int	DisplayPokedex(sf::RenderWindow & window, int from)
{
  Pokedex	pok;
  std::string xml;
  int		i = 1;
  int		j = 0;
  if ((xml = my_read_from_xml(xml)) == "");
  while (i != 494)
    pok.getPokemonNameList(xml, i++);
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

  if (!scroll.openFromFile("ressources/music/scroll.ogg"))
    std::cout << "olalala" << std::endl;
  if (!My_music.openFromFile("ressources/music/theme.ogg"))
    std::cout << "olalala" << std::endl;
  if (!pressEnter.openFromFile("ressources/music/pressenter.ogg"))
    std::cout << "olalala" << std::endl;
  i = 1;
  scroll.setVolume(100);
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
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    return -1;
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
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	    ++move;
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    --move;
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && from == 1)
	    return (i);
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
}

void	aff_team::my_aff_team(Team &team)
{
  std::stringstream ss;
  std::string	img;
  int	i = 0;
  int	x = 0;
  int	y = 0;  

  if (!this->myFont.loadFromFile("ressources/pokemonfont.ttf"))
    std::cout << "olalala" << std::endl;
  
  while (i != team.getSizeTeam())
    {
      ss.str("");
      ss << team.tab_pokemon.at(i)->pokemon.ID;
      std::string str = ss.str();
      img = "ressources/sprites/" + str + ".png";
      if (!this->Tpokemon[i].loadFromFile(img))
	std::cout << "olalala" << std::endl;
      
      if (x > 1)
	{
	  ++y;
	  x = 0;
	}
      this->Tpokemon[i].setSmooth(true);
      this->Spokemon[i].setTexture(this->Tpokemon[i]);
      this->Spokemon[i].setPosition(105  + (400 * x), 105 + (180 * y));
	
      this->Npokemon[i].setCharacterSize(22);
      this->Npokemon[i].setColor(sf::Color::White);
      std::cout << team.tab_pokemon.at(i)->pokemon.name << std::endl;
      this->Npokemon[i].setString("");
      this->Npokemon[i].setString(team.tab_pokemon.at(i)->pokemon.name);
      this->Npokemon[i].setPosition(185  + (400 * x), 155 + (180 * y));
      this->Npokemon[i].setFont(this->myFont);
      ++x;
      ++i;
    }
}

void	buildTeam(std::string  name, sf::RenderWindow & window, std::string const &xml)
{
  sf::Texture fondtexture;
  sf::Sprite fond;
  int	i = 0;
  int	a = 0;
  int	j = 0;
  aff_team	t;
  Team		team;

  if (team.GetTeam(name, xml) != -1)
    	      t.my_aff_team(team);
  if (!(fondtexture.loadFromFile("ressources/images/teambuilder.jpg")))
    std::cout << "olalala" << std::endl;
  fond.setTexture(fondtexture);
  if (name == "")
    return;
  //  Team		build(name);
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && j != 0)
	    {
	      a =  DisplayPokedex(window, 1);
	      if (a == -1)
		return ;
	      team.addPokemon(a, xml);
	      t.my_aff_team(team);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) && j != 0)
	    {
	      team.deletePokemon(team.getSizeTeam() - 1);
	      t.my_aff_team(team);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && j != 0)
	    {
	      team.SaveTeam(name);
	      return ;
	    }
	  j++;
	}
      window.clear();
      window.draw(fond);
      while (i != team.getSizeTeam())
	{
	  window.draw(t.Spokemon[i]);
	  window.draw(t.Npokemon[i]);
	  ++i;
	}
      i = 0;
      window.display();
    }
}

int	main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Pokedex");
  sf::Texture	mainmenu;
  sf::Sprite	fondmenu;
  sf::Texture	bP;
  sf::Sprite	iP;
  sf::Texture	bT;
  sf::Sprite	iT;
  sf::Music	mainmusique;
  sf::Music	porte;
  std::string xml;
  xml = my_read_from_xml(xml);
  int		i = 0;

  if (!(mainmusique.openFromFile("ressources/music/mainmusique.ogg")))
    std::cout << "olalala" << std::endl;
  if (!(porte.openFromFile("ressources/music/porte.ogg")))
    std::cout << "olalala" << std::endl;
  if (!(mainmenu.loadFromFile("ressources/images/mainmenu.jpg")))
    std::cout << "olalala" << std::endl;
  if (!(bP.loadFromFile("ressources/images/BPS.png")))
    std::cout << "olalala" << std::endl;
  if (!(bT.loadFromFile("ressources/images/BTU.png")))
    std::cout << "olalala" << std::endl;
  mainmusique.setLoop(true);
  mainmusique.play();
  fondmenu.setTexture(mainmenu);
  iP.setTexture(bP);
  iT.setTexture(bT);
  iP.setPosition(140, 550);
  iT.setPosition(740, 550);
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    {
	      if (i == 0)
		{
		  mainmusique.pause();
		  porte.play();
		  DisplayPokedex(window, 0);
		  mainmusique.play();
		}
	      else
		{
		  buildTeam(giveUName(window), window ,xml);
		}
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    {
	      if (i == 0)
		{
		  if (!(bP.loadFromFile("ressources/images/BPU.png")))
		    std::cout << "olalala" << std::endl;
		  if (!(bT.loadFromFile("ressources/images/BTS.png")))
		    std::cout << "olalala" << std::endl;
		  i++;
		}
	      else
		{
		  if (!(bP.loadFromFile("ressources/images/BPS.png")))
		    std::cout << "olalala" << std::endl;
		  if (!(bT.loadFromFile("ressources/images/BTU.png")))
		    std::cout << "olalala" << std::endl;
		  i = 0;
		}
	      iP.setTexture(bP);
	      iT.setTexture(bT);
	    }
	}
      window.clear();
      window.draw(fondmenu);
      window.draw(iP);
      window.draw(iT);
      window.display();
      
      
    }
  return (0);
}
