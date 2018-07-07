# K3-Op-Een-Rij

Branch|[![Travis CI logo](TravisCI.png)](https://travis-ci.org)|[![Codecov logo](Codecov.png)](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/K3OpEenRij.svg?branch=master)](https://travis-ci.org/richelbilderbeek/K3OpEenRij)|[![codecov.io](https://codecov.io/github/richelbilderbeek/K3OpEenRij/coverage.svg?branch=master)](https://codecov.io/github/richelbilderbeek/K3OpEenRij/branch/master)
develop|[![Build Status](https://travis-ci.org/richelbilderbeek/K3OpEenRij.svg?branch=develop)](https://travis-ci.org/richelbilderbeek/K3OpEenRij)|[![codecov.io](https://codecov.io/github/richelbilderbeek/K3OpEenRij/coverage.svg?branch=develop)](https://codecov.io/github/richelbilderbeek/K3OpEenRij/branch/develop)

K3-themed game of connect-three programmed in C++ using Qt and Wt (see 'About the program' for more details).

![K3-Op-Een-Rij game version 8.0](Screenshots/K3OpEenRij_8_0.png)

## Building

On a terminal, do:

```
sudo apt-get install libqt5svg5-dev
git clone https://github.com/richelbilderbeek/K3OpEenRij.git
cd K3OpEenRij
./download_other_githubs.sh
qmake K3OpEenRijDesktop.pro
make
./K3OpEenRijDesktop
```

## Downloads

 * [Download the Windows executable](http://richelbilderbeek.nl/GameK3OpEenRij.zip)

## About the program

K3-Op-Een-Rij is programmed in C++14 using the STL, [Boost](http://www.boost.org), [Qt](http://www.qt.io) (for the desktop version) and [Wt](http://www.webtoolkit.eu/wt) (for the website version) libraries.

K3-Op-Een-Rij is cross-compiled using [MXE](http://mxe.cc) in the bash shell scripts.

## [Contributing](CONTRIBUTING.md)

See [contributing](CONTRIBUTING.md).

## [Screenshots](Screenshots.md)

See [screenshots](Screenshots.md).
