#pragma GCC diagnostic push

#include "qtk3opeenrijinstructionsdialog.h"
#include "ui_qtk3opeenrijinstructionsdialog.h"
#pragma GCC diagnostic pop

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
