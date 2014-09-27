Silkroad For Linux Patcher
==========================
This is a very simple application that will patch `sro_client.exe` and `silkroad.exe` to work with Wine 1.4.0+ on Linux & OSX. `sro_client.exe` and `silkroad.exe` check for `TransmitFile` which has not been added to Wine yet and so this program will disable that check.

- I believe `TransmitFile` may be used for uploading guild/union emblems and if so, you will crash while attempting to upload them.

- The guides below will assume you already have Wine installed.

- I have decided to rewrite the patcher in Python 3 since that is a lot easier to run instead of needing to install boost.

Installation
============

Debian/Ubuntu
-------------
1. `apt-get install python3 git`

Arch
----
1. `pacman -S git`

Fedora
------
1. `yum install git`

Mac OSX
-------
1. Install homebrew [brew.sh](http://brew.sh)
2. `brew update`
3. `brew install git`

Patching
========
1. Clone this repository with git
2. cd to the cloned repo directory
3. Place silkroad.exe and sro_client.exe in the SilkroadLinux directory
4. `chmod +x SilkroadLinux.py`
5. `./SilkroadLinux.py`
6. Copy silkroad.exe and sro_client.exe back to your Silkroad directory
7. cd to your Silkroad directory
8. `wine silkroad.exe` or run it through your file manager

This will not bypass HackShield and the client will probably crash while loading it.