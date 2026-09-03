# This script can be used if you want to compile to Linux and Windows at the same times

set -e 

function buildWindows(){
    if [[ $build_type == "Release" ]] ; then 
        echo "========= Building Windows Binary (Release) ========="
       

    elif [[ $build_type == "Debug" ]] || [[ -z ${build_type} ]]; then
        echo "========= Building Windows Binary (Debug) ========="
        

    else 
        echo "Argument error : Build type specification error"
        exit 
    fi 
}

function buildLinux(){
    if [[ $build_type == "Release" ]] ; then 
        echo "========= Building Linux Binary (Release) ========="
        
    elif [[ $build_type == "Debug" ]] || [[ -z ${build_type} ]]; then
        echo "========= Building Linux Binary (Debug) ========="
        
    else 
        echo "Argument error : Build type specification error"
        exit 
    fi 
}

target_OS="$1"
build_type="$2"
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

