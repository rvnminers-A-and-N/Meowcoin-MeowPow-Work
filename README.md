Meowcoin integration/staging tree
=====================================



What is Meowcoin?
----------------

Meowcoin is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. The Meowcoin platform also lets anyone create assets (tokens) on the Meowcoin network. 
Assets can be used for NFTs, STOs, Gift Cards, and fractional ownership of anything of value.
Meowcoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. 



License
-------

Meow Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/RavenProject/Ravencoin/tags) are created
regularly to indicate new official, stable release versions of Raven Core.

Active development is done in the `develop` branch. 

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer IRC is inactive please join us on discord in #development. https://discord.gg/fndp4NBGct

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

Testnet is up and running and available to use during development.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`


### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.


About Meowcoin
----------------
A digital peer to peer network for the facilitation of value transferf and the well being of cats world wide.







Thank you to the Bitcoin developers. 

The Meowcoin project is launched based on the hard work and continuous effort of over 400 Bitcoin developers who made over 14,000 commits over the life to date of the Bitcoin project. We are eternally grateful to you for your efforts and diligence in making a secure network and for their support of free and open source software development.  The Meowcoin experiment is made on the foundation you built.


Abstract
----------------
Meowcoin aims to implement a blockchain which is optimized specifically for the use case of transferring value from one holder to another. Based on the extensive development and testing of Bitcoin, Meowcoin is built on a fork of the Bitcoin code. Key changes include a faster block reward time and a change in the number, but not weighed distribution schedule, of coins. Meowcoin is free and open source and will be issued and mined transparently with no pre-mine, developer allocation or any other similar set aside. Meowcoin is intended to prioritize user control, privacy and censorship resistance and be jurisdiction agnostic while allowing simple optional additional features for users based on need.



A blockchain is a ledger showing the value of something and allowing it to be transferred to someone else. Of all the possible uses for blockchains, the reporting of who owns what is one of the core uses of the technology.  This is why the first and most successful use case for blockchain technology to date has been Bitcoin.

