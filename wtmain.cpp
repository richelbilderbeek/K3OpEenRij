//---------------------------------------------------------------------------
/*
K3-Op-Een-Rij. A simple game.
Copyright (C) 2007-2014 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameK3OpEenRij.htm
//---------------------------------------------------------------------------
#include <exception>
#include <iostream>

#include <Wt/WApplication>
#include <Wt/WEnvironment>

#include "wtautoconfig.h"

#include "connectthreeresources.h"
#include "wtconnectthreemenudialog.h"
#include "qtk3opeenrijresources.h"
#include "about.h"
#include "connectthreegame.h"
#include "wtaboutdialog.h"
#include "wtconnectthreewidget.h"

namespace ribi {

struct K3OpEenRijApplication : public Wt::WApplication
{
  K3OpEenRijApplication(
    const Wt::WEnvironment& env,
    const ribi::con3::Resources& resources)
    : Wt::WApplication(env)
  {
    this->setTitle("K3OpEenRij");
    this->useStyleSheet(resources.GetCss());
    root()->addWidget(new ribi::con3::WtMenuDialog(resources));
  }
};

} //namespace ribi

Wt::WApplication * createApplication(const Wt::WEnvironment& env)
{
  ribi::con3::Resources resources;
  return new ribi::K3OpEenRijApplication(env,resources);
}

int main(int argc, char **argv)
{
  ribi::WtAutoConfig::SaveDefaultStylesheet();
  ribi::WtAutoConfig a(argc,argv,createApplication);
  return a.Run();
}

