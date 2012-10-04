  sample-qt
=======

A small Qt demo app for Gumstix Overo boards, written to test building 
Qt embedded apps with OpenEmbedded.

The app allows for toggling the red heartbeat LED on the Gumstix expansion 
boards used with the Gumstix 4.3 inch LCD touchscreens.

The following steps can build it manually on a Gumstix image that has
development tools, Qt and a network connection.

        root@overo:~# git clone git://github.com/scottellis/sample-qt.git
        root@overo:~# cd sample-qt
        root@overo:~/sample-qt# qmake
        root@overo:~/sample-qt# make

If you haven't previously calibrated your touchscreen, then run this

        root@overo:~/sample-qt# ts_calibrate

Then to run the sample-qt app

        root@overo:~/sample-qt# ./sample-qt -qws

If you use the jumpnow-qte-image available in the [https://github.com/scottellis/meta-jumpnow](meta-jumpnow)
Yocto meta layer, then the sample-qt app will be built and installed in /usr/bin 
in the resulting root file system.

The recipe can be found in meta-jumpnow/recipes-qt/qt4/sample-qt/


