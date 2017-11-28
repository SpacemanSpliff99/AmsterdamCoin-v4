
Debian
====================
This directory contains files used to package puffscoind/puffscoin-qt
for Debian-based Linux systems. If you compile puffscoind/puffscoin-qt yourself, there are some useful files here.

## puffscoin: URI support ##


puffscoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install puffscoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your puffscoinqt binary to `/usr/bin`
and the `../../share/pixmaps/puffscoin128.png` to `/usr/share/pixmaps`

puffsoin-qt.protocol (KDE)

