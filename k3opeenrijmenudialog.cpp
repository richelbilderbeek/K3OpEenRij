#include "k3opeenrijmenudialog.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>


#include "connectthreegame.h"
#include "connectthreewidget.h"
#include "qtk3opeenrijresources.h"


#pragma GCC diagnostic pop

int ribi::koer::MenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  using namespace ::ribi::con3;
  #ifndef NDEBUG
  Test();
  #endif

  const int argc = static_cast<int>(argv.size());

  if (argc == 2 && (argv[1] == "-d" || argv[1] == "--demo"))
  {

    //Play a ConnectThreeGame, but change the graphics
    Game c(15,5);
    const std::bitset<3> is_player_human(0);
    while (c.GetWinner() == Winner::no_winner)
    {
      c.DoMove(c.SuggestMove(is_player_human));
      std::stringstream s;
      s << c;
      std::string t { s.str() };
      //Replace
      std::replace(t.begin(),t.end(),'1','K'); //Karen
      std::replace(t.begin(),t.end(),'2','R'); //kRistel
      std::replace(t.begin(),t.end(),'3','J'); //Josje
      std::cout << t << std::endl
        << std::endl;
    }

    switch (c.GetWinner())
    {
      case Winner::player1  : std::cout << "Karen won the game"; break;
      case Winner::player2  : std::cout << "Kristel won the game"; break;
      case Winner::player3  : std::cout << "Josje won the game"; break;
      case Winner::draw     : std::cout << "The game ended in a draw"; break;
      case Winner::no_winner:
        assert(!"Should not get here");
    }

    std::cout << std::endl;
    return 0;
  }
  else
  {
    std::cout << GetHelp() << '\n';
    return 0;
  }
}

ribi::About ribi::koer::MenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "K3OpEenRij",
    "K3-themed connect-three game",
    "the 14th of November 2015",
    "2007-2015",
    "http://www.richelbilderbeek.nl/GameK3OpEenRij.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("ConnectThree version: " + con3::Game::GetVersion());
  a.AddLibrary("ConnectThreeWidget version: " + con3::ConnectThreeWidget::GetVersion());
  a.AddLibrary("Special thanks to Mark Wiering for his excellent bug reports");
  return a;
}

ribi::Help ribi::koer::MenuDialog::GetHelp() const noexcept
{
  return Help(
    GetAbout().GetFileTitle(),
    GetAbout().GetFileDescription(),
    {
      Help::Option('d',"demo","Display a demo game")
    },
    {
      GetAbout().GetFileTitle() + " -d",
      GetAbout().GetFileTitle() + " --demo"
    }
  );
}

std::string ribi::koer::MenuDialog::GetVersion() const noexcept
{
  return "7.0";
}

std::vector<std::string> ribi::koer::MenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2007-01-03: version 3.0: initial C++ Builder verion",
    "2009-12-31: version 4.0: replaced Kathleen by Josje, game arena always visible, made screens smaller, removed useless JPEGs",
    "2013-08-06: version 5.0: port to Qt Creator",
    "2013-08-06: version 5.1: allow selection of both Kathleen and Josje",
    "2013-08-09: version 6.0: implemented suggestions and bugfixes from Mark Wiering's report",
    "2014-01-23: version 6.1: added command line demo",
    "2014-01-30: version 6.2: added extra command line option to display the artists",
    "2015-06-09: version 6.3: show how to choose Kathleen in the menu screen, clean up files when program closes",
    "2015-11-14: version 7.0: moved to own GitHub, added pictures of new K3"
  };
}

#ifndef NDEBUG
void ribi::koer::MenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  ribi::con3::Game c(15,5);
  const std::bitset<3> is_player_human(0);
  while (c.GetWinner() == con3::Winner::no_winner)
  {
    c.DoMove(c.SuggestMove(is_player_human));
  }
}
#endif
