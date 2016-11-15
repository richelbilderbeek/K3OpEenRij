#ifndef QTK3OPEENRIJSELECTPLAYERWIDGET_H
#define QTK3OPEENRIJSELECTPLAYERWIDGET_H

#include <bitset>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

#include "k3opeenrijnames.h"

#include <QImage>
#include <QWidget>
#pragma GCC diagnostic pop

namespace ribi {
namespace koer {

struct QtK3OpEenRijResources;

class QtK3OpEenRijSelectPlayerWidget : public QWidget
{
  Q_OBJECT
public:
  explicit QtK3OpEenRijSelectPlayerWidget(
    const QtK3OpEenRijResources& resources,
    QWidget *parent = 0
  );
  const std::bitset<3>& GetIsPlayerHuman() const { return m_is_player_human; }
  BlackHairedGirl GetBlack() const noexcept { return m_black; }
  BlondeGirl GetBlond() const noexcept { return m_blond; }
  RedHairedGirl GetRed() const noexcept { return m_red; }

protected:
  void mousePressEvent(QMouseEvent * e);
  void paintEvent(QPaintEvent *);


private:
  BlackHairedGirl m_black;
  BlondeGirl m_blond;
  RedHairedGirl m_red;
  std::bitset<3> m_is_player_human;
  const QImage m_david;
  const QImage m_david_grey;
  const QImage m_hanne;
  const QImage m_hanne_grey;
  const QImage m_josje;
  const QImage m_josje_grey;
  const QImage m_karen;
  const QImage m_karen_grey;
  const QImage m_kathleen;
  const QImage m_kathleen_grey;
  const QImage m_klaasje;
  const QImage m_klaasje_grey;
  const QImage m_kristel;
  const QImage m_kristel_grey;
  const QImage m_marthe;
  const QImage m_marthe_grey;
  const QImage m_matt;
  const QImage m_matt_grey;
  const QImage m_tyler;
  const QImage m_tyler_grey;
  const QImage m_computer1;
  const QImage m_computer2;
  const QImage m_computer3;
  const QImage m_computer_grey;
  static const int m_sprite_height;
  static const int m_sprite_width;

  const QImage& GetImage(const bool is_human,const BlackHairedGirl girl) const noexcept;
  const QImage& GetImage(const bool is_human,const BlondeGirl girl) const noexcept;
  const QImage& GetImage(const bool is_human,const RedHairedGirl girl) const noexcept;
};

} //~namespace koer
} //~namespace ribi

#endif // QTK3OPEENRIJSELECTPLAYERWIDGET_H
