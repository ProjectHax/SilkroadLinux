Silkroad For Linux Patcher
==========================
This is a very simple application that will patch `sro_client.exe` and `silkroad.exe` to work with Wine 1.4.0+ on Linux & OSX. `sro_client.exe` and `silkroad.exe` check for `TransmitFile` which has not been added to Wine yet and so this program will disable that check.

I believe `TransmitFile` may be used for uploading guild/union emblems and if so, you will crash while attempting to upload them.

The guides below will assume you already have Wine installed.

Debian/Ubuntu
-------------
1. `apt-get install build-essential libboost-regex* git-core`
2. Clone this repository with git
3. cd to the cloned repo directory
4. Place silkroad.exe and sro_client.exe in the SilkroadLinux directory
5. `chmod +x compile; ./compile`
6. `./SilkroadLinux`
7. Copy silkroad.exe and sro_client.exe back to your Silkroad directory
8. cd to your Silkroad directory
9. wine silkroad.exe

Arch
----
1. `pacman -S boost`
2. Go to step #2 of the Debian/Ubuntu guide

Mac OSX
-------
1. Install homebrew [brew.sh](http://brew.sh)
2. `brew install boost`
3. Go to step #2 of the Debian/Ubuntu guide