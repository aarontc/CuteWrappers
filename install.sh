#!/bin/bash


cd $(dirname $0)

[[ -d /usr/include/CuteWrappers ]] || sudo mkdir /usr/include/CuteWrappers
[[ -f /usr/include/CuteWrappers/*.h ]] && sudo rm /usr/include/CuteWrappers/*.h

sudo cp *.h /usr/include/CuteWrappers/
sudo cp ../CuteWrappers-build-desktop/*.so* /usr/lib
