

#include "qtk3opeenrijinstructionsdialog.h"
#include "ui_qtk3opeenrijinstructionsdialog.h"


ribi::koer::QtK3OpEenRijInstructionsDialog::QtK3OpEenRijInstructionsDialog(QWidget *parent) noexcept
  : QDialog(parent),
    ui(new Ui::QtK3OpEenRijInstructionsDialog)
{
  ui->setupUi(this);
}

ribi::koer::QtK3OpEenRijInstructionsDialog::~QtK3OpEenRijInstructionsDialog() noexcept
{
  delete ui;
}
