#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtk3opeenrijselectplayerwidget.h"

#include <cassert>

#include <QMouseEvent>
#include <QPainter>


#include "qtk3opeenrijresources.h"
#pragma GCC diagnostic pop

const int ribi::koer::QtK3OpEenRijSelectPlayerWidget::m_sprite_height = 50;
const int ribi::koer::QtK3OpEenRijSelectPlayerWidget::m_sprite_width  = 50;

ribi::koer::QtK3OpEenRijSelectPlayerWidget::QtK3OpEenRijSelectPlayerWidget(
  const QtK3OpEenRijResources& resources,
  QWidget *parent)
  : QWidget(parent),
    m_black{BlackHairedGirl::marthe},
    m_blond{BlondeGirl::klaasje},
    m_red{RedHairedGirl::hanne},
    m_is_player_human{},
    m_david{resources.GetPlayerFilename(true,BlackHairedGirl::david).c_str()},
    m_david_grey{resources.GetPlayerFilename(false,BlackHairedGirl::david).c_str()},
    m_hanne{resources.GetPlayerFilename(true,RedHairedGirl::hanne).c_str()},
    m_hanne_grey{resources.GetPlayerFilename(false,RedHairedGirl::hanne).c_str()},
    m_josje{resources.GetPlayerFilename(true,BlondeGirl::josje).c_str()},
    m_josje_grey{resources.GetPlayerFilename(false,BlondeGirl::josje).c_str()},
    m_karen{resources.GetPlayerFilename(true,RedHairedGirl::karen).c_str()},
    m_karen_grey{resources.GetPlayerFilename(false,RedHairedGirl::karen).c_str()},
    m_kathleen{resources.GetPlayerFilename(true,BlondeGirl::kathleen).c_str()},
    m_kathleen_grey{resources.GetPlayerFilename(false,BlondeGirl::kathleen).c_str()},
    m_klaasje{resources.GetPlayerFilename(true,BlondeGirl::klaasje).c_str()},
    m_klaasje_grey{resources.GetPlayerFilename(false,BlondeGirl::klaasje).c_str()},
    m_kristel{resources.GetPlayerFilename(true,BlackHairedGirl::kristel).c_str()},
    m_kristel_grey{resources.GetPlayerFilename(false,BlackHairedGirl::kristel).c_str()},
    m_marthe{resources.GetPlayerFilename(true,BlackHairedGirl::marthe).c_str()},
    m_marthe_grey{resources.GetPlayerFilename(false,BlackHairedGirl::marthe).c_str()},
    m_matt{resources.GetPlayerFilename(true,BlondeGirl::matt).c_str()},
    m_matt_grey{resources.GetPlayerFilename(false,BlondeGirl::matt).c_str()},
    m_tyler{resources.GetPlayerFilename(true,RedHairedGirl::tyler).c_str()},
    m_tyler_grey{resources.GetPlayerFilename(false,RedHairedGirl::tyler).c_str()},
    m_computer1(resources.GetComputerFilename(0).c_str()),
    m_computer2(resources.GetComputerFilename(1).c_str()),
    m_computer3(resources.GetComputerFilename(2).c_str()),
    m_computer_grey(resources.GetComputerGreyFilename().c_str())
{
  m_is_player_human[0] = true;
  m_is_player_human[1] = true;
  m_is_player_human[2] = true;


  this->setMinimumWidth( 3 * m_sprite_width );
  this->setMinimumHeight(3 * m_sprite_height);
  this->setMaximumWidth( 3 * m_sprite_width );
  this->setMaximumHeight(3 * m_sprite_height);
}

const QImage& ribi::koer::QtK3OpEenRijSelectPlayerWidget::GetImage(const bool is_human,const BlackHairedGirl girl) const noexcept
{
  switch (girl)
  {
    case BlackHairedGirl::kristel: return is_human ? m_kristel : m_kristel_grey;
    case BlackHairedGirl::marthe: return is_human ? m_marthe : m_marthe_grey;
    case BlackHairedGirl::david: return is_human ? m_david : m_david_grey;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl image");
}

const QImage& ribi::koer::QtK3OpEenRijSelectPlayerWidget::GetImage(const bool is_human,const BlondeGirl girl) const noexcept
{
  switch (girl)
  {
    case BlondeGirl::kathleen: return is_human ? m_kathleen : m_kathleen_grey;
    case BlondeGirl::josje: return is_human ? m_josje : m_josje_grey;
    case BlondeGirl::klaasje: return is_human ? m_klaasje : m_klaasje_grey;
    case BlondeGirl::matt: return is_human ? m_matt : m_matt_grey;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl image");
}

const QImage& ribi::koer::QtK3OpEenRijSelectPlayerWidget::GetImage(const bool is_human,const RedHairedGirl girl) const noexcept
{
  switch (girl)
  {
    case RedHairedGirl::karen: return is_human ? m_karen : m_karen_grey;
    case RedHairedGirl::hanne: return is_human ? m_hanne : m_hanne_grey;
    case RedHairedGirl::tyler: return is_human ? m_tyler : m_tyler_grey;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl image");
}

void ribi::koer::QtK3OpEenRijSelectPlayerWidget::mousePressEvent(QMouseEvent * e)
{
  const int mouse_x = e->x();
  const int mouse_y = e->y();
  const int col_index = mouse_x / m_sprite_width;
  const int row_index = mouse_y / m_sprite_height;
  const bool was_human = m_is_player_human[row_index];
  const bool is_human = col_index == 0;
  m_is_player_human[row_index] = is_human;
  if (row_index == 0 && is_human && was_human) m_red = GetNext(m_red);
  if (row_index == 1 && is_human && was_human) m_black = GetNext(m_black);
  if (row_index == 2 && is_human && was_human) m_blond = GetNext(m_blond);
  this->repaint();
}

void ribi::koer::QtK3OpEenRijSelectPlayerWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.drawImage(
    0 * m_sprite_width,
    0 * m_sprite_height,
    GetImage(m_is_player_human[0],m_red)
  );
  painter.drawImage(
    0 * m_sprite_width,
    1 * m_sprite_height,
    GetImage(m_is_player_human[1],m_black)
  );
  painter.drawImage(
    0 * m_sprite_width,
    2 * m_sprite_height,
    GetImage(m_is_player_human[2],m_blond)
  );

  painter.drawImage(1 * m_sprite_width,0 * m_sprite_height,m_is_player_human[0] ? m_computer_grey : m_computer1);
  painter.drawImage(1 * m_sprite_width,1 * m_sprite_height,m_is_player_human[1] ? m_computer_grey : m_computer2);
  painter.drawImage(1 * m_sprite_width,2 * m_sprite_height,m_is_player_human[2] ? m_computer_grey : m_computer3);
}

