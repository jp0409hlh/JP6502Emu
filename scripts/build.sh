# This script can be used if you want to compile to Linux and Windows at the same times

set -e 

function buildWindows(){
    if [[ $build_type == "Release" ]] ; then 
        echo "========= Building Windows Binary (Release) ========="
        cmake --build ${build_dir}/Windows-Release

    elif [[ $build_type == "Debug" ]]; then
        echo "========= Building Windows Binary (Debug) ========="
        cmake --build ${build_dir}/Windows-Debug 

    else 
        echo "Argument error : Build type specification error"
        exit 
    fi 
}

function buildLinux(){
    if [[ $build_type == "Release" ]] ; then 
        echo "========= Building Linux Binary (Release) ========="
        cmake --build ${build_dir}/Linux-Release
        
    elif [[ $build_type == "Debug" ]]; then
        echo "========= Building Linux Binary (Debug) ========="
        cmake --build ${build_dir}/Linux-Debug
        
    else 
        echo "Argument error : Build type specification error"
        exit 
    fi 
}

target_OS="$1"
build_type="${2:-"Debug"}"
build_dir="../build"

if [[ $target_OS == "All" ]] ; then
    buildWindows
    buildLinux
elif [[ $target_OS == "Windows" ]] ; then
    buildWindows
elif [[ $target_OS == "Linux" ]] ; then 
    buildLinux 
else 
    echo "Argument error : Target OS name error"
    exit 
fi 

wait 

echo "========= Build Complete ========="

