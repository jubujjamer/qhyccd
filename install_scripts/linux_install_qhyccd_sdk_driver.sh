#!/bin/bash
#####################################################################################################################
# Description : This script installs all the necessary files (libraries, firmwares, udev, include) on Linux machine. 
# Written by  : Jan Soldan (astrosoft@email.cz)
# Version     : 1.02
# Date        : 9/2017
#####################################################################################################################

# install shared libs and links
cp -d ../lib/* /usr/local/lib

# install firmware
mkdir -p /usr/local/lib/qhy/firmware
cp -p ../firmware/* /usr/local/lib/qhy/firmware

# install udev files
cp ../udev/* /etc/udev/rules.d
cp ../udev/* /lib/udev/rules.d

# install fxload with the FX3 support
mkdir -p /usr/share/usb
cp ../fx3load/a3load.hex /usr/share/usb
cp ../fx3load/fxload /sbin
