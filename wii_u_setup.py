#!/usr/bin/env python3

import os

os.system('export PATH="$PATH:/opt/devkitpro/tools/bin" && echo "Adding paths..."')
os.system('export DEVKITPRO=/opt/devkitpro')
os.system('export DEVKITARM=/opt/devkitpro/devkitARM')
os.system('DEVKITPPC=/opt/devkitpro/devkitPPC && echo "Paths added!"')
os.system('echo "Receving key..." && pacman-key --recv BC26F752D25B92CE272E0F44F7FD5492264BB9D0 --keyserver keyserver.ubuntu.com')
os.system('echo "Signing key..." && pacman-key --lsign BC26F752D25B92CE272E0F44F7FD5492264BB9D0')
os.system('pacman -U https://pkg.devkitpro.org/devkitpro-keyring.pkg.tar.xz --noconfirm && echo "Downloading devkit keyring package..."')
os.system('echo "Added devkit libraries to mingw64" && cat <<EOF >> /etc/pacman.conf\n\
[dkp-libs]\n\
Server = https://downloads.devkitpro.org/packages\n\
[dkp-windows]\n\
Server = https://downloads.devkitpro.org/packages/windows\n\
EOF')
os.system('echo "Updating pacman..." && pacman -Syu --noconfirm')
os.system('pacman -S devkitPPC devkitARM cmake --noconfirm')
os.system('echo "Receving key..." && pacman-key --recv-key 6F986ED22C5B9003')
os.system('echo "Signing key..." && pacman-key --lsign 6F986ED22C5B9003')
os.system('echo "Added Wii U Fling to mingw64 (ignore error)" && cat <<EOF >> /etc/pacman.conf\n\
[wiiu-fling]\n\
Server = https://web.archive.org/web/20200705125529/https%3A%2F%2Ffling.heyquark.com%2F\n\
EOF')
os.system('echo "Updating pacman..." && pacman -Syu --noconfirm')
os.system('pacman -S wiiu-sdl2 --noconfirm')
os.system('pacman -S wut-msys2 --noconfirm')
os.system('pacman -S git make python3 mingw-w64-x86_64-gcc --noconfirm')