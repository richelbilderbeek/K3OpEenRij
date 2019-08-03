#ifndef QTK3OPEENRIJRESOURCES_H
#define QTK3OPEENRIJRESOURCES_H

#pragma GCC diagnostic push

#include <array>
#include <vector>
#include "connectthreeresources.h"
#include "k3opeenrijnames.h"
#pragma GCC diagnostic pop

namespace ribi {
namespace koer {

///QtK3OpEenRijResources is a class containing
///all filenames to be used by the program
///It ensures the files needed are present upon construction.
struct QtK3OpEenRijResources
{
  QtK3OpEenRijResources();

  const std::string& GetCss() const noexcept { return m_css; }
  const std::string& GetEmptyFilename() const noexcept { return m_empty_filename; }
  const std::vector<std::string>& GetInstructionsGoodFilenames() const noexcept { return  m_instructions_good_filenames; }
  const std::string& GetInstructionsWrongFilename() const noexcept { return m_instructions_wrong_filename; }

  std::vector<std::string> GetPlayerFilenames(
    const BlackHairedGirl black,
    const BlondeGirl blond,
    const RedHairedGirl red
  ) const noexcept;

  std::vector<std::string> GetPlayerGreyFilenames(
    const BlackHairedGirl black,
    const BlondeGirl blond,
    const RedHairedGirl red
  ) const noexcept;

  const std::string& GetIconFilename() const noexcept { return m_icon_filename; }

  const std::string& GetPlayerFilename(const bool is_human, const BlondeGirl girl) const noexcept;
  const std::string& GetPlayerFilename(const bool is_human, const BlackHairedGirl girl) const noexcept;
  const std::string& GetPlayerFilename(const bool is_human, const RedHairedGirl girl) const noexcept;

  const std::vector<std::string>& GetComputerFilenames() const noexcept { return m_computers_filenames; }
  const std::string& GetComputerFilename(const int index) const noexcept;
  const std::string& GetComputerGreyFilename() const noexcept { return m_computer_grey_filename; }

  ///The text displayed at the Quit button
  const std::string& GetQuitText() const noexcept { return m_quit_text; }

  ///The text display at the Winner dialog
  const std::string& GetWinnerText() const noexcept { return m_winner_text; }

  ///Removes all files
  void RemoveFiles() const noexcept;

  private:
  std::vector<std::string> CreatePlayerNames(
    const BlackHairedGirl black,
    const BlondeGirl blond,
    const RedHairedGirl red
  );
  std::vector<std::string> CreatePlayerGreyNames(
    const BlackHairedGirl black,
    const BlondeGirl blond,
    const RedHairedGirl red
  );

  const std::vector<std::string> m_computers_filenames;
  const std::string m_computer_grey_filename;
  const std::string m_css;
  const std::string m_empty_filename;
  const std::string m_icon_filename;
  const std::vector<std::string> m_instructions_good_filenames;
  const std::string m_instructions_wrong_filename;
  const std::array<std::string,10> m_players_filenames;
  const std::array<std::string,10> m_players_grey_filenames;
  const std::string m_quit_text;
  const std::string m_winner_text;


  void Create() const;

  ///Creates a file
  ///Throws std::runtime_error if it cannot be created from resources
  void CreateFile(const std::string& s) const;
};

} //~namespace koer
} //~namespace ribi

#endif // QTK3OPEENRIJRESOURCES_H
