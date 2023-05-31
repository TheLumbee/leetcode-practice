build_debug () {
	if [ ! -d "debug" ]
	then
		mkdir debug
	fi

	cd debug
	cmake -DCMAKE_BUILD_TYPE=Debug ..
	make
	cd ..
}

build_release () {
	if [ ! -d "release" ]
	then
		mkdir release
	fi

	cd release
	cmake -DCMAKE_BUILD_TYPE=Release ..
	make
	cd ..
}

if [ $# -eq 0 ]
then
	build_debug
	build_release
elif [ "$1" == "debug" ]
then
	build_debug
elif [ "$1" == "release" ]
then
	build_release
fi