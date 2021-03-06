PuffsCoin Core
=====================

Setup
---------------------
[PUFFScoin Core](http://puffscoin.ca/wallets) is the desktop PUFFScoin client and it provides the backbone of the blockchain network. However, it downloads and stores the entire history of PuffsCoin transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. Every time you reopen the PUFFScoin client, it will take a few minutes to connect to the PUFFS network and update blocks that have been processed since the last time you opened the client.

Running
---------------------
The following are some helpful notes on how to run PUFFScq1 oin on your native platform.

### Unix

Unpack the files into a directory and run:

- bin/32/puffscoin-qt (GUI, 32-bit) or bin/32/puffscoind (headless, 32-bit)
- bin/64/puffscoin-qt (GUI, 64-bit) or bin/64/puffscoind (headless, 64-bit)

### Windows

Unpack the files into a directory, and then run puffscoin-qt.exe.

### OSX

Drag PuffsCoin-Qt to your applications folder, and then run PuffsCoin-Qt.

### Need Help?

* See the documentation at the [PuffsCoin Wiki](https://) ***TODO***
for help and more information.
* Ask for help on [BitcoinTalk](https://bitcointalk.org/index.php).
* Join our Slack groups [PuffsCoin Slack](https://).

Building
---------------------
The following are developer notes on how to build PuffsCoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The PuffsCoin repo's [root README](https://github.com/https://github.com/SpacemanSpliff99/PUFFSco./blob/master/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/) ***TODO***
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Dnsseed Policy](dnsseed-policy.md)

### Resources

* Discuss on the [BitcoinTalk](***TODO***) or the [PuffsCoin](http://forum.puffscoin.com/) forum.
* Join the [PuffsCoin-Dev](***TODO***) Slack group.

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
