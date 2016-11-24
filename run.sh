#!/bin/bash

if [ "$1" = "buildonly" ] ; then
    runtest=false
else
	runtest=true
fi

function testLinux {
    if [ $runtest == true ] ; then
		./MainTest
	fi
}
function testWin {
    if [ $runtest == true ] ; then
		./Debug/MainTest.exe
	fi
}

if [ "$(uname)" == "Darwin" ]; then
    # Do something under Mac OS X platform    
    echo "Mac OS X platform"
	echo "not suported"
	exit 1
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Do something under GNU/Linux platform
	echo "GNU/Linux platform"
	mkdir build
	cd build &&
	cmake .. -G "Unix Makefiles" &&
	cmake --build . -- &&
	testLinux
elif [ "$(expr substr $(uname -s) 1 5)" == "MINGW" ]; then
    # Do something under Windows NT platform
	echo "Windows NT platform"
	mkdir build
	cd build &&
	cmake .. -G "Visual Studio 14 2015 Win64" &&
	cmake --build . -- &&
	testWin
fi
