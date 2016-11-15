#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <QApplication>
#include <QIcon>
#include <QFile>
#include <QPixmap>
#include <cassert>
#include "qtk3opeenrijresources.h"
#include "qtk3opeenrijmenudialog.h"
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  const ribi::koer::QtK3OpEenRijResources resources;
  ribi::koer::QtK3OpEenRijMenuDialog w(resources);

  {
    const std::string icon_filename = resources.GetIconFilename();
    assert(QFile::exists(icon_filename.c_str()));
    qApp->setWindowIcon(QIcon(QPixmap(icon_filename.c_str())));
    w.setWindowIcon(QIcon(QPixmap(icon_filename.c_str())));
  }

  w.show();
  return a.exec();
}
