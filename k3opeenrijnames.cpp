#include "k3opeenrijnames.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

std::vector<ribi::koer::BlackHairedGirl> GetBlackHairedGirls() noexcept
{
  return
  {
    ribi::koer::BlackHairedGirl::kristel,
    ribi::koer::BlackHairedGirl::marthe,
    ribi::koer::BlackHairedGirl::david
  };
}

ribi::koer::BlackHairedGirl ribi::koer::GetNext(
  const BlackHairedGirl girl
) noexcept
{
  switch (girl)
  {
    case BlackHairedGirl::kristel: return BlackHairedGirl::marthe;
    case BlackHairedGirl::marthe: return BlackHairedGirl::david;
    case BlackHairedGirl::david: return BlackHairedGirl::kristel;
  }
  assert(!"Should not get here");
  return BlackHairedGirl::marthe;
}

ribi::koer::BlondeGirl ribi::koer::GetNext(const BlondeGirl girl) noexcept
{
  switch (girl)
  {
    case BlondeGirl::kathleen: return BlondeGirl::josje;
    case BlondeGirl::josje: return BlondeGirl::klaasje;
    case BlondeGirl::klaasje: return BlondeGirl::matt;
    case BlondeGirl::matt: return BlondeGirl::kathleen;
  }
  assert(!"Should not get here");
  return BlondeGirl::josje;

}

ribi::koer::RedHairedGirl ribi::koer::GetNext(const RedHairedGirl girl) noexcept
{
  switch (girl) {
    case RedHairedGirl::karen: return RedHairedGirl::hanne;
    case RedHairedGirl::hanne: return RedHairedGirl::tyler;
    case RedHairedGirl::tyler: return RedHairedGirl::karen;
  }
  assert(!"Should not get here");
  return RedHairedGirl::hanne;
}

std::string ribi::koer::ToStr(const BlackHairedGirl girl) noexcept
{
  switch (girl) {
    case BlackHairedGirl::kristel: return "Kristel";
    case BlackHairedGirl::marthe: return "Marthe";
    case BlackHairedGirl::david: return "David";
  }
  assert(!"Should not get here");
  return "Kristel";
}

std::string ribi::koer::ToStr(const BlondeGirl girl) noexcept
{
  switch (girl) {
    case BlondeGirl::kathleen: return "Kathleen";
    case BlondeGirl::josje: return "Josje";
    case BlondeGirl::klaasje: return "Klaasje";
    case BlondeGirl::matt: return "Matt";
  }
  assert(!"Should not get here");
  return "Kathleen";
}

std::string ribi::koer::ToStr(const RedHairedGirl girl) noexcept
{
  switch (girl) {
    case RedHairedGirl::karen: return "Karen";
    case RedHairedGirl::hanne: return "Hanne";
    case RedHairedGirl::tyler: return "Tyler";
  }
  assert(!"Should not get here");
  return "Karen";
}

std::ostream& ribi::koer::operator<<(std::ostream& os, const BlackHairedGirl g) noexcept
{
  os << ToStr(g);
  return os;
}

std::ostream& ribi::koer::operator<<(std::ostream& os, const BlondeGirl g) noexcept
{
  os << ToStr(g);
  return os;
}

std::ostream& ribi::koer::operator<<(std::ostream& os, const RedHairedGirl g) noexcept
{
  os << ToStr(g);
  return os;
}
