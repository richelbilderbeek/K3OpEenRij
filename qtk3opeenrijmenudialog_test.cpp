#include "qtk3opeenrijmenudialog_test.h"

#include "qtk3opeenrijmenudialog.h"
#include "qtk3opeenrijresources.h"
#include <cassert>

/*
void ribi::braw::qtbrainweaverstudentmenudialog_test::has_about()
{
  {
    const ribi::con3::Resources resources;
    con3::QtConnectThreeWidget widget(resources);
    con3::QtGameDialog d(resources,std::bitset<3>(false));
  }
  {
    QtK3OpEenRijInstructionsDialog d;
  }
  {
    About about = MenuDialog().GetAbout();
    QtAboutDialog d(about);
  }
}
*/

void ribi::koer::qtk3opeenrijmenudialog_test::construct()
{
  QtK3OpEenRijMenuDialog d{QtK3OpEenRijResources()};
  d.show();
}
