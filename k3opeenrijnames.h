#ifndef K3OPEENRIJNAMES_H
#define K3OPEENRIJNAMES_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>

namespace ribi {
namespace koer {

enum class BlackHairedGirl
{
  kristel,
  marthe,
  david
};

std::vector<BlackHairedGirl> GetBlackHairedGirls() noexcept;
enum class BlondeGirl { kathleen, josje, klaasje, matt };
enum class RedHairedGirl { karen, hanne, tyler };

BlackHairedGirl GetNext(const BlackHairedGirl girl) noexcept;
BlondeGirl GetNext(const BlondeGirl girl) noexcept;
RedHairedGirl GetNext(const RedHairedGirl girl) noexcept;

std::string ToStr(const BlackHairedGirl girl) noexcept;
std::string ToStr(const BlondeGirl girl) noexcept;
std::string ToStr(const RedHairedGirl girl) noexcept;

std::ostream& operator<<(std::ostream& os, const BlackHairedGirl g) noexcept;
std::ostream& operator<<(std::ostream& os, const BlondeGirl g) noexcept;
std::ostream& operator<<(std::ostream& os, const RedHairedGirl g) noexcept;

} //~namespace koer
} //~namespace ribi


#endif // K3OPEENRIJNAMES_H
