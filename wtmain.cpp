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

ribi::con3::Resources Convert(const ribi::koer::QtK3OpEenRijResources& r)
{
  return ribi::con3::Resources(
    r.GetComputerFilenames(),
    r.GetComputerGreyFilename(),
    r.GetCss(),
    r.GetEmptyFilename(),
    r.GetIconFilename(),
    r.GetInstructionsGoodFilenames(),
    r.GetInstructionsWrongFilename(),
    r.GetPlayerFilenames(
      ribi::koer::BlackHairedGirl::kristel,
      ribi::koer::BlondeGirl::kathleen,
      ribi::koer::RedHairedGirl::karen
    ),
    r.GetPlayerGreyFilenames(
      ribi::koer::BlackHairedGirl::kristel,
      ribi::koer::BlondeGirl::kathleen,
      ribi::koer::RedHairedGirl::karen
    ),
    r.GetQuitText(),
    r.GetWinnerText()
  );
}


struct K3OpEenRijApplication : public Wt::WApplication
{
  K3OpEenRijApplication(
    const Wt::WEnvironment& env,
    const ribi::koer::QtK3OpEenRijResources& resources)
    : Wt::WApplication(env)
  {
    this->setTitle("K3OpEenRij");
    this->useStyleSheet(resources.GetCss());
    root()->addWidget(new ribi::con3::WtMenuDialog(Convert(resources)));
  }
};

} //namespace ribi

Wt::WApplication * createApplication(const Wt::WEnvironment& env)
{
  ribi::koer::QtK3OpEenRijResources resources;
  return new ribi::K3OpEenRijApplication(env,resources);
}

int main(int argc, char **argv)
{
  ribi::WtAutoConfig::SaveDefaultStylesheet();
  ribi::WtAutoConfig a(argc, argv, createApplication);
  return a.Run();
}

