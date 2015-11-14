#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtk3opeenrijmenudialog.h"

#include "k3opeenrijmenudialog.h"
#include "qtaboutdialog.h"
#include "qtconnectthreegamedialog.h"
#include "qtconnectthreewidget.h"
#include "qtk3opeenrijresources.h"
#include "qtk3opeenrijinstructionsdialog.h"
#include "testtimer.h"
#include "qtk3opeenrijselectplayerwidget.h"
#include "ui_qtk3opeenrijmenudialog.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::koer::QtK3OpEenRijMenuDialog::QtK3OpEenRijMenuDialog(
  const QtK3OpEenRijResources& resources,
  QWidget *parent
) noexcept : QtHideAndShowDialog(parent),
    ui(new Ui::QtK3OpEenRijMenuDialog),
    m_select(new QtK3OpEenRijSelectPlayerWidget(resources,this)),
    m_resources{resources}
{
  #ifndef NDEBUG
  Test();
  #endif

  ui->setupUi(this);
  ui->layout_horizontal->addWidget(m_select);
}

ribi::koer::QtK3OpEenRijMenuDialog::~QtK3OpEenRijMenuDialog() noexcept
{
  delete ui;
}

ribi::con3::Resources ribi::koer::Convert(
  const QtK3OpEenRijResources r,
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
)
{
  return ribi::con3::Resources(
    r.GetComputerFilenames(),
    r.GetComputerGreyFilename(),
    r.GetCss(),
    r.GetEmptyFilename(),
    r.GetIconFilename(),
    r.GetInstructionsGoodFilenames(),
    r.GetInstructionsWrongFilename(),
    r.GetPlayerFilenames(black,blond,red),
    r.GetPlayerGreyFilenames(black,blond,red),
    r.GetQuitText(),
    r.GetWinnerText()
  );
}

void ribi::koer::QtK3OpEenRijMenuDialog::on_button_about_clicked() noexcept
{
  About about = MenuDialog().GetAbout();
  about.AddLibrary("QtConnectThreeWidget version: " + con3::QtConnectThreeWidget::GetVersion());
  QtAboutDialog d(about);
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  this->ShowChild(&d);
}

void ribi::koer::QtK3OpEenRijMenuDialog::on_button_instructions_clicked() noexcept
{
  QtK3OpEenRijInstructionsDialog d;
  this->ShowChild(&d);
}

void ribi::koer::QtK3OpEenRijMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

void ribi::koer::QtK3OpEenRijMenuDialog::on_button_start_clicked() noexcept
{
  //Supply the correct resources, depending on if player 3 chose Kathleen or Josje
  ribi::con3::Resources resources =
    Convert(
      m_resources,
      m_select->GetBlack(),
      m_select->GetBlond(),
      m_select->GetRed()
    )
  ;
  con3::QtGameDialog d(
    resources,
    m_select->GetIsPlayerHuman()
  );
  d.setWindowTitle("K3OpEenRij");
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  ShowChild(&d);
}

#ifndef NDEBUG
void ribi::koer::QtK3OpEenRijMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
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
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
