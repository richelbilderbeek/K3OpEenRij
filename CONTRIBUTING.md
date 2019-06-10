# Contributing

Awesome that you are reading this.

This GitHub follows the [Contributor Covenant Code of Conduct](CODE_OF_CONDUCT.md).

 * For questions, you can create an Issue
 * Code changes go via Pull Requests

## Which GitHub repository to contribute to?

K3-Op-Een-Rij is mostly a skin around [ConnectThree](https://github.com/richelbilderbeek/ConnectThree).

If you want to contribute to the game logic,
go to [ConnectThree](https://github.com/richelbilderbeek/ConnectThree/blob/master/CONTRIBUTING.md).

If you want to contribute with the looks of K3-Op-Een-Rij, you are at the right spot :-) 

## Submitting code

Submitted code should follow these quality guidelines:

 * All tests pass cleanly/silently
 * Code coverage must be 100%
 * Coding style should follow the default style by `OCLint`

These are all checked by Travis CI when submitting
a Pull Request. 

Emails with code will not be accepted.

## Submitting bugs

Awesome. These are your options:

 * Add an Issue, with the test that fails
 * Submit a Pull Request, where the test is added to the `tests/testthat` folder
 * Send @richelbilderbeek an email (@richelbilderbeek will make an Issue of it)

Pull Requests should follow the same guidelines as 'Submitting code'.

## Branching policy

 * The `master` branch should always build successfully
 * The `development` branch is for developers

## git usage

To get started working on K3-Op-Een-Rij do:

```
git clone https://github.com/richelbilderbeek/K3OpEenRij
```

Development is done on the `develop` branch. 
To download and checkout the `develop` branch, 
first go into the `K3OpEenRij` folder (`cd K3OpEenRij`), then do:

```
git checkout -b develop origin/develop
```

Then the workflow is the common `git` workflow:

```
git pull
git add --all :/
git commit -m "Did something awesome"
git push
```
