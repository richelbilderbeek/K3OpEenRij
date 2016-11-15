#ifndef K3OPEENRIJNAMES_H
#define K3OPEENRIJNAMES_H

#include <string>

namespace ribi {
namespace koer {

enum class BlackHairedGirl { kristel, marthe, david };
enum class BlondeGirl { kathleen, josje, klaasje, matt };
enum class RedHairedGirl { karen, hanne, tyler };

BlackHairedGirl GetNext(const BlackHairedGirl girl) noexcept;
BlondeGirl GetNext(const BlondeGirl girl) noexcept;
RedHairedGirl GetNext(const RedHairedGirl girl) noexcept;

std::string ToStr(const BlackHairedGirl girl) noexcept;
std::string ToStr(const BlondeGirl girl) noexcept;
std::string ToStr(const RedHairedGirl girl) noexcept;

} //~namespace koer
} //~namespace ribi


#endif // K3OPEENRIJNAMES_H
