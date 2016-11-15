#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtk3opeenrijresources.h"

#include <cassert>

#include <QFile>

#include "fileio.h"

#pragma GCC diagnostic pop

ribi::koer::QtK3OpEenRijResources::QtK3OpEenRijResources()
  : m_computers_filenames{
      "K3OpEenRijComputer1.png",
      "K3OpEenRijComputer2.png",
      "K3OpEenRijComputer3.png"
    },
    m_computer_grey_filename{"K3OpEenRijComputerGrey.png"},
    m_css{"K3OpEenRij.css"},
    m_empty_filename{"K3OpEenRijEmpty2.png"},
    m_icon_filename{"K3OpEenRijIcon.png"},
    m_instructions_good_filenames
    {
      "K3OpEenRijInstructions1.png",
      "K3OpEenRijInstructions2.png"
    },
    m_instructions_wrong_filename{"K3OpEenRijInstructions3.png"},
    m_players_filenames{
      "K3OpEenRijKaren.png",     //0
      "K3OpEenRijKristel.png",   //1
      "K3OpEenRijKathleen.png",  //2
      "K3OpEenRijJosje.png",     //3
      "K3OpEenRijHanne.png",     //4
      "K3OpEenRijKlaasje.png",   //5
      "K3OpEenRijMarthe.png"     //6
    },
    m_players_grey_filenames{
      "K3OpEenRijKarenGrey.png",
      "K3OpEenRijKristelGrey.png",
      "K3OpEenRijKathleenGrey.png",
      "K3OpEenRijJosjeGrey.png",
      "K3OpEenRijHanneGrey.png",
      "K3OpEenRijKlaasjeGrey.png",
      "K3OpEenRijMartheGrey.png"
    },
    m_quit_text{"Stoppen"},
    m_winner_text{"Winnaar"}
{
  Create();
}

void ribi::koer::QtK3OpEenRijResources::Create() const
{
  for (const std::string filename: m_computers_filenames) { CreateFile(filename); }
  for (const std::string filename: m_players_filenames) { CreateFile(filename); }
  for (const std::string filename: m_players_grey_filenames) { CreateFile(filename); }
  CreateFile(m_computer_grey_filename);
  CreateFile(m_css);
  CreateFile(m_empty_filename);
  CreateFile(m_icon_filename);
  CreateFile(m_instructions_good_filenames[0]);
  CreateFile(m_instructions_good_filenames[1]);
  CreateFile(m_instructions_wrong_filename);
}

void ribi::koer::QtK3OpEenRijResources::CreateFile(const std::string& s) const
{
  if (!fileio::FileIo().IsRegularFile(s))
  {
    const std::string filename = ":/images/" + s;
    QFile f(filename.c_str());
    f.copy(s.c_str());
    if (!fileio::FileIo().IsRegularFile(s))
    {
      const std::string error = "QtK3OpEenRijResources::CreateFile: file not found: '" + s
        + "\', please add the file to a resource file, or correct the filename";
      throw std::runtime_error(error);
    }
  }
  assert(fileio::FileIo().IsRegularFile(s));
}

const std::string& ribi::koer::QtK3OpEenRijResources::GetPlayerFilename(const bool is_human, const BlondeGirl girl) const noexcept
{
  int index = -1;
  switch (girl) {
    case BlondeGirl::kathleen: index = 2; break;
    case BlondeGirl::josje   : index = 3; break;
    case BlondeGirl::klaasje : index = 5; break;
  }
  assert(index >= 0);
  assert(index < static_cast<int>(m_players_filenames.size()));
  assert(index < static_cast<int>(m_players_grey_filenames.size()));
  return is_human
    ? m_players_filenames[index]
    : m_players_grey_filenames[index]
  ;
}

const std::string& ribi::koer::QtK3OpEenRijResources::GetPlayerFilename(const bool is_human, const BlackHairedGirl girl) const noexcept
{
  int index = -1;
  switch (girl) {
    case BlackHairedGirl::kristel: index = 1; break;
    case BlackHairedGirl::marthe : index = 6; break;
  }
  assert(index >= 0);
  assert(index < static_cast<int>(m_players_filenames.size()));
  assert(index < static_cast<int>(m_players_grey_filenames.size()));
  return is_human
    ? m_players_filenames[index]
    : m_players_grey_filenames[index]
  ;
}

const std::string& ribi::koer::QtK3OpEenRijResources::GetPlayerFilename(const bool is_human, const RedHairedGirl girl) const noexcept
{
  int index = -1;
  switch (girl) {
    case RedHairedGirl::karen: index = 0; break;
    case RedHairedGirl::hanne: index = 4; break;
  }
  assert(index >= 0);
  assert(index < static_cast<int>(m_players_filenames.size()));
  assert(index < static_cast<int>(m_players_grey_filenames.size()));
  return is_human
    ? m_players_filenames[index]
    : m_players_grey_filenames[index]
  ;
}


std::vector<std::string> ribi::koer::QtK3OpEenRijResources::GetPlayerFilenames(
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
) const noexcept
{
  return {
    GetPlayerFilename(true,red),
    GetPlayerFilename(true,black),
    GetPlayerFilename(true,blond)
  };
}

std::vector<std::string> ribi::koer::QtK3OpEenRijResources::GetPlayerGreyFilenames(
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
) const noexcept
{
  return {
    GetPlayerFilename(false,red),
    GetPlayerFilename(false,black),
    GetPlayerFilename(false,blond)
  };
}


const std::string& ribi::koer::QtK3OpEenRijResources::GetComputerFilename(const int index) const noexcept
{
  assert(index >= 0);
  assert(index < static_cast<int>(m_computers_filenames.size()));
  return m_computers_filenames[index];
}

void ribi::koer::QtK3OpEenRijResources::RemoveFiles() const noexcept
{
  for (const std::string filename: m_computers_filenames) { std::remove(filename.c_str()); }
  for (const std::string filename: m_players_filenames) { std::remove(filename.c_str()); }
  for (const std::string filename: m_players_grey_filenames) { std::remove(filename.c_str()); }
  for (const std::string filename: m_instructions_good_filenames) { std::remove(filename.c_str()); }
  std::remove(m_computer_grey_filename.c_str());
  std::remove(m_css.c_str());
  std::remove(m_empty_filename.c_str());
  std::remove(m_icon_filename.c_str());
  std::remove(m_instructions_wrong_filename.c_str());
}

std::vector<std::string> ribi::koer::QtK3OpEenRijResources::CreatePlayerNames(
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
)
{
  std::vector<std::string> v;
  v.push_back("K3OpEenRij" + ToStr(red) + ".png");
  v.push_back("K3OpEenRij" + ToStr(black) + ".png");
  v.push_back("K3OpEenRij" + ToStr(blond) + ".png");
  return v;
}

std::vector<std::string> ribi::koer::QtK3OpEenRijResources::CreatePlayerGreyNames(
  const BlackHairedGirl black,
  const BlondeGirl blond,
  const RedHairedGirl red
)
{
  std::vector<std::string> v;
  v.push_back("K3OpEenRij" + ToStr(red) + "Grey.png");
  v.push_back("K3OpEenRij" + ToStr(black) + "Grey.png");
  v.push_back("K3OpEenRij" + ToStr(blond) + "Grey.png");
  return v;
}
