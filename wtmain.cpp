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

