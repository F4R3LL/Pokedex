//
// main.cpp for main in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:01:19 2015 Tristan Roby
// Last update Sun Jan 25 21:26:48 2015 Julien Selaries
//

//#include <SFML/Audio.hpp>
#include	<iostream>
#include	<fstream>
#include	<sstream>
#include	"Pokedex.hh"
#include	"Pokeplus.hh"
#include	"Team.hh"

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

int	main()
{
  Pokedex	pok;
  std::string xml;
  int		i = 1;

  if ((xml = my_read_from_xml(xml)) == "")
    return (-1);
  while (i != 494)
    pok.getPokemonNameList(xml, i++);
  
  Team		ash;

  /*ash.addPokemon(25, xml);
  ash.addPokemon(42, xml);
  ash.addPokemon(13, xml);
  ash.addPokemon(16, xml);
  ash.addPokemon(1, xml);
  ash.addPokemon(3, xml);
  ash.SaveTeam("lol");*/
  ash.GetTeam("lol", xml);
  std::cout << "atk " << ash.tab_pokemon.front()->getIvAtk() << std::endl;
  std::cout << "hp  " << ash.tab_pokemon.front()->getIvHP() << std::endl;
  std::cout << ash.tab_pokemon.front()->pokemon.name << std::endl;
  std::cout << "atk " << ash.tab_pokemon.back()->getIvAtk() << std::endl;
  std::cout << "hp  " << ash.tab_pokemon.back()->getIvHP() << std::endl;
  std::cout << ash.tab_pokemon.back()->pokemon.name << std::endl;
  return (0);
}
