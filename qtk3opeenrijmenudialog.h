#ifndef QTK3OPEENRIJMENUDIALOG_H
#define QTK3OPEENRIJMENUDIALOG_H

#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#include "connectthreeresources.h"
#include "k3opeenrijnames.h"
#pragma GCC diagnostic pop

namespace Ui {
  class QtK3OpEenRijMenuDialog;
}

namespace ribi {
namespace koer {

struct QtK3OpEenRijSelectPlayerWidget;
struct QtK3OpEenRijResources;

class QtK3OpEenRijMenuDialog : public QDialog
{
  Q_OBJECT

public:
  ///Won't throw, as all resources are present
  explicit QtK3OpEenRijMenuDialog(
    const QtK3OpEenRijResources& resources,
    QWidget *parent = 0
  ) noexcept;
  QtK3OpEenRijMenuDialog(const QtK3OpEenRijMenuDialog&) = delete;
  QtK3OpEenRijMenuDialog& operator=(const QtK3OpEenRijMenuDialog&) = delete;
  ~QtK3OpEenRijMenuDialog() noexcept;

private:
  Ui::QtK3OpEenRijMenuDialog *ui;
  QtK3OpEenRijSelectPlayerWidget * m_select;
  const QtK3OpEenRijResources& m_resources;

private slots:

  void on_button_about_clicked() noexcept;
  void on_button_instructions_clicked() noexcept;
  void on_button_quit_clicked() noexcept;
  void on_button_start_clicked() noexcept;
};

ribi::con3::Resources Convert(
  const QtK3OpEenRijResources r,
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
);

} //~namespace koer
} //~namespace ribi

#endif // QTK3OPEENRIJMENUDIALOG_H
