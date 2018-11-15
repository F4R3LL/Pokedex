//
// main.cpp for main in /home/roby_t/perso/test
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Jan 19 18:01:19 2015 Tristan Roby
// Last update Sun Jan 25 18:43:14 2015 Julien Selaries
//

//#include <SFML/Audio.hpp>
#include	<iostream>
#include	<fstream>
#include	<sstream>
#include	"Pokedex.hh"
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

  ash.addPokemonById(0, 25, xml);
  return (0);
}
