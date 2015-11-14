#include "k3opeenrijnames.h"

#include <cassert>
#include <stdexcept>

ribi::koer::BlackHairedGirl ribi::koer::GetNext(
  const BlackHairedGirl girl
) noexcept
{
  switch (girl) {
    case BlackHairedGirl::kristel: return BlackHairedGirl::marthe;
    case BlackHairedGirl::marthe: return BlackHairedGirl::kristel;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");
}

ribi::koer::BlondeGirl ribi::koer::GetNext(const BlondeGirl girl) noexcept
{
  switch (girl) {
    case BlondeGirl::kathleen: return BlondeGirl::josje;
    case BlondeGirl::josje: return BlondeGirl::klaasje;
    case BlondeGirl::klaasje: return BlondeGirl::kathleen;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");

}

ribi::koer::RedHairedGirl ribi::koer::GetNext(const RedHairedGirl girl) noexcept
{
  switch (girl) {
    case RedHairedGirl::karen: return RedHairedGirl::hanne;
    case RedHairedGirl::hanne: return RedHairedGirl::karen;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");
}

std::string ribi::koer::ToStr(const BlackHairedGirl girl) noexcept
{
  switch (girl) {
    case BlackHairedGirl::kristel: return "Kristel";
    case BlackHairedGirl::marthe: return "Marthe";
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");
}

std::string ribi::koer::ToStr(const BlondeGirl girl) noexcept
{
  switch (girl) {
    case BlondeGirl::kathleen: return "Kathleen";
    case BlondeGirl::josje: return "Josje";
    case BlondeGirl::klaasje: return "Klaasje";
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");
}

std::string ribi::koer::ToStr(const RedHairedGirl girl) noexcept
{
  switch (girl) {
    case RedHairedGirl::karen: return "Karen";
    case RedHairedGirl::hanne: return "Hanne";
  }
  assert(!"Should not get here");
  throw std::logic_error("Unknown girl");
}

